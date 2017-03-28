#include "SimpleStatement.h"

SimpleStatement::SimpleStatement(SimpleStatementType _type) : Printable(), type(_type)
{

}

SimpleStatement::~SimpleStatement()
{

}

SimpleStatementType SimpleStatement::getType()
{
    return type;
}
