#include "UselessStatement.h"

UselessStatement::UselessStatement()
    : SimpleStatement(USELESS_STATEMENT)
{

}

UselessStatement::~UselessStatement()
{

}

std::string UselessStatement::toString() const
{
    return "; ";
}

void UselessStatement::buildIR(CFG *cfg) const
{}

