#include "DeclarationArrayVariable.h"

DeclarationArrayVariable::DeclarationArrayVariable(char* _id, int _size)
	: DeclarationVariable(_id, true, true), size(_size)
{

}

DeclarationArrayVariable::~DeclarationArrayVariable()
{

}

std::string DeclarationArrayVariable::toString() const
{
	if(array) 
	{
		return std::string(id) + "[" + std::string(id) + "]";
	} 
	return "ERROR_DeclarationArrayVariable";
}