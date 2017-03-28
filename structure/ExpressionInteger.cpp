#include "ExpressionInteger.h"


ExpressionInteger::ExpressionInteger(int _value, int _type)
	: Expression(), value(_value)
{
    setType(_type);
    setExpressionType(EXPRESSION_INTEGER);
}

ExpressionInteger::~ExpressionInteger()
{

}

string ExpressionInteger::toString() const
{
	return "ExpressionInteger";
}
