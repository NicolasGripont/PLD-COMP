#include "MultipleStatement.h"

MultipleStatement::MultipleStatement() : Printer()
{

}

void MultipleStatement::addStatement(SimpleStatement* statement)
{
    statements.push_back(statement);
}

string MultipleStatement::print() {
	return "MultipleStatement";
}