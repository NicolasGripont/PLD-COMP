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

string WhileLoop::print() const
{
	string exprStr = "";
	string statementStr = "";
	
	if(expr != nullptr) 
	{
		exprStr = expr->print();
	}
	if(expr != nullptr) 
	{
		statementStr = statement->print();
	}

	return string("While(") + exprStr + string(")") + statementStr;
}