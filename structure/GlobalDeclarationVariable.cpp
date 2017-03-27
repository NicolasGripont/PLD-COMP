#include "GlobalDeclarationVariable.h"

GlobalDeclarationVariable::GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	: Declaration(), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

string GlobalDeclarationVariable::print() const
{
	return "GlobalDeclarationVariable";
}