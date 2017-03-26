#include "expressionarrayvariable.h"

ExpressionArrayVariable::ExpressionArrayVariable(string name, Expression* expr) : ExpressionVariable(name) {
	this->expr = expr;
}
	
ExpressionArrayVariable::~ExpressionArrayVariable() {

}
	
string ExpressionArrayVariable::print() const {
	return "";
}