#include "multipledeclarationvariableglobal.h"

MultipleDeclarationVariableGlobal::MultipleDeclarationVariableGlobal() {

}

MultipleDeclarationVariableGlobal::~MultipleDeclarationVariableGlobal() {

}

void MultipleDeclarationVariableGlobal::addDeclarationVariable(DeclarationVariable *variable) {
	if(variable != NULL) {
		declarations.push_back(variable);
	}
}
	
string MultipleDeclarationVariableGlobal::print() const {
	return "";
}
