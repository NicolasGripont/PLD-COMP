#ifndef _INTEL_H
#define _INTEL_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Intel
{
public:
    Intel();
    ~Intel();

    int compile();

    void test();

private:
    void open(std::_Ios_Openmode mode = std::ios::trunc);
    void close();
    void write(const char* line = "");

    static const std::string filename;
    std::ofstream* file;
};

#endif