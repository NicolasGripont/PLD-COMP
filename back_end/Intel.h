#ifndef _INTEL_H
#define _INTEL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

#include "Writer.h"
#include "../middle_end/CFG.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/IRInstruction.h"

class Intel : public Writer
{
public:
    Intel(const std::string _filename, std::map<std::string, CFG*> _listCFG);
    ~Intel();

    void parse();
    int compile();

    void binaryOp();
    void rwmemory();
    void call();
    void jump();
    void selection();

    void putchar(const char character);

    void test();

private:
    std::map<std::string, CFG*> listCFG;
};

#endif