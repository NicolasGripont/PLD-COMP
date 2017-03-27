#include "MultipleStatement.h"

MultipleStatement::MultipleStatement()
{

}

void MultipleStatement::addStatement(SimpleStatement* statement)
{
    statements.push_back(statement);
}