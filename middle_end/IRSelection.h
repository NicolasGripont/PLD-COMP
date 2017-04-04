#ifndef IRSELECTION_H
#define IRSELECTION_H

#include <iostream>
#include <string>

#include "IRInstruction.h"
#include "Symbol.h"
#include "BasicBlock.h"

class IRSelection : IRInstruction
{
public:
    static const std::string LABEL_NULL_NAME;
    IRSelection(Symbol* condition, std::string ifLabel, std::string elseLabel = LABEL_NULL_NAME);
    ~IRSelection();

    virtual std::string toString() const;

    Symbol *getCondition() const;
    std::string getIfLabel() const;
    std::string getElseLabel() const;

protected:
    Symbol *condition;
    std::string ifLabel;
	std::string elseLabel;
};

#endif // IRSELECTION_H
