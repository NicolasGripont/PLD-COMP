#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(Expression* _expr)
    : SimpleStatement(EXPRESSION_STATEMENT), expr(_expr)
{

}

ExpressionStatement::~ExpressionStatement()
{
	if(expr != nullptr)
	{
		delete expr;
	}
}

string ExpressionStatement::toString() const
{
	return expr->toString() + "; ";
}