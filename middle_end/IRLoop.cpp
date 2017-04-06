#include "IRLoop.h"

IRLoop::IRLoop(Symbol* _condition, BasicBlock * bbCondition, BasicBlock *bbEnd)
    : IRInstruction(IRInstruction::Type::SELECTION), condition(_condition), blockCondition(bbCondition), end(bbEnd)
{

}

IRLoop::~IRLoop()
{
    delete condition;
}

std::string IRLoop::toString() const
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

Symbol *IRLoop::getCondition() const
{
    return condition;
}

BasicBlock *IRLoop::getBlockEnd() const
{
    return end;
}

BasicBlock *IRLoop::getBlockCondition() const
{
    return blockCondition;
}
