#include "ExpressionArrayVariable.h"


ExpressionArrayVariable::ExpressionArrayVariable(char* _id, Expression* _expr, int _type)
	:ExpressionVariable(_type),id(_id),expr(_expr)
{
    setExpressionType(EXPRESSION_ARRAY_VARIABLE);
}

ExpressionArrayVariable::~ExpressionArrayVariable()
{
    delete id;
    delete expr;
}

string ExpressionArrayVariable::print() const
{
	return "ExpressionArrayVariable";
}
