#include "GlobalDeclarationVariable.h"

GlobalDeclarationVariable::GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	: Declaration(), multipleDeclarationVariable(_multipleDeclarationVariable)
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
