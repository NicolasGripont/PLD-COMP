#include "IterationStatement.h"

IterationStatement::IterationStatement(Statement* _statement)
	: SimpleStatement(ITERATION_STATEMENT), statement(_statement)
{

}

string IterationStatement::print() const
{
	return "IterationStatement";
}