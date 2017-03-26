#include "whileloop.h"

WhileLoop::WhileLoop(Expression* _expr, MultipleStatement *statements) : IterationStatement(statements) {
	this->expr = _expr;
}

WhileLoop::~WhileLoop() {

}

string WhileLoop::print() const {
	return "";
}