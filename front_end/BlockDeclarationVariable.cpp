#include "BlockDeclarationVariable.h"
#include "../middle_end/CFG.h"

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

void BlockDeclarationVariable::buildIR(CFG *cfg) const
{

}

MultipleDeclarationVariable* BlockDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
