#include "GlobalDeclarationVariable.h"

GlobalDeclarationVariable::GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	: Declaration(GLOBAL_DECLARATION_VARIABLE), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

GlobalDeclarationVariable::~GlobalDeclarationVariable()
{
    delete multipleDeclarationVariable;
}

string GlobalDeclarationVariable::toString() const
{
	return multipleDeclarationVariable->toString() + string("; ");
}

MultipleDeclarationVariable* GlobalDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
