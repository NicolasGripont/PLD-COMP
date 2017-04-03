#ifndef _ASSIGNEMENTOPERATIONVARIABLE_H
#define _ASSIGNEMENTOPERATIONVARIABLE_H

#include "AssignmentVariable.h"

class AssignmentOperationVariable : public AssignmentVariable
{
public:
	AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op);
	virtual ~AssignmentOperationVariable();

    virtual std::string toString() const;
    void buildIR(CFG* cfg) const;

private:
	int op;
};

#endif
