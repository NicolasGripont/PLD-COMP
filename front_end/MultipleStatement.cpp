#include "MultipleStatement.h"

#include "../middle_end/CFG.h"

MultipleStatement::MultipleStatement()
{}

MultipleStatement::~MultipleStatement()
{
    for (unsigned int i = 0; i < statements.size(); ++i)
    {
        if(statements[i] != nullptr) 
        {
            delete statements[i];
        }
    }
}

std::string MultipleStatement::toString() const
{
	std::string txt = "";

    for(SimpleStatement * state : statements)
    {
        txt += state->toString();
    }

    return txt;
}

void MultipleStatement::buildIR(CFG *cfg) const
{
    for(SimpleStatement * state : statements)
    {
        state->buildIR(cfg);
    }
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

const std::vector<SimpleStatement *> &MultipleStatement::getStatements()
{
    return statements;
}
