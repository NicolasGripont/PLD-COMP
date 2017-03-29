#include "IRSelection.h"
 
IRSelection::IRSelection(BasicBlock* _block, Symbol* _condition, std::string _ifLabel, std::string _elseLabel)
	: IRInstruction(block, IR_Operation.SELECTION), condition(_condition), ifLabel(_ifLabel), elseLabel(_elseLabel)
{

}

IRSelection::~IRSelection()
{
	delete condition;
}
    
std::string IRSelection::toString() const
{
    std::string cond = "";
	if(condition != nullptr)
	{
		cond = condition->getName();
	}
	std::string res = "if " + cond + " then " + label1;
	if(labelElse != LABEL_NULL_NAME)
	{
		res += " else " + label2;
	}

    return cond;
}

Symbol *IRSelection::getCondition() const
{
    return condition;
}

std::string IRSelection::getIfLabel() const
{
    return ifLabel;
}

std::string IRSelection::getElseLabel() const
{
    return elseLabel;
}
