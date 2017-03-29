#include "WhileLoop.h"

WhileLoop::WhileLoop(Expression* _expr, Statement* _statement)
	: IterationStatement(_statement), expr(_expr)
{

}

WhileLoop::~WhileLoop()
{
	if(this->expr != nullptr) 
	{
		delete this->expr;
	}
}

string WhileLoop::toString() const
{
	string txt = "while(" + expr->toString() + ")";
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