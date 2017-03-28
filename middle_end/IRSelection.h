#ifndef IRSELECTION_H
#define IRSELECTION_H
#include <iostream>
#include "IRInsctruction.h"

class IRSelection : IRInsctruction
{
public:
	static const string LABEL_NULL_NAME = "null";
    IRSelection(BasicBlock* block, Symbol* condition, string ifLabel, string elseLabel = LABEL_NULL_NAME);
    ~IRSelection();
    std::string toString() const;

protected:
	Symbol *condition;
	string ifLabel;
	string elseLabel;
};

#endif // IRSELECTION_H
