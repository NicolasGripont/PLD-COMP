#ifndef _JAVA_H
#define _JAVA_H

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

/* To execute: ~$ java filename */
/*       e.g.: ~$ java java */
class Java : public Writer
{
public:
    static const int OFFSET_VALUE;

    Java(const std::string _filename, std::map<std::string, CFG*> _listCFG);
    ~Java();

    void parse();
    int compile();

    void binaryOp(const IRBinaryOp* instruction);
    void loadConstant(const IRLoadConstant* instruction);
    void rwmemory(const IRRWMemory* instruction);
    void call(const IRCall* instruction);
    void jump(const IRJump* instruction);
    void selection(const IRSelection* instruction);

private:
    std::map<std::string, CFG*> listCFG;
};

#endif