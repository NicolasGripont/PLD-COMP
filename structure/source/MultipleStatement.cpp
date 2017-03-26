#include "../header/MultipleStatement.h"
#include <iostream>

MultipleStatement::MultipleStatement()
{
    std::cout<<"MultipleStatement - Constructor"<<std::endl;
}

MultipleStatement::~MultipleStatement()
{
    for (auto statement : listStatements)
    {
        delete statement;
    }
}

void MultipleStatement::addStatement(Statement * state)
{
    listStatements.push_back(state);
}
