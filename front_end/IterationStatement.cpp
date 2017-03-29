#include "IterationStatement.h"

IterationStatement::IterationStatement(Statement* _statement)
	: SimpleStatement(ITERATION_STATEMENT), statement(_statement)
{

}

IterationStatement::~IterationStatement()
{
    delete statement;
}
