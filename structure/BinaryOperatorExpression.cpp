#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op)
	: Expression(), expr1(_expr1), expr2(_expr1), op(_op)
{

}

string BinaryOperatorExpression::print() {
	return "BinaryOperatorExpression";
}