#include "binaryoperatorexpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression*& _exprLeft, Expression*& _exprRight, char inconnu) {
	this->exprLeft = _exprLeft;
	this->exprRight = _exprRight;
}

BinaryOperatorExpression::~BinaryOperatorExpression() {

}

string BinaryOperatorExpression::print() const {
	return "";
}
