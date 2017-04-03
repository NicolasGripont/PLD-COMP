#include "ExpressionVariable.h"

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

}

const char *ExpressionVariable::getId() const
{
    return id;
}
