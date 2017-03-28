#include "Genesis.h"

Genesis::Genesis() : Printable()
{

}

Genesis::~Genesis()
{

}

string Genesis::toString() const
{
	return "Genesis";
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
