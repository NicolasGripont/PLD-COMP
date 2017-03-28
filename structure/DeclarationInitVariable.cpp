#include "DeclarationInitVariable.h"

DeclarationInitVariable::DeclarationInitVariable(char* _id, Expression* _expr)

	: DeclarationVariable(_id, false), expr(_expr)
{

}

DeclarationInitVariable::~DeclarationInitVariable()
{
    delete expr;
}

string DeclarationInitVariable::print() const
{
	return "DeclarationInitVariable";
}
