#include "X64.h"

const int X64::OFFSET_VALUE = 8;

X64::X64(const std::string _filename, std::map<std::string, CFG*> _listCFG)
    : Writer(_filename), listCFG(_listCFG)
{
    open();

    // Begin of the assembler part
    write(".text");
    write(".global main");
    write();
}

void X64::parse()
{
    for (std::map<std::string, CFG*>::iterator itCFG = listCFG.begin(); itCFG != listCFG.end(); ++itCFG)
    {
        const BasicBlock* block = itCFG->second->getRootBasicBlock();

        parseBasicBlocks(block, true, itCFG->second->getOffsetFromCurrentBasicBlock(), nullptr);

        write("\tleave");
        write("\tret");
        write();
    }
}

int X64::compile()
{
    if (!system(nullptr))
    {
        std::cout << "Erreur : impossible de lancer une commande système [back_end:X64:compile()]." << std::endl;
        return -1;
    }
    close();

    int result = 0;
    result = system(("as -o " + filename + ".o " + filename + ".s").c_str());
    result = system(("gcc -static -o " + filename + ".out " + filename + ".o").c_str());

    if (isOpen())
    {
        open(std::ios::app);
    }

    if (result != 0)
    {
        std::cout << "Erreur lors de la compilation de l'assembleur [back_end:X64:compile()]." << std::endl;
        return -1;
    }    

    return 0;
}

void X64::parseBasicBlocks(const BasicBlock* block, bool prolog, int offsetBasicBlock, BasicBlock* terminal)
{
    std::string label;
    std::vector<IRInstruction*> instructions;

    while (block != terminal)
    {
        label = block->getLabel();
        write(label + ":");

        if (prolog) // Prolog
        {
            write("\tpushq %rbp");
            write("\tmovq %rsp, %rbp");

            int offset = offsetBasicBlock * OFFSET_VALUE;
            if (offset%OFFSET_VALUE != 0) // Next multiple OFFSET_VALUE
            {
                offset += (OFFSET_VALUE - (offset%OFFSET_VALUE));
            }
            write("\tsubq $" + std::to_string(offset) + ", %rsp");

            prolog = false;
        }
        else // Other
        {
            instructions = block->getInstructions();
            for (const IRInstruction* iri : instructions)
            {
                IRInstruction::Operation instruction = iri->getOperation();

                switch (instruction)
                {
                    case IRInstruction::Operation::BINARY_OP :
                        binaryOp((IRBinaryOp*) iri);
                        break;
                    case IRInstruction::Operation::LOAD_CONSTANT :
                        loadConstant((IRLoadConstant*) iri);
                        break;
                    case IRInstruction::Operation::RWMEMORY :
                        rwmemory((IRRWMemory*) iri);
                        break;
                    case IRInstruction::Operation::CALL :
                        call((IRCall*) iri);
                        break;
                    case IRInstruction::Operation::CONDITIONNAL :
                        selection((IRConditionnal*) iri);
                        break;
                    default:
                        break;
                }
            }
        }

        if (block->getExitTrue() != nullptr)
        {
            block = block->getExitTrue();
            write("\tjmp " + block->getLabel());
        }
        else if (block->getExitFalse() != nullptr)
        {
            block = block->getExitFalse();
            write("\tjmp " + block->getLabel());
        }
        else
        {
            block = nullptr;
        }
    }
}

void X64::binaryOp(const IRBinaryOp* instruction)
{
    write("//binaryOp");

    const Symbol* destination = instruction->getDestination();
    const Symbol* operand1 = instruction->getOperand_1();
    const Symbol* operand2 = instruction->getOperand_2();

    write("\tmovq -" + std::to_string(operand1->getOffset() * OFFSET_VALUE) + "(%rbp), %rax");
    write("\tmovq -" + std::to_string(operand2->getOffset() * OFFSET_VALUE) + "(%rbp), %rbx");

    switch (instruction->getType())
    {
        case IRBinaryOp::Type::ADD :
            write("\taddq %rbx, %rax");
            break;
        case IRBinaryOp::Type::SUB :
            write("\tsubq %rbx, %rax");
            break;
        case IRBinaryOp::Type::MUL :
            write("\timulq %rbx, %rax");
            break;
        case IRBinaryOp::Type::DIV :
            break;
        case IRBinaryOp::Type::MOD :
            break;
        case IRBinaryOp::Type::EQUAL_EQUAL :
            write("\tcmp %rbx, %rax");
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmove %rax, %rbx");
            write("\tmovq %rbx, %rax");
            break;
        case IRBinaryOp::Type::DIFF :
            write("\tcmp %rbx, %rax");
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovne %rax, %rbx");
            write("\tmovq %rbx, %rax");
            break;
        case IRBinaryOp::Type::LESS_THAN :
            write("\tcmp %rbx, %rax");
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovl %rax, %rbx");
            write("\tmovq %rbx, %rax");
            break;
        case IRBinaryOp::Type::LESS_THAN_OR_EQUAL :
            write("\tcmp %rbx, %rax");
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovle %rax, %rbx");
            write("\tmovq %rbx, %rax");
            break;
        case IRBinaryOp::Type::MORE_THAN :
            write("\tcmp %rbx, %rax");
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovg %rax, %rbx");
            write("\tmovq %rbx, %rax");
            break;
        case IRBinaryOp::Type::MORE_THAN_OR_EQUAL :
            write("\tcmp %rbx, %rax");
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovge %rax, %rbx");
            write("\tmovq %rbx, %rax");
            break;
        case IRBinaryOp::Type::AND_AND :
            break;
        case IRBinaryOp::Type::OR_OR :
            break;
        case IRBinaryOp::Type::OR :
            break;
        case IRBinaryOp::Type::AND :
            break;
        case IRBinaryOp::Type::LEFT_DEC :
            break;
        case IRBinaryOp::Type::RIGHT_DEC :
            break;
        case IRBinaryOp::Type::POW :
            break;
        default:
            std::cout << "Erreur : type d'instruction IRBinaryOp invalide [back_end:X64:binaryOp()]." << std::endl;
            break;
    }
    write("\tmovq %rax, -" + std::to_string(destination->getOffset() * OFFSET_VALUE) + "(%rbp)");
}

