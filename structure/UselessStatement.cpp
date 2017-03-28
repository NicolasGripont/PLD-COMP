#include "UselessStatement.h"

UselessStatement::UselessStatement()
    : SimpleStatement(USELESS_STATEMENT)
{

}

UselessStatement::~UselessStatement()
{

}

string UselessStatement::print() const
{
	return ";";
}

