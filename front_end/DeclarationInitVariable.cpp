#include "DeclarationInitVariable.h"

DeclarationInitVariable::DeclarationInitVariable(char *_id, Expression *_expr)
    : DeclarationVariable(_id, false, false), expr(_expr)
{
}

DeclarationInitVariable::~DeclarationInitVariable()
{
    if (expr != nullptr)
    {
		delete expr;
    }
}

std::string DeclarationInitVariable::toString() const
{
    if (!array)
    {
		return std::string(id) + " = " + expr->toString();
    }
    return "ERROR_DeclarationInitVariable";
}

Expression *DeclarationInitVariable::getExpr()
{
    return expr;
}