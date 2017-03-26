#ifndef BINARYOPERATOREXPRESSION_H
#define BINARYOPERATOREXPRESSION_H

#include <iostream>

#include "expression.h"

using namespace std;

class BinaryOperatorExpression : public Expression
{

public:
	BinaryOperatorExpression(Expression*& _exprLeft, Expression*& _exprRight, char inconnu);
	virtual ~BinaryOperatorExpression();
	virtual string print() const;
private:
	Expression* exprLeft;
	Expression* exprRight;
};
#endif
