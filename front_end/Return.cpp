#include "Return.h"

Return::Return(Expression* _expr)
    : Printable(), expr(_expr)
{

}

Return::~Return()
{
	if(expr != nullptr) 
	{
		delete expr;
	}  
}

std::string Return::toString() const
{
	std::string txt = "return";

	if(expr != nullptr)
	{
		txt += " " + expr->toString();
	}
	return txt;
}
