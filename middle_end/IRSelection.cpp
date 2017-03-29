#include "IRSelection.h"

const std::string IRSelection::LABEL_NULL_NAME = "null";

IRSelection::IRSelection(BasicBlock* _block, Symbol* _condition, std::string _ifLabel, std::string _elseLabel)
	: IRInstruction(block, IRInstructionType::SELECTION), condition(_condition), ifLabel(_ifLabel), elseLabel(_elseLabel)
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
	std::string res = "if " + cond + " then " + ifLabel;
	if(elseLabel != LABEL_NULL_NAME)
	{
		res += " else " + elseLabel;
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
