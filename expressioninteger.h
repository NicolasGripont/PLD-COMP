#ifndef EXPRESSIONINTEGER_H
#define EXPRESSIONINTEGER_H
#include <iostream>
#include "expression.h"

using namespace std;

class ExpressionInteger : public Expression {
private:
	int value;
public:
	ExpressionInteger(int value);
	virtual ~ExpressionInteger();
	virtual string print() const;
};
#endif