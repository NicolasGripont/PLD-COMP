#include "Writer.h"

Writer::Writer(const std::string _filename)
    : filename(_filename)
{
    file = new std::ofstream();
}

Writer::~Writer()
{
    close();
    delete file;
}

void Writer::open(std::_Ios_Openmode mode)
{
    file->open(filename + ".s", mode);
    if (!file->is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier " << filename << " [back_end:Writer:open()]." << std::endl;
    }
}

void Writer::close()
{
    if (file->is_open())
    {
        file->close();
    }
}

void Writer::write(const char* line)
{
    if (!file->is_open())
    {
        try
        {
            open(std::ios::app);
        }
        catch (const std::exception& e)
        {
            open();
        }
        if (!file->is_open())
        {
            std::cout << "Erreur : impossible d'ouvrir le fichier " << filename << ". Write interrompu [back_end:Writer:write()]." << std::endl;
            return;
        }
    }
    (*file) << line << "\n";
}

bool Writer::isOpen()
{
    return file->is_open();
}