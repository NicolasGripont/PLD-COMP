#include "DeclarationArrayVariable.h"

DeclarationArrayVariable::DeclarationArrayVariable(char* _id, int _size)
	: DeclarationVariable(_id), size(_size)
{

}

string DeclarationArrayVariable::print() const
{
	return "DeclarationArrayVariable";
}