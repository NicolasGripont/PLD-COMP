#include "AssignmentVariable.h"

AssignmentVariable::AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr)
	:Expression(),exprVar(_exprVar),expr(_expr)
{

}