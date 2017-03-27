#include "BlockDeclarationVariable.h"

BlockDeclarationVariable::BlockDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
    : SimpleStatement(BLOCK_DECLARATION_VARIABLE), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

MultipleDeclarationVariable* BlockDeclarationVariable::getMultipleDeclarationVariable()
{
    return multipleDeclarationVariable;
}
