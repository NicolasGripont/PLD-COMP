#ifndef _IRCONDITIONNAL_H
#define _IRCONDITIONNAL_H

#include "IRInstruction.h"
#include "Symbol.h"
#include "BasicBlock.h"

#include <iostream>
#include <string>

class IRConditionnal : public IRInstruction
{
public:

    enum class Type
    {
        SELECTION,
        FOR,
        WHILE
    };

    IRConditionnal(Type _type, Symbol* _condition, BasicBlock * bbCondition, BasicBlock *bbEnd);
    ~IRConditionnal();

    std::string toString() const;

    Symbol *getCondition() const;
    BasicBlock *getBlockCondition() const;
    BasicBlock *getBlockEnd() const;

protected:
    Type type;

    Symbol *condition;
    BasicBlock * blockCondition;
    BasicBlock * end;
};

#endif // IRCONDITIONNAL_H
