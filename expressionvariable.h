#ifndef EXPRESSIONVARIABLE_H
#define EXPRESSIONVARIABLE_H
#include <iostream>
#include "expression.h"

using namespace std;

class ExpressionVariable : public Expression {
public:
	ExpressionVariable(string name);
	virtual ~ExpressionVariable();
	virtual string print() const;
private:
	string name;
};
#endif