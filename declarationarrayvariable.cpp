#include "declarationarrayvariable.h"

DeclarationArrayVariable::DeclarationArrayVariable(TYPE _type, string _id, int _size) : DeclarationVariable(_type, _id) {
	this->size = _size;
}

DeclarationArrayVariable::~DeclarationArrayVariable() {

}

string DeclarationArrayVariable::print() const {
	return "";
}