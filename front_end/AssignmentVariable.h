#ifndef _ASSIGNEMENTVARIABLE_H
#define _ASSIGNEMENTVARIABLE_H

#include "ExpressionVariable.h"
#include "Expression.h"

class AssignmentVariable : public Expression
{
public:
	AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr);
	virtual ~AssignmentVariable();
	virtual string toString() const;
protected:
	ExpressionVariable* exprVar;
	Expression* expr;
};

#endif
