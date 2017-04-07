#include "IRConditionnal.h"

IRConditionnal::IRConditionnal(Type _type, Symbol* _condition, BasicBlock * bbCondition, BasicBlock *bbEnd)
    : IRInstruction(IRInstruction::Operation::CONDITIONNAL), type(_type),
      condition(_condition), blockCondition(bbCondition), end(bbEnd)
{

}

IRConditionnal::~IRConditionnal()
{
    delete condition;
}

std::string IRConditionnal::toString() const
{
    std::string cond = "";
    std::string res = "";

    if(condition != nullptr)
    {
        cond = condition->getName();
    }

    switch(type)
    {
    case Type::SELECTION :

        res = "IF " + cond + " then " + blockCondition->getExitTrue()->getLabel();
        if(blockCondition->getExitFalse() != nullptr)
        {
            res += " else " + blockCondition->getExitFalse()->getLabel();
        }
        break;
    case Type::FOR :
        res = "FOR " + cond + " then " + blockCondition->getExitTrue()->getLabel();
        break;
    case Type::WHILE :
        res = "WHILE " + cond + " then " + blockCondition->getExitTrue()->getLabel();
        break;
    }

    return res;
}

Symbol *IRConditionnal::getCondition() const
{
    return condition;
}

BasicBlock *IRConditionnal::getBlockEnd() const
{
    return end;
}

BasicBlock *IRConditionnal::getBlockCondition() const
{
    return blockCondition;
}

const IRConditionnal::Type IRConditionnal::getType() const
{
    return type;
}