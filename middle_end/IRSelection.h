#ifndef IRSELECTION_H
#define IRSELECTION_H

#include <iostream>
#include <string>

#include "IRInstruction.h"
#include "Symbol.h"
#include "BasicBlock.h"

class IRSelection : public IRInstruction
{
public:
    static const std::string LABEL_NULL_NAME;
    IRSelection(Symbol* condition, BasicBlock * bbCondition);
    ~IRSelection();

    virtual std::string toString() const;

    Symbol *getCondition() const;

    BasicBlock *getBlockCondition() const;

protected:
    Symbol *condition;
    BasicBlock * blockCondition;
};

#endif // IRSELECTION_H
