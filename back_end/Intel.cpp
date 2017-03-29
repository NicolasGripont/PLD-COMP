#include "Intel.h"

const std::string Intel::filename = "intel";

Intel::Intel()
{
    file = new std::ofstream();

    openFile();

    // Begin of the assembler part
    (*file) << ".text\n";
    (*file) << ".global main\n\n";
    (*file) << "main:\n";
}

void Intel::openFile()
{
    file->open(filename + ".s", std::ios::trunc);

    if (!file->is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier " << filename << " [back_end:Intel:Intel()]." << std::endl;
    }
}

int Intel::compile()
{
    if (!system(nullptr))
    {
        std::cout << "Erreur : impossible de lancer une commande système [back_end:Intel:compile()]." << std::endl;
        return -1;
    }
    if (file->is_open())
    {
        file->close();
    }

    int result = 0;
    result = system(("as -o " + filename + ".o " + filename + ".s").c_str());
    result = system(("gcc -o " + filename + " " + filename + ".o ").c_str());

    if (!file->is_open())
    {
        openFile();
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
    (*file) << "\tmovl $'I', %edi\n";
    (*file) << "\tcall putchar\n";
    (*file) << "\tmovl $'N', %edi\n";
    (*file) << "\tcall putchar\n";
    (*file) << "\tmovl $'T', %edi\n";
    (*file) << "\tcall putchar\n";
    (*file) << "\tmovl $'E', %edi\n";
    (*file) << "\tcall putchar\n";
    (*file) << "\tmovl $'L', %edi\n";
    (*file) << "\tcall putchar\n";
    (*file) << "\tmovl $'\n', %edi\n";
    (*file) << "\tcall putchar\n";

    (*file) << "\n\tretq\n\n";
}

Intel::~Intel()
{
    if (file->is_open())
    {
        file->close();
    }
    delete file;
}