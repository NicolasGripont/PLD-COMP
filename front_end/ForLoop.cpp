#include "ForLoop.h"

ForLoop::ForLoop(LoopExpression* _expr1, LoopExpression* _expr2, LoopExpression* _expr3, Statement* _statement)
    : IterationStatement(_statement), expr1(_expr1), expr2(_expr2), expr3(_expr3)
{

}

ForLoop::~ForLoop()
{
	if(expr1 != nullptr)
	{
		delete expr1;
	}
	if(expr2 != nullptr)
	{
		delete expr2;
	}
	if(expr3 != nullptr)
	{
		delete expr3;
	}
}

std::string ForLoop::toString() const
{
	std::string txt = "for(" + expr1->toString() + "; " + expr2->toString() + "; " + expr3->toString() + ")";
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
