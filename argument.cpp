#include "argument.h"

Argument::Argument(TYPE type, string name, bool isArray) {
	this->type = type;
	this->name = name;
	this->isArray = isArray;
}

Argument::~Argument() {

}

string Argument::print() const {
	return "";
}