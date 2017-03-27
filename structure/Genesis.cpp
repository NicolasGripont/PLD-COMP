#include "Genesis.h"

Genesis::Genesis() : Printer()
{

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

string Genesis::print() {
	return "Genesis";
}