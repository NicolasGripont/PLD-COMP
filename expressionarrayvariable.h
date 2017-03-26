#ifndef EXPRESSIONARRAYVARIABLE_H
#define EXPRESSIONARRAYVARIABLE_H
#include <iostream>
#include "expressionvariable.h"

using namespace std;

class ExpressionArrayVariable : public ExpressionVariable {
public:
	ExpressionArrayVariable(string name, Expression* expr);
	virtual ~ExpressionArrayVariable();
	virtual string print() const;
private:
	Expression* expr;
};
#endif