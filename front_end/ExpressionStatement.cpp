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

std::string ExpressionStatement::toString() const
{
    return expr->toString() + "; ";
}

void ExpressionStatement::buildIR(CFG *cfg) const
{

}
