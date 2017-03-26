#include "multipledeclarationvariablelocal.h"

MultipleDeclarationVariableLocal::MultipleDeclarationVariableLocal() {

}

MultipleDeclarationVariableLocal::~MultipleDeclarationVariableLocal() {

}

void MultipleDeclarationVariableLocal::addDeclarationVariable(DeclarationVariable *variable) {
	if(variable != NULL) {
		declarations.push_back(variable);
	}
}
	
string MultipleDeclarationVariableLocal::print() const {
	return "";
}
