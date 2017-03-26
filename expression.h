#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include "statement.h"

using namespace std;

class Expression : public Statement {
public:
	Expression();
	virtual ~Expression();
	virtual string print() const = 0;
};
#endif
