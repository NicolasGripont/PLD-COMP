#include "declarationvariable.h"

DeclarationVariable::DeclarationVariable(TYPE type, string name) {
	this->type = type;
	this->name = name;
}

DeclarationVariable::~DeclarationVariable() {

}

string DeclarationVariable::print() const {
	return "";
}