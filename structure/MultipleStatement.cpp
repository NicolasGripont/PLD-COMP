#include "MultipleStatement.h"

MultipleStatement::MultipleStatement() : Printable()
{

}

MultipleStatement::~MultipleStatement()
{

}

string MultipleStatement::toString() const
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
