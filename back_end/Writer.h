#ifndef _WRITER_H
#define _WRITER_H

#include <iostream>
#include <fstream>
#include <string>

class Writer
{
public:
    ~Writer();

protected:
    const std::string filename;

    Writer(const std::string _filename);

    void open(std::ios_base::openmode mode = std::ios::trunc);
    void close();
    void write(const char* line = "");

    bool isOpen();

private:
    std::ofstream* file;
};

#endif