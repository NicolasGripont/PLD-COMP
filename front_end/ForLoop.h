#ifndef _FOORLOOP_H
#define _FOORLOOP_H

#include "IterationStatement.h"
#include "LoopExpression.h"

class ForLoop : public IterationStatement
{
public:
    ForLoop(LoopExpression* _expr1, LoopExpression* _expr2, LoopExpression* _expr3, Statement* _statement);
	virtual ~ForLoop();
	virtual string toString() const;
	
private:
    LoopExpression* expr1;
    LoopExpression* expr2;
    LoopExpression* expr3;
};

#endif