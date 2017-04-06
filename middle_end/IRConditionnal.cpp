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

        res = "if " + cond + " then " + blockCondition->getExitTrue()->getLabel();
        if(blockCondition->getExitFalse() != nullptr)
        {
            res += " else " + blockCondition->getExitFalse()->getLabel();
        }
        return res;
        break;
    case Type::FOR :

        break;
    case Type::WHILE :

        break;
    }


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
