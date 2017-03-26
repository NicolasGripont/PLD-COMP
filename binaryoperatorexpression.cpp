#include "binaryoperatorexpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _exprLeft, Expression* _exprRight) {
	this->exprLeft = _exprLeft;
	this->exprRight = _exprRight;
}

BinaryOperatorExpression::~BinaryOperatorExpression() {

}