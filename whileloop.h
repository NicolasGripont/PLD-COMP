#ifndef WHILELOOP_H
#define WHILELOOP_H
#include <iostream>
#include "iterationstatement.h"
#include "expression.h"

using namespace std;

class WhileLoop : public IterationStatement {
public:
	WhileLoop(Expression* _expr, MultipleStatement *statements);
	~WhileLoop();
	virtual string print() const;
private:
	Expression* expr;
};
#endif
