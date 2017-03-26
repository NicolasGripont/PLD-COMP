#ifndef ASSIGNMENTEXPRESSION_H
#define ASSIGNMENTEXPRESSION_H
#include <iostream>
#include "expressionvariable.h"
#include "expression.h"

using namespace std;

class AssignmentExpression : public Expression {
public:
	AssignmentExpression(ExpressionVariable *exprVar, Expression* expr);
	virtual ~AssignmentExpression();
	virtual string print() const;
private:
	ExpressionVariable *exprVar;
	Expression* expr;
};
#endif