#include "Intel.h"

Intel::Intel(const std::string _filename)
    : Writer(_filename)
{
    open();

    // Begin of the assembler part
    write(".text");
    write(".global main");
    write();
    write("main:");
}

void Intel::parse(CFG* _cfg)
{
    cfg = _cfg;

    std::string label;
    std::vector<IRInstruction*> instructions;

    std::vector<BasicBlock*> basicBlocks = cfg->getBasicBlocks();
    for (std::vector<BasicBlock*>::iterator block = basicBlocks.begin() ; block != basicBlocks.end(); ++block)
    {
        label = (*block)->getLabel();
        write(label);

        instructions = (*block)->getInstructions();
        for (std::vector<IRInstruction*>::iterator iri = instructions.begin() ; iri != instructions.end(); ++iri)
        {
            IRInstruction::IRInstructionType instruction = (*iri)->getOperation();

            switch (instruction)
            {
                case IRInstruction::IRInstructionType::BINARY_OP:
                    break;
                case IRInstruction::IRInstructionType::RWMEMORY:
                    break;
                case IRInstruction::IRInstructionType::CALL:
                    break;
                case IRInstruction::IRInstructionType::JUMP:
                    break;
                case IRInstruction::IRInstructionType::SELECTION:
                    break;
                default:
                    break;
            }
        }

        instructions.clear();
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

void Intel::call()
{

}

void Intel::ifThenElse()
{

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