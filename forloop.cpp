#include "forloop.h"

ForLoop::ForLoop(Expression* _expr1, Expression* _expr2, Expression* _expr3, MultipleStatement *statements) : IterationStatement(statements) {
	this->expr1 = _expr1;
	this->expr2 = _expr2;
	this->expr3 = _expr3;
}

ForLoop::~ForLoop() {

}

string ForLoop::print() const {
	return "";
}