#include "LoopExpression.h"

LoopExpression::LoopExpression(Expression* _expr)
    : Printer(), expr(_expr)
{

}

LoopExpression::~LoopExpression()
{

}

string LoopExpression::print() const
{
	return "LoopExpression";
}