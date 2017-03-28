#ifndef _ASSIGNEMENTOPERATIONVARIABLE_H
#define _ASSIGNEMENTOPERATIONVARIABLE_H

#include "AssignmentVariable.h"

class AssignmentOperationVariable : public AssignmentVariable
{
public:
	AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, TOKEN _op);
	virtual ~AssignmentOperationVariable();
	virtual string print() const;

private:
	TOKEN op;
};

#endif