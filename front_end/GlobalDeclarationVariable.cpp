#include "GlobalDeclarationVariable.h"

GlobalDeclarationVariable::GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	: Declaration(), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

GlobalDeclarationVariable::~GlobalDeclarationVariable()
{
	if(multipleDeclarationVariable != nullptr)
	{
		delete multipleDeclarationVariable;
	}
}

string GlobalDeclarationVariable::toString() const
{
	return multipleDeclarationVariable->toString() + "; ";
}
