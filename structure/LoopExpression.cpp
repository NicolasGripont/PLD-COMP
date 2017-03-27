#include "LoopExpression.h"

LoopExpression::LoopExpression(Expression* _expr)
    : Printer(), expr(_expr)
{

}

string LoopExpression::print() {
	return "LoopExpression";
}