#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(char* _id, bool _array) : id(_id), array(_array), Printable(){

}

DeclarationVariable::~DeclarationVariable()
{
    delete id;
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
	return "DeclarationVariable";
}
