#include "Genesis.h"

Genesis::Genesis() : Printable()
{

}

Genesis::~Genesis()
{
    for (unsigned int i = 0; i < declarations.size(); ++i)
    {
        if(declarations[i] != nullptr)
        {
            delete declarations[i];
        }
    }
}

string Genesis::toString() const
{
	string txt = "";


    for (unsigned int i = 0; i < declarations.size(); ++i)
    {
        txt += declarations.at(i)->toString();
    }

    return txt;
}

void Genesis::addDeclaration(Declaration* declaration) 
{
    declarations.push_back(declaration);
}

int Genesis::countDeclaration()
{
    return declarations.size();
}

Declaration*& Genesis::operator[] (int i)
{
    return declarations[i];
}
