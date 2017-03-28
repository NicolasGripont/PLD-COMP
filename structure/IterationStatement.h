#ifndef _ITERATIONSTATEMENT_H
#define _ITERATIONSTATEMENT_H

#include "SimpleStatement.h"
#include "Statement.h"

class IterationStatement : public SimpleStatement
{
public:
    IterationStatement(Statement* _statement);
    virtual ~IterationStatement();
    virtual string print() const;

protected:
    Statement* statement;
};

#endif