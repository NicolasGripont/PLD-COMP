#include "UnaryOperatorExpression.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr, int _op)
	: Expression(), expr(_expr), op(_op)
{

}

string UnaryOperatorExpression::print() {
	return "UnaryOperatorExpression";
}