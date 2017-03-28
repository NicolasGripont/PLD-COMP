#include "MultipleStatement.h"

MultipleStatement::MultipleStatement() : Printer()
{

}

MultipleStatement::~MultipleStatement()
{

}

string MultipleStatement::print() const
{
	return "MultipleStatement";
}

void MultipleStatement::addStatement(SimpleStatement* statement)
{
    statements.push_back(statement);
}

int MultipleStatement::countStatements()
{
    return statements.size();
}

SimpleStatement*& MultipleStatement::operator[] (int i)
{
    return statements[i];
}
