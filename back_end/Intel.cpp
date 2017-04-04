#include "Intel.h"

const int Intel::OFFSET_VALUE = 8;

Intel::Intel(const std::string _filename, std::map<std::string, CFG*> _listCFG)
    : Writer(_filename), listCFG(_listCFG)
{
    open();

    // Begin of the assembler part
    write(".text");
    write(".global main");
    write();
}

void Intel::parse()
{
    std::string label;
    std::vector<IRInstruction*> instructions;

    for (std::map<std::string, CFG*>::iterator itCFG = listCFG.begin(); itCFG != listCFG.end(); ++itCFG)
    {
        const BasicBlock* block = itCFG->second->getRootBasicBlock();

        bool prolog = true;
        while (block != nullptr)
        {
            label = block->getLabel();
            write(label + ":");

            if (prolog) // Prolog
            {
                write("\tpushq %rbp");
                write("\tmovq %rsp, %rbp");

                int offset = itCFG->second->getOffsetFromCurrentBasicBlock() * OFFSET_VALUE;
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
                    IRInstruction::Type instruction = iri->getOperation();

                    switch (instruction)
                    {
                        case IRInstruction::Type::BINARY_OP :
                            binaryOp((IRBinaryOp*) iri);
                            break;
                        case IRInstruction::Type::LOAD_CONSTANT :
                            loadConstant((IRLoadConstant*) iri);
                            break;
                        case IRInstruction::Type::RWMEMORY :
                            rwmemory((IRRWMemory*) iri);
                            break;
                        case IRInstruction::Type::CALL :
                            call((IRCall*) iri);
                            break;
                        case IRInstruction::Type::JUMP :
                            jump((IRJump*) iri);
                            break;
                        case IRInstruction::Type::SELECTION :
                            selection((IRSelection*) iri);
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
        write("\tleave");
        write("\tret");
        write();
    }
}

int Intel::compile()
{
    if (!system(nullptr))
    {
        std::cout << "Erreur : impossible de lancer une commande système [back_end:Intel:compile()]." << std::endl;
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
        std::cout << "Erreur lors de la compilation de l'assembleur [back_end:Intel:compile()]." << std::endl;
        return -1;
    }    

    return 0;
}

void Intel::binaryOp(const IRBinaryOp* instruction)
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
        default:
            std::cout << "Erreur : type d'instruction IRBinaryOp invalide [back_end:Intel:binaryOp()]." << std::endl;
            break;
    }
    write("\tmovq %rax, -" + std::to_string(destination->getOffset() * OFFSET_VALUE) + "(%rbp)");
}

void Intel::loadConstant(const IRLoadConstant* instruction)
{
    write("//loadConstant");

    const Symbol* destination = instruction->getDestination();
    const int value = instruction->getValue();

    write("\tmovq $" + std::to_string(value) + ", -" + std::to_string(destination->getOffset() * OFFSET_VALUE) + "(%rbp)");
}

void Intel::rwmemory(const IRRWMemory* instruction)
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
            std::cout << "Erreur : type d'instruction IRRWMemory invalide [back_end:Intel:rwmemory()]." << std::endl;
            break;
    }
}

void Intel::call(const IRCall* instruction)
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
        std::cout << "Warning : appel de fonction avec plus de 6 paramètres [back_end:Intel:call()]." << std::endl;
    }

    write("\tcall " + instruction->getName());
}

void Intel::jump(const IRJump* instruction)
{
    write("//jump");
    write("\tjmp " + instruction->getLabel());
}

void Intel::selection(const IRSelection* instruction)
{
    write("//selection");
}

Intel::~Intel()
{
    close();
}
