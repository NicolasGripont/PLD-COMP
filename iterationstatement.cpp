#include "iterationstatement.h"

IterationStatement::IterationStatement(MultipleStatement *statements) : Statement() {
	this->statements = statements;
}

IterationStatement::~IterationStatement() {

}