#include "ExpressionVariable.h"
#include "../middle_end/CFG.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/IRRWMemory.h"

ExpressionVariable::ExpressionVariable(char * _id, int _type)
    : Expression(), id(_id)
{
    setType(_type);
    setExpressionType(EXPRESSION_VARIABLE);
}

ExpressionVariable::~ExpressionVariable()
{
    if(id != nullptr)
    {
        free(id);
    }
}

std::string ExpressionVariable::toString() const
{
    return std::string(id);
}

void ExpressionVariable::buildIR(CFG *cfg) const
{
    Symbol * resultat = cfg->getCurrentBasicBlock()->getSymbol(id);
    if(resultat == nullptr)
    {
        std::cout << "Error : ExpressionVariable::buildIR " << std::endl;
    }
    else
    {
        IRRWMemory * instruction = new IRRWMemory(IRRWMemory::Type::READ_MEMORY,resultat, resultat);
        cfg->addInstructionInCurrentBasicBlock(instruction);
    }
}

const char *ExpressionVariable::getId() const
{
    return id;
}
