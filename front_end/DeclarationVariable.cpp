#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(char* _id, bool _array)
	: Printable(), id(_id), array(_array)
{

}

DeclarationVariable::~DeclarationVariable()
{
	if(id != nullptr)
	{
		delete id;
	}
}

char* DeclarationVariable::getId()
{
    return id;
}
bool DeclarationVariable::isArray()
{
    return array;
}

string DeclarationVariable::toString() const
{
	if(!array) 
	{
		return string(id);
	} 
	return "ERROR_DeclarationVariable";
}
