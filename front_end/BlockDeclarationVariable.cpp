#include "BlockDeclarationVariable.h"

BlockDeclarationVariable::BlockDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
    : SimpleStatement(BLOCK_DECLARATION_VARIABLE), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

BlockDeclarationVariable::~BlockDeclarationVariable()
{
	if(multipleDeclarationVariable != nullptr) 
    {
        delete multipleDeclarationVariable;
    }
}

std::string BlockDeclarationVariable::toString() const
{
	return multipleDeclarationVariable->toString() + "; ";
}

MultipleDeclarationVariable* BlockDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
