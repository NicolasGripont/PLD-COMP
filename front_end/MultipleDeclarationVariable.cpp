#include "MultipleDeclarationVariable.h"

MultipleDeclarationVariable::MultipleDeclarationVariable() : Printable()
{

};

MultipleDeclarationVariable::~MultipleDeclarationVariable()
{
    if(type != nullptr)
    {
        delete type;
    }
    for (unsigned int i = 0; i < declarationsVariables.size(); ++i)
    {
        if(declarationsVariables[i] != nullptr)
        {
            delete declarationsVariables[i];
        }
    }
}

std::string MultipleDeclarationVariable::toString() const
{
    std::string txt = type->toString();

    if (!declarationsVariables.empty())
    {
        txt += " " + declarationsVariables.at(0)->toString();
    }
    for (unsigned int i = 1; i < declarationsVariables.size(); ++i)
    {
        txt += ", " + declarationsVariables.at(i)->toString();
    }

    return txt ;
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
