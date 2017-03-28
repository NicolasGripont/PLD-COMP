#include "UnaryOperatorExpression.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr, int _op)
	:Expression(),expr(_expr),op(_op)
{

    type = _expr->getType();
}

UnaryOperatorExpression::~UnaryOperatorExpression()
{
	if(expr != nullptr) {
		delete expr;
	}
}

string UnaryOperatorExpression::print() const
{
	string exprStr = "";
	char opStr = (char) op;

	if(expr != nullptr) {
		exprStr = expr->print();
	}

	return opStr + exprStr;
}
