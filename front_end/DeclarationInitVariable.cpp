#include "DeclarationInitVariable.h"

DeclarationInitVariable::DeclarationInitVariable(char* _id, Expression* _expr)
	: DeclarationVariable(_id, false), expr(_expr)
{

}

DeclarationInitVariable::~DeclarationInitVariable()
{
    delete expr;
}

string DeclarationInitVariable::toString() const
{
	if(!array) 
	{
		return string(id) + string(" = ") + expr->toString();
	} 
	return "ERROR_DeclarationInitVariable";
}
