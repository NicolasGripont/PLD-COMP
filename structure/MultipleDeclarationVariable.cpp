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
    string txt = type->toString();

    if (!declarationsVariables.empty())
    {
        txt += string(" ") + declarationsVariables.at(0)->toString();
    }
    for (unsigned int i = 1; i < declarationsVariables.size(); ++i)
    {
        txt += string(", ") + declarationsVariables.at(i)->toString();
    }

    return txt + string("; ");
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
