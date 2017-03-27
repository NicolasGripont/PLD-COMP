#include "SimpleStatement.h"

SimpleStatement::SimpleStatement(SimpleStatementType _type) : Printer(), type(_type)
{

}

string SimpleStatement::print() const
{
	return "SimpleStatement";
}

SimpleStatementType SimpleStatement::getType()
{
    return type;
}
