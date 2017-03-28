#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(char* _id, bool _array) : id(_id), array(_array), Printer(){

}

DeclarationVariable::~DeclarationVariable()
{

}

char* DeclarationVariable::getId()
{
    return id;
}
bool DeclarationVariable::isArray()
{
    return array;
}

string DeclarationVariable::print() const
{
	return "DeclarationVariable";
}
