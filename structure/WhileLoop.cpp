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
	string exprStr = "";
	string statementStr = "";
	
	if(expr != nullptr) 
	{
		exprStr = expr->toString();
	}
	if(expr != nullptr) 
	{
		statementStr = statement->toString();
	}

	return string("While(") + exprStr + string(")") + statementStr;
}