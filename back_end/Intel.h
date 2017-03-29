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
    void openFile();

    static const std::string filename;
    std::ofstream* file;
};

#endif