#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(char* _id) : Printer(), id(_id)
{

}

char* DeclarationVariable::getId()
{
    return id;
}

string DeclarationVariable::print() const
{
	return "DeclarationVariable";
}