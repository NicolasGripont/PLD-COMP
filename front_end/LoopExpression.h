#ifndef _LOOPEXPRESSION_H
#define _LOOPEXPRESSION_H

#include "Expression.h"
#include "Printable.h"

class LoopExpression : public Printable
{
public:
    LoopExpression(Expression* _expr);
    virtual ~LoopExpression();
    virtual std::string toString() const;

private:
    Expression* expr;
};

#endif