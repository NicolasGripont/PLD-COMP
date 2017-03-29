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
	return string("while(") + expr->toString() + string(")") + statement->toString();
}