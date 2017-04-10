#include "Expression.h"

Expression::Expression()
	: Printable(), type(EXPRESSION_TYPE_UNDEFINED), expressionType(EXPRESSION)
{

}

int Expression::getType() const
{
    return type;
}

void Expression::setType(int _type)
{
    type = _type;
}

ExpressionType Expression::getExpressionType()
{
    return expressionType;
}

void Expression::setExpressionType(ExpressionType _type)
{
    expressionType = _type;
}
