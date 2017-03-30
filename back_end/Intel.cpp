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
    std::string line = std::string("movl $'") + character + std::string("', %edi");

    write(("\t" + line).c_str());
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