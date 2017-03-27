#include "AssignmentOperationVariable.h"

AssignmentOperationVariable::AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op)
	:AssignmentVariable(_exprVar,_expr),op(_op)
{

}