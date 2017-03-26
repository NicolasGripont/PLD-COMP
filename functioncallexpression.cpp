#include "functioncallexpression.h"

FunctionCallExpression::FunctionCallExpression(string _id, Expression* _expr) : Expression() {
	this->id = _id;
	this->expr = _expr;
}

FunctionCallExpression::~FunctionCallExpression() {

}
	
string FunctionCallExpression::print() const {
	return "";
}