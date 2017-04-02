#ifndef _LOOPEXPRESSION_H
#define _LOOPEXPRESSION_H

#include "Expression.h"
#include "Printable.h"

class LoopExpression : public Printable, public IRTranslatable
{
public:
    LoopExpression(Expression* _expr);
    virtual ~LoopExpression();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

private:
    Expression* expr;
};

#endif
