#include "LoopExpression.h"

LoopExpression::LoopExpression(Expression* _expr)
    : Printable(), expr(_expr)
{

}

LoopExpression::~LoopExpression()
{
	if(expr != nullptr)
	{
		delete expr;
	}
}

std::string LoopExpression::toString() const
{
	std::string txt = "";
	if(expr != nullptr) 
	{
		txt = expr->toString();
	}
    return txt;
}

void LoopExpression::buildIR(CFG *cfg) const
{
    if(expr != nullptr)
    {
        expr->buildIR(cfg);
    }
}
