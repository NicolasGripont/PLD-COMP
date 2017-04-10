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

std::string GlobalDeclarationVariable::toString() const
{
    return multipleDeclarationVariable->toString() + "; ";
}

void GlobalDeclarationVariable::buildIR(CFG *cfg) const
{

}

MultipleDeclarationVariable* GlobalDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
