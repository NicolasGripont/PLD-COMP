#include "MultipleDeclarationVariable.h"

MultipleDeclarationVariable::MultipleDeclarationVariable() : Printable()
{

};

MultipleDeclarationVariable::~MultipleDeclarationVariable()
{
    delete type;
    for (unsigned int i = 0; i < declarationsVariables.size(); ++i)
    {
        delete declarationsVariables[i];
    }
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
