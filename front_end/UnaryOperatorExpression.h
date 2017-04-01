#ifndef _UNARYOPERATOREXPRESSION_H
#define _UNARYOPERATOREXPRESSION_H

#include "Expression.h"

class UnaryOperatorExpression : public Expression 
{
public:
	UnaryOperatorExpression(Expression* _expr, int _op);
	virtual ~UnaryOperatorExpression();

    std::string toString() const;
    void buildIR(CFG * cfg) const;
	
private:
	Expression* expr;
	int op;
};

#endif
