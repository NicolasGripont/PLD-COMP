#include "UselessStatement.h"

UselessStatement::UselessStatement()
    : SimpleStatement(USELESS_STATEMENT)
{

}

UselessStatement::~UselessStatement()
{

}

string UselessStatement::toString() const
{
	return "; ";
}

