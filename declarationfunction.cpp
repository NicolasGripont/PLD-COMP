#include "declarationfunction.h"

DeclarationFunction::DeclarationFunction(TYPE type, string name, MultipleArgument * arguments, MultipleStatement *statements) {
	this->type = type;
	this->name = name;
	this->arguments = arguments;
	this->statements = statements;
}

DeclarationFunction::~DeclarationFunction() {

}

string DeclarationFunction::print() const {
	return "";
}