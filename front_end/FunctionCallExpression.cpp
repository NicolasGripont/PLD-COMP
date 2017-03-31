#include "FunctionCallExpression.h"

FunctionCallExpression::FunctionCallExpression(char* _id, Expression* _expr, int _type)
	: Expression(), id(_id), expr(_expr)
{

    type = _type;
}

FunctionCallExpression::~FunctionCallExpression()
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

std::string FunctionCallExpression::toString() const
{
	
	std::string exprStr = "";
	if(expr != nullptr) 
	{
		exprStr = expr->toString();
	}
	return std::string(id) + "(" + exprStr + ")";
}
