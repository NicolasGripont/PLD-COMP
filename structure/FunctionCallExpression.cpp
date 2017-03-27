#include "FunctionCallExpression.h"


FunctionCallExpression::FunctionCallExpression(char* _id, Expression* _expr, int _type)
	: Expression(),id(_id),expr(_expr)
{

    type = _type;
}
string FunctionCallExpression::print() const
{
	return "FunctionCallExpression";
}
