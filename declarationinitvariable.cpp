#include "declarationinitvariable.h"

DeclarationInitVariable::DeclarationInitVariable(TYPE _type, string _id, Expression* _expr) : DeclarationVariable(_type, _id) {
	this->expr = _expr;
}

DeclarationInitVariable::~DeclarationInitVariable() {
	delete expr;
}

string DeclarationInitVariable::print() const {
	return "";
}