#ifndef FUNCTIONCALLEXPRESSION_H
#define FUNCTIONCALLEXPRESSION_H
#include <iostream>
#include "expression.h"

using namespace std;

class FunctionCallExpression : public Expression {
private:
	string id;
	Expression* expr;
public:
	FunctionCallExpression(string _id, Expression* _expr);
	virtual ~FunctionCallExpression();
	virtual string print() const;
};
#endif