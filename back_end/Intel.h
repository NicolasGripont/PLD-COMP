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
#include "../middle_end/IRBinaryOp.h"
#include "../middle_end/IRLoadConstant.h"
#include "../middle_end/IRRWMemory.h"
#include "../middle_end/IRCall.h"
#include "../middle_end/IRJump.h"
#include "../middle_end/IRSelection.h"
#include "../middle_end/Symbol.h"

class Intel : public Writer
{
public:
    static const int OFFSET_VALUE;

    Intel(const std::string _filename, std::map<std::string, CFG*> _listCFG);
    ~Intel();

    void parse();
    int compile();

    void binaryOp(const IRBinaryOp* instruction);
    void loadConstant(const IRLoadConstant* instruction);
    void rwmemory(const IRRWMemory* instruction);
    void call(const IRCall* instruction);
    void jump(const IRJump* instruction);
    void selection(const IRSelection* instruction);

    void putchar(const char character);

    void test();

private:
    std::map<std::string, CFG*> listCFG;
};

#endif