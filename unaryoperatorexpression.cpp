#include "unaryoperatorexpression.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr) {
	this->expr = _expr;
}

UnaryOperatorExpression::~UnaryOperatorExpression() {

}