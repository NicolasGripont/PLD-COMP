#include "Expression.h"

Expression::Expression()
	: Printable(), type(EXPRESSION_TYPE_UNDEFINED), expressionType(EXPRESSION)
{

}

Expression::~Expression()
{

}

int Expression::getType()
{
    return type;
}

void Expression::setType(int _type)
{
    type = _type;
}

int Expression::getExpressionType()
{
    return expressionType;
}

void Expression::setExpressionType(int _type)
{
    expressionType = _type;
}
