#ifndef _LOOPEXPRESSION_H
#define _LOOPEXPRESSION_H

#include "Expression.h"
#include "Printer.h"

class LoopExpression : public Printer
{
public:
    LoopExpression(Expression* _expr);
    virtual string print();

private:
    Expression* expr;
};

#endif