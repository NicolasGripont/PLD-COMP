#ifndef BINARYOPERATOREXPRESSION_H
#define BINARYOPERATOREXPRESSION_H
#include <iostream>
#include "expression.h"

using namespace std;

class BinaryOperatorExpression : public Expression {
private:
	Expression* exprLeft;
	Expression* exprRight;
public:
	BinaryOperatorExpression(Expression* _exprLeft, Expression* _exprRight);
	virtual ~BinaryOperatorExpression();
	virtual string print() const = 0;
};
#endif