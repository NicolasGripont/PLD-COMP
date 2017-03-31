#include "WhileLoop.h"

WhileLoop::WhileLoop(Expression* _expr, Statement* _statement)
	: IterationStatement(_statement), expr(_expr)
{

}

WhileLoop::~WhileLoop()
{
	if(expr != nullptr) 
	{
		delete expr;
	}
}

std::string WhileLoop::toString() const
{
	std::string txt = "while(" + expr->toString() + ")";
	if(statement != nullptr) 
	{
		txt += statement->toString();
	}
	else 
	{
		txt += "{}";
	}
	return txt;
}