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

/* To execute: ~$ ./filename.out */
/*       e.g.: ~$ ./x64.out */
class x64 : public Writer
{
public:
    x64(const std::string _filename, std::map<std::string, CFG*> _listCFG);
    ~x64();

    void parse();
    int compile();

private:
    static const int OFFSET_VALUE;

    std::map<std::string, CFG*> listCFG;

    void binaryOp(const IRBinaryOp* instruction);
    void loadConstant(const IRLoadConstant* instruction);
    void rwmemory(const IRRWMemory* instruction);
    void call(const IRCall* instruction);
    void jump(const IRJump* instruction);
    void selection(const IRSelection* instruction);
};

#endif