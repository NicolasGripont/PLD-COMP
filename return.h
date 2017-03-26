#ifndef RETURN_H
#define RETURN_H
#include <iostream>
#include "statement.h"
#include "expression.h"

using namespace std;

class Return : public Statement {
private:
	Expression* expr;
public:
	Return(Expression* _expr);
	virtual ~Return();
	virtual string print() const;
};
#endif