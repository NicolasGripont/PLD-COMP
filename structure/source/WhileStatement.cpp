#include "../header/WhileStatement.h"
#include <iostream>

WhileStatement::WhileStatement(Expression *expr, Statement *state) : expression(expr), statement(state)
{
    std::cout<<"WhileStatement - Constructor"<<std::endl;
}

WhileStatement::~WhileStatement()
{
    delete expression;
    delete statement;
}
