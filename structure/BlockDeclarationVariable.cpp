#include "BlockDeclarationVariable.h"

BlockDeclarationVariable::BlockDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
    : SimpleStatement(), multipleDeclarationVariable(_multipleDeclarationVariable)
{

}

string BlockDeclarationVariable::print() {
	return "BlockDeclarationVariable";
}