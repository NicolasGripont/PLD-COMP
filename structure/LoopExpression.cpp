#include "LoopExpression.h"

LoopExpression::LoopExpression(Expression* _expr)
    : Printable(), expr(_expr)
{

}

LoopExpression::~LoopExpression()
{

}

string LoopExpression::toString() const
{
	return "LoopExpression";
}