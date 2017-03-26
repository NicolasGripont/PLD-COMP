#include "../header/MultipleExpression.h"
#include <iostream>

MultipleExpression::MultipleExpression()
{
    std::cout<<"MultipleExpression - Constructor"<<std::endl;
}

MultipleExpression::~MultipleExpression()
{
    for(auto expr : listExpressions)
    {
        delete expr;
    }
}

void MultipleExpression::addExpression(Expression *expr)
{
    listExpressions.push_back(expr);
}
