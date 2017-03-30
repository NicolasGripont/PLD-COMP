#include "Intel.h"

const std::string Intel::filename = "intel";

Intel::Intel()
{
    file = new std::ofstream();

    open();

    // Begin of the assembler part
    write(".text");
    write(".global main");
    write();
    write("main:");
}

void Intel::open(std::_Ios_Openmode mode)
{
    file->open(filename + ".s", mode);
    if (!file->is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier " << filename << " [back_end:Intel:Intel()]." << std::endl;
    }
}

void Intel::close()
{
    if (file->is_open())
    {
        file->close();
    }
}

void Intel::write(const char* line)
{
    (*file) << line << "\n";
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

    if (!file->is_open())
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

void Intel::test()
{
    write("\tmovl $'I', %edi");
    write("\tcall putchar");
    write("\tmovl $'N', %edi");
    write("\tcall putchar");
    write("\tmovl $'T', %edi");
    write("\tcall putchar");
    write("\tmovl $'E', %edi");
    write("\tcall putchar");
    write("\tmovl $'L', %edi");
    write("\tcall putchar");
    write("\tmovl $'\\n', %edi");
    write("\tcall putchar");

    write();
    write("\tretq");
}

Intel::~Intel()
{
    close();
    delete file;
}