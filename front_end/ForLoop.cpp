#include "ForLoop.h"

ForLoop::ForLoop(LoopExpression* _expr1, LoopExpression* _expr2, LoopExpression* _expr3, Statement* _statement)
    : IterationStatement(_statement), expr1(_expr1), expr2(_expr2), expr3(_expr3)
{

}

ForLoop::~ForLoop()
{
    delete expr1;
    delete expr2;
    delete expr3;
}

string ForLoop::toString() const
{
	return string("for(") + expr1->toString() + string("; ") + expr2->toString() + string("; ") + expr3->toString() + string(")") + statement->toString();
}
