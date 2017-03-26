#include "assignmentexpression.h"

AssignmentExpression::AssignmentExpression(ExpressionVariable *exprVar, Expression* expr) : Expression() {
	this->exprVar = exprVar;
	this->expr = expr;
}

AssignmentExpression::~AssignmentExpression() {

}

string AssignmentExpression::print() const {
	return "";
}