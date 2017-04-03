#ifndef _LOOPEXPRESSION_H
#define _LOOPEXPRESSION_H

#include "Expression.h"
#include "Printable.h"

class LoopExpression : public Printable, public IRTranslatable
{
public:
    LoopExpression(Expression* _expr);
    virtual ~LoopExpression();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

private:
    Expression* expr;
};

#endif
