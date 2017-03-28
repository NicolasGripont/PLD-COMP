#include "MultipleDeclarationVariable.h"

MultipleDeclarationVariable::MultipleDeclarationVariable() : Printable()
{

};

MultipleDeclarationVariable::~MultipleDeclarationVariable()
{

}

string MultipleDeclarationVariable::toString() const
{
    return "MultipleDeclarationVariable";
}

void MultipleDeclarationVariable::addDeclarationVariable(DeclarationVariable* dec)
{
    declarationsVariables.push_back(dec);
}

void MultipleDeclarationVariable::setType(Type* t)
{
    type = t;
}

Type* MultipleDeclarationVariable::getType()
{
    return type;
}

int MultipleDeclarationVariable::countDeclaration()
{
    return declarationsVariables.size();
}

DeclarationVariable*& MultipleDeclarationVariable::operator[] (int i)
{
    return declarationsVariables[i];
}
