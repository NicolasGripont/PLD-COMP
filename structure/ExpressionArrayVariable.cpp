#include "ExpressionArrayVariable.h"


ExpressionArrayVariable::ExpressionArrayVariable(char* _id, Expression* _expr, int _type)
	:ExpressionVariable(_type),id(_id),expr(_expr)
{

}

ExpressionArrayVariable::~ExpressionArrayVariable()
{

}

string ExpressionArrayVariable::print() const
{
	return "ExpressionArrayVariable";
}