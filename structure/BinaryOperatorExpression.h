#ifndef _BINARYOPERATOREXPRESSION_H
#define _BINARYOPERATOREXPRESSION_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression
{
public:
	BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op);
	virtual string print() const;

private:
	Expression* expr1;
	Expression* expr2;
	int op;
};

#endif