#include "FunctionCallExpression.h"


FunctionCallExpression::FunctionCallExpression(char* _id, Expression* _expr, int _type)
	: Expression(),id(_id),expr(_expr)
{

    type = _type;
}

FunctionCallExpression::~FunctionCallExpression()
{
    delete expr;
}

string FunctionCallExpression::toString() const
{
	return "FunctionCallExpression";
}
