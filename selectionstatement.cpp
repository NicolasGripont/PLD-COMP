#include "selectionstatement.h"

SelectionStatement::SelectionStatement(Expression* expr, MultipleStatement *statements) : Statement() {
	this->expr = expr;
	this->statements = statements;
}

SelectionStatement::~SelectionStatement() {

}