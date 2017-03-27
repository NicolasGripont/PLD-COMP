#include "MultipleDeclarationVariable.h"

MultipleDeclarationVariable::MultipleDeclarationVariable() : Printer()
{

};

void MultipleDeclarationVariable::addDeclarationVariable(DeclarationVariable* dec)
{
    declarationsVariables.push_back(dec);
}

void MultipleDeclarationVariable::setType(Type* t)
{
    type = t;
}

int MultipleDeclarationVariable::countDeclaration()
{
    return declarationsVariables.size();
}

DeclarationVariable*& MultipleDeclarationVariable::operator[] (int i)
{
    return declarationsVariables[i];
}

string MultipleDeclarationVariable::print() {
	return "MultipleDeclarationVariable";
}