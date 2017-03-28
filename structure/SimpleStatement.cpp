#include "SimpleStatement.h"

SimpleStatement::SimpleStatement(SimpleStatementType _type) : Printable(), type(_type)
{

}

SimpleStatement::~SimpleStatement()
{

}

string SimpleStatement::toString() const
{
	return "SimpleStatement";
}

SimpleStatementType SimpleStatement::getType()
{
    return type;
}
