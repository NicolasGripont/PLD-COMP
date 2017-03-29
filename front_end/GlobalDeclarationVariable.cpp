#include "GlobalDeclarationVariable.h"

GlobalDeclarationVariable::GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	: Declaration(GLOBAL_DECLARATION_VARIABLE), multipleDeclarationVariable(_multipleDeclarationVariable)
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

MultipleDeclarationVariable* GlobalDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
