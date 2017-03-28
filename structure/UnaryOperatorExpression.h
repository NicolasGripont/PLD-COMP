#ifndef _UNARYOPERATOREXPRESSION_H
#define _UNARYOPERATOREXPRESSION_H

#include "Expression.h"

class UnaryOperatorExpression : public Expression 
{
public:
	UnaryOperatorExpression(Expression* _expr, int _op);
	virtual ~UnaryOperatorExpression();
	virtual string toString() const;
	
private:
	Expression* expr;
	int op;
};

#endif