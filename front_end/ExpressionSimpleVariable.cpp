#include "ExpressionSimpleVariable.h"

ExpressionSimpleVariable::ExpressionSimpleVariable(char* _id, int _type)
    : ExpressionVariable(_type), id(_id)
{
    setExpressionType(EXPRESSION_SIMPLE_VARIABLE);
}

ExpressionSimpleVariable::~ExpressionSimpleVariable()
{
	if(id != nullptr)
	{
		free(id);
	}
}

std::string ExpressionSimpleVariable::toString() const
{
	return std::string(id);
}
