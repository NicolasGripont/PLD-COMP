#include "IRSelection.h"

const std::string IRSelection::LABEL_NULL_NAME = "null";

IRSelection::IRSelection(Symbol* _condition, BasicBlock * bbCondition)
    : IRInstruction(IRInstruction::Type::SELECTION), condition(_condition), blockCondition(bbCondition)
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
    std::string res = "if " + cond + " then " + blockCondition->getExitTrue()->getLabel();
    if(blockCondition->getExitFalse() != nullptr)
    {
        res += " else " + blockCondition->getExitFalse()->getLabel();
    }

    return res;
}

Symbol *IRSelection::getCondition() const
{
    return condition;
}

BasicBlock *IRSelection::getBlockCondition() const
{
    return blockCondition;
}