void X64::loadConstant(const IRLoadConstant* instruction)
{
    write("//loadConstant");

    const Symbol* destination = instruction->getDestination();
    const int value = instruction->getValue();

    write("\tmovq $" + std::to_string(value) + ", -" + std::to_string(destination->getOffset() * OFFSET_VALUE) + "(%rbp)");
}

void X64::rwmemory(const IRRWMemory* instruction)
{
    write("//rwmemory");

    const Symbol* destination = instruction->getDestination();
    const Symbol* source = instruction->getSource();

    switch (instruction->getType())
    {
        case IRRWMemory::Type::READ_MEMORY :
            break;
        case IRRWMemory::Type::WRITE_MEMORY :
            write("\tmovq -" + std::to_string(source->getOffset() * OFFSET_VALUE) + "(%rbp), %rax");
            write("\tmovq %rax, -" + std::to_string(destination->getOffset() * OFFSET_VALUE) + "(%rbp)");
            break;
        default:
            std::cout << "Erreur : type d'instruction IRRWMemory invalide [back_end:X64:rwmemory()]." << std::endl;
            break;
    }
}

void X64::call(const IRCall* instruction)
{
    write("//call");

    std::vector<Symbol*> params = instruction->getParams();

    // 6 parameters. 64 bits.
    if (params.size() > 0)
    {
        write("\tmovq -" + std::to_string(params.at(0)->getOffset() * OFFSET_VALUE) + "(%rbp), %rdi");
    }
    if (params.size() > 1)
    {
        write("\tmovq -" + std::to_string(params.at(1)->getOffset() * OFFSET_VALUE) + "(%rbp), %rsi");
    }
    if (params.size() > 2)
    {
        write("\tmovq -" + std::to_string(params.at(2)->getOffset() * OFFSET_VALUE) + "(%rbp), %rdx");
    }
    if (params.size() > 3)
    {
        write("\tmovq -" + std::to_string(params.at(3)->getOffset() * OFFSET_VALUE) + "(%rbp), %rcx");
    }
    if (params.size() > 4)
    {
        write("\tmovq -" + std::to_string(params.at(4)->getOffset() * OFFSET_VALUE) + "(%rbp), %r8");
    }
    if (params.size() > 5)
    {
        write("\tmovq -" + std::to_string(params.at(5)->getOffset() * OFFSET_VALUE) + "(%rbp), %r9");
    }
    if (params.size() > 6)
    {
        std::cout << "Warning : appel de fonction avec plus de 6 paramètres [back_end:X64:call()]." << std::endl;
    }

    write("\tcall " + instruction->getName());

    if (!instruction->getIsReturnVoid())
    {
        write("\tmovq %rax, -" + std::to_string(instruction->getReturnSymbol()->getOffset() * OFFSET_VALUE) + "(%rbp)");
    }
}

void X64::selection(const IRConditionnal *instruction)
{
    write("//selection");

    // True/False -> condition

    const Symbol* condition = instruction->getCondition();
    const BasicBlock* blockCondition = instruction->getBlockCondition();

    write("\tmovq -" + std::to_string(condition->getOffset() * OFFSET_VALUE) + "(%rbp), %rax");
    write("\tcmpq $0, %rax");
    write("\tje " + blockCondition->getExitTrue()->getLabel()); // Jump Then

    //write -> Else
    if (blockCondition->getExitFalse() != nullptr)
    {
        write("\tjmp " + blockCondition->getExitFalse()->getLabel());

        BasicBlock* block = blockCondition->getExitFalse();
        BasicBlock* blockEnd = instruction->getBlockEnd();
        
        parseBasicBlocks(block, false, 0, blockEnd);
    }
}

X64::~X64()
{
    close();
}
