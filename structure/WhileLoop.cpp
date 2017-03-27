#include "WhileLoop.h"

WhileLoop::WhileLoop(Expression* _expr, Statement* _statement)
	: IterationStatement(_statement), expr(_expr)
{

}

string WhileLoop::print() const
{
	return "WhileLoop";
}