#include "expressionvariable.h"

ExpressionVariable::ExpressionVariable(string name) : Expression() {
	this->name = name;
}
	
ExpressionVariable::~ExpressionVariable() {

}
	
string ExpressionVariable::print() const {
	return "";
}