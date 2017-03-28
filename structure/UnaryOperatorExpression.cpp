#include "UnaryOperatorExpression.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr, int _op)
	:Expression(),expr(_expr),op(_op)
{

    type = _expr->getType();
}

UnaryOperatorExpression::~UnaryOperatorExpression()
{

}

string UnaryOperatorExpression::print() const
{
	return "UnaryOperatorExpression";
}
