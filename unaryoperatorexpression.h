#ifndef UNARYOPERATOREXPRESSION_H
#define UNARYOPERATOREXPRESSION_H
#include <iostream>
#include "expression.h"

using namespace std;

class UnaryOperatorExpression : public Expression {
private:
	Expression* expr;
public:
	UnaryOperatorExpression(Expression* _expr);
	virtual ~UnaryOperatorExpression();
	virtual string print() const = 0;
};
#endif