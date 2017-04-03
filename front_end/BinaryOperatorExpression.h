#ifndef _BINARYOPERATOREXPRESSION_H
#define _BINARYOPERATOREXPRESSION_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression
{
public:
	BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op);
    BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op, int _type);
    virtual ~BinaryOperatorExpression();

    virtual std::string toString() const;
    void buildIR(CFG* cfg) const;

private:
	Expression* expr1;
	Expression* expr2;
	int op;
};
#endif
