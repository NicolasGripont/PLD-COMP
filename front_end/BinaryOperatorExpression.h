#ifndef _BINARYOPERATOREXPRESSION_H
#define _BINARYOPERATOREXPRESSION_H

#include "Expression.h"

class BinaryOperatorExpression : public Expression
{
public:
    BinaryOperatorExpression(Expression* _left, Expression* _right, int _op);
    BinaryOperatorExpression(Expression* _left, Expression* _right, int _op, int _type);
    virtual ~BinaryOperatorExpression();

    virtual std::string toString() const;
    void buildIR(CFG* cfg) const;

    Expression *getLeft() const;
    Expression *getRight() const;

private:
    Expression* left;
    Expression* right;
	int op;
};
#endif
