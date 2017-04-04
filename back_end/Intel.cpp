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
    std::vector<const IRInstruction*> instructions;

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

                int offset = block->getPrologMaximalOffset() * OFFSET_VALUE;
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
            }
            else if (block->getExitFalse() != nullptr)
            {
                block = block->getExitFalse();
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
    write("\t// binaryOp");

    const Symbol* destination = instruction->getDestination();
    const Symbol* operand1 = instruction->getOperand_1();
    const Symbol* operand2 = instruction->getOperand_2();

    switch (instruction->getType())
    {
        case IRBinaryOp::Type::ADD :
            break;
        case IRBinaryOp::Type::SUB :
            break;
        case IRBinaryOp::Type::MUL :
            break;
        case IRBinaryOp::Type::DIV :
            break;
        default:
            std::cout << "Erreur : type d'instruction IRBinaryOp invalide [back_end:Intel:binaryOp()]." << std::endl;
            break;
    }
}

void Intel::loadConstant(const IRLoadConstant* instruction)
{
    write("\t// loadConstant");

    const Symbol* destination = instruction->getDestination();
    const int value = instruction->getValue();

    write("\tmovq $" + std::to_string(value) + ", -" + std::to_string(destination->getOffset() * OFFSET_VALUE) + "(%rbp)");
}

void Intel::rwmemory(const IRRWMemory* instruction)
{
    write("\t// rwmemory");

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
    write("\t// call");

    // Pour le moment que putchar (voir 5.3)

    std::vector<const Symbol*> params = instruction->getParams();

    write("\tmovl -" + std::to_string(params.at(0)->getOffset() * OFFSET_VALUE) + "(%rbp), %edi");
    write("\tcall putchar");

}

void Intel::jump(const IRJump* instruction)
{
    write("\t// jump");
}

void Intel::selection(const IRSelection* instruction)
{
    write("\t// selection");
}

void Intel::putchar(const char character)
{
    std::string finalCharacter;
    switch (character)
    {
        case '\n':
            finalCharacter = "\\n";
            break;
        case '\t':
            finalCharacter = "\\t";
            break;
        default:
            finalCharacter = character;
            break;
    }
    write(("\tmovl $'" + finalCharacter + "', %edi").c_str());
    write("\tcall putchar");
}

void Intel::test()
{
    putchar('I');
    putchar('N');
    putchar('T');
    putchar('E');
    putchar('L');
    putchar('\n');

    write();
    write("\tretq");
}

Intel::~Intel()
{
    close();
}
