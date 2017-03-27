#include "BlockDeclarationVariable.h"

BlockDeclarationVariable::BlockDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
    : SimpleStatement(BLOCK_DECLARATION_VARIABLE), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

string BlockDeclarationVariable::print() {
	return "BlockDeclarationVariable";
}

MultipleDeclarationVariable* BlockDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
