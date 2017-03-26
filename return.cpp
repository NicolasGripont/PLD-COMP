#include "return.h"

Return::Return(Expression* _expr) : Statement() {
	this->expr = _expr;
}
Return::~Return() {

}

string Return::print() const {
	return "";
}