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

string Return::toString() const
{
	string txt = "return";

	if(expr != nullptr)
	{
		txt += " " + expr->toString();
	}
	return txt;
}
