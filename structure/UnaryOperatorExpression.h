#ifndef _UNARYOPERATOREXPRESSION_H
#define _UNARYOPERATOREXPRESSION_H

#include "Expression.h"

class UnaryOperatorExpression : public Expression 
{
public:
	UnaryOperatorExpression(Expression* _expr, int _op);

private:
	Expression* expr;
	int op;
};

#endif