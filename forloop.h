#ifndef FORLOOP_H
#define FORLOOP_H
#include <iostream>
#include "iterationstatement.h"
#include "expression.h"

using namespace std;

class ForLoop : public IterationStatement {
public:
	ForLoop(Expression* _expr1, Expression* _expr2, Expression* _expr3, MultipleStatement *statements);
	~ForLoop();
	virtual string print() const;
private:
	Expression* expr1;
	Expression* expr2;
	Expression* expr3;
};
#endif
