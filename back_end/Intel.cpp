#include "Intel.h"

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

                int offset = block->getPrologMaximalOffset();
                if (offset%32 != 0) // Next multiple 32
                {
                    offset += (32 - (offset%32));
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
                            binaryOp();
                            break;
                        case IRInstruction::Type::RWMEMORY :
                            rwmemory();
                            break;
                        case IRInstruction::Type::CALL :
                            call();
                            break;
                        case IRInstruction::Type::JUMP :
                            jump();
                            break;
                        case IRInstruction::Type::SELECTION :
                            selection();
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
    result = system(("gcc -o " + filename + ".out " + filename + ".o ").c_str());

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

void Intel::binaryOp()
{

}

void Intel::rwmemory()
{

}

void Intel::call()
{

}

void Intel::jump()
{

}

void Intel::selection()
{

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
