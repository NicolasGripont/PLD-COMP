#include "ifelsestatement.h"

IfElseStatement::IfElseStatement(Expression* expr, MultipleStatement *ifStatement, MultipleStatement *elseStatement) : SelectionStatement(expr, ifStatement) {
	this->elseStatement = elseStatement;
}

IfElseStatement::~IfElseStatement() {

}
	
string IfElseStatement::print() const {
	return "";
}