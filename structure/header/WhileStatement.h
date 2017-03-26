#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include "IterationStatement.h"
#include "Expression.h"
#include "Statement.h"

class WhileStatement : public IterationStatement
{
public:
    WhileStatement(Expression * expr, Statement * state);
    ~WhileStatement();

private:
    Expression * expression;
    Statement * statement;
};

#endif // WHILESTATEMENT_H
