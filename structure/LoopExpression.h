#ifndef _LOOPEXPRESSION_H
#define _LOOPEXPRESSION_H

#include "Expression.h"

class LoopExpression
{
public:
    LoopExpression(Expression* _expr);

private:
    Expression* expr;
};

#endif