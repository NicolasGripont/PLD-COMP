#ifndef IRSELECTION_H
#define IRSELECTION_H

#include "IRInstruction.h"
#include "Symbol.h"
#include "BasicBlock.h"

#include <iostream>

class IRSelection : IRInstruction
{
public:
    static const std::string LABEL_NULL_NAME = "null";
    IRSelection(BasicBlock* block, Symbol* condition, std::string ifLabel, std::string elseLabel = LABEL_NULL_NAME);
    ~IRSelection();

    std::string toString() const; 

    Symbol *getCondition() const;
    std::string getIfLabel() const;
    std::string getElseLabel() const;

protected:
    Symbol *condition;
    std::string ifLabel;
	std::string elseLabel;
};

#endif // IRSELECTION_H
