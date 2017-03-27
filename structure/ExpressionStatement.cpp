#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(Expression* _expr)
    : SimpleStatement(EXPRESSION_STATEMENT), expr(_expr)
{

}

string ExpressionStatement::print() const
{
	return "ExpressionStatement";
}
