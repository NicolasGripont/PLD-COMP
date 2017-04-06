#ifndef IRLOOP_H
#define IRLOOP_H

#include <iostream>
#include <string>

#include "IRInstruction.h"
#include "Symbol.h"
#include "BasicBlock.h"

class IRLoop : public IRInstruction
{
public:
    IRLoop(Symbol* _condition, BasicBlock * bbCondition, BasicBlock *bbEnd);
    ~IRLoop();
    virtual std::string toString() const;
    Symbol *getCondition() const;
    BasicBlock *getBlockCondition() const;
    BasicBlock *getBlockEnd() const;

protected:
    Symbol *condition;
    BasicBlock * blockCondition;
    BasicBlock * end;
};

#endif // IRLOOP_H
