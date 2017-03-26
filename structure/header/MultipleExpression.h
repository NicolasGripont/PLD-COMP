#ifndef MULTIPLEEXPRESSION_H
#define MULTIPLEEXPRESSION_H

#include "Expression.h"
#include <vector>

using namespace std;

class MultipleExpression : public Expression
{
public:
    MultipleExpression();
    ~MultipleExpression();

    void addExpression(Expression *  expr);

private:
    vector<Expression*> listExpressions;
};

#endif // MULTIPLEEXPRESSION_H
