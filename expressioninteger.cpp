#include "expressioninteger.h"

ExpressionInteger::ExpressionInteger(int value) : Expression() {
	this->value = value;
}

ExpressionInteger::~ExpressionInteger() {

}
	
string ExpressionInteger::print() const {
	return "";
}