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
#include "../middle_end/IRRWMemoryArray.h"
#include "../middle_end/IRCall.h"
#include "../middle_end/IRConditionnal.h"
#include "../middle_end/Symbol.h"

/* To execute: ~$ java filename */
/*       e.g.: ~$ java java */
/* --- */
/* Help: */
/* http://web.mit.edu/javadev/packages/jasmin/doc/ */
/* https://cs.au.dk/~mis/dOvs/jvmspec/ref-Java.html */
class Java : public Writer
{
public:
    static const int OFFSET_VALUE;

    Java(const std::string _filename, std::map<std::string, CFG*> _listCFG);
    ~Java();

    void parse();
    int compile();

private:
    std::map<std::string, CFG*> listCFG;

    void parseBasicBlocks(CFG* cfg, const BasicBlock* block, bool prolog = false, int offsetBasicBlock = 0, BasicBlock* terminal = nullptr);

    void binaryOp(const IRBinaryOp* instruction);
    void loadConstant(const IRLoadConstant* instruction);
    void rwmemory(const IRRWMemory* instruction);
    void rwmemoryarray(const IRRWMemoryArray* instruction);
    void call(const IRCall* instruction);
    void selection(CFG* cfg, const IRConditionnal* instruction);
};

#endif
