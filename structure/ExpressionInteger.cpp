#include "ExpressionInteger.h"


ExpressionInteger::ExpressionInteger(int _value, int _type)
	: Expression(), value(_value)
{

    setType(_type);
}

ExpressionInteger::~ExpressionInteger()
{

}

string ExpressionInteger::print() const
{
	return "ExpressionInteger";
}
