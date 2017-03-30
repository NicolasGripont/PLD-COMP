#ifndef _INTEL_H
#define _INTEL_H

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Writer.h"

class Intel : public Writer
{
public:
    Intel(const std::string _filename);
    ~Intel();

    int compile();

    void putchar(const char character);
    void call();
    void ifThenElse();

    void test();
};

#endif