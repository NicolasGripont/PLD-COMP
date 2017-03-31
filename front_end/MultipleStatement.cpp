#include "MultipleStatement.h"

MultipleStatement::MultipleStatement() : Printable()
{

}

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

	for (unsigned int i = 0; i < statements.size(); ++i)
    {
        txt += statements.at(i)->toString();
    }

	return txt;
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
