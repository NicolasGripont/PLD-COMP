#ifndef _WHILELOOP_H
#define _WHILELOOP_H

#include "IterationStatement.h"
#include "Expression.h"

class WhileLoop : public IterationStatement
{
public:
    WhileLoop(Expression* _expr, Statement* _statement);
    virtual ~WhileLoop();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

private:
    Expression* expr;
};

#endif
