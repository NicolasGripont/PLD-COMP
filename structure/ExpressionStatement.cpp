#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(Expression* _expr)
    : SimpleStatement(EXPRESSION_STATEMENT), expr(_expr)
{

}

ExpressionStatement::~ExpressionStatement()
{

}

string ExpressionStatement::print() const
{
	return "ExpressionStatement";
}
