#include "GlobalDeclarationVariable.h"

GlobalDeclarationVariable::GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	: Declaration(), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

GlobalDeclarationVariable::~GlobalDeclarationVariable()
{

}

string GlobalDeclarationVariable::toString() const
{
	return "GlobalDeclarationVariable";
}