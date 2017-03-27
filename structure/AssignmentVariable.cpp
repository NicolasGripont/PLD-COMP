#include "AssignmentVariable.h"

AssignmentVariable::AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr)
	:Expression(),exprVar(_exprVar),expr(_expr)
{

    if(_exprVar->getType() == _expr->getType())
    {
        setType(_expr->getType());
    }
    else
    {
        setType(EXPRESSION_TYPE_CONFLICT);
    }
}

string AssignmentVariable::print() const
{
	return "AssignmentVariable";
}
