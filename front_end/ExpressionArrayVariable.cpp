#include "ExpressionArrayVariable.h"

ExpressionArrayVariable::ExpressionArrayVariable(char* _id, Expression* _expr, int _type)
    :ExpressionVariable(_id,_type), expr(_expr)
{
    setExpressionType(EXPRESSION_ARRAY_VARIABLE);
}

ExpressionArrayVariable::~ExpressionArrayVariable()
{
	if(id != nullptr)
	{
		free(id);
	}
	if(expr != nullptr)
	{
		delete expr;
	}
}

std::string ExpressionArrayVariable::toString() const
{
    return std::string(id) + "[" + expr->toString() + "]";
}

Expression *ExpressionArrayVariable::getExpr() const
{
    return expr;
}

