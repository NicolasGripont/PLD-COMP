#ifndef _ASSIGNEMENTVARIABLE_H
#define _ASSIGNEMENTVARIABLE_H

#include "ExpressionVariable.h"
#include "Expression.h"

class AssignmentVariable : public Expression
{
public:
	AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr);
	virtual ~AssignmentVariable();

    std::string toString() const;
    void buildIR(CFG* cfg) const;

protected:
	ExpressionVariable* exprVar;
	Expression* expr;
};

#endif
