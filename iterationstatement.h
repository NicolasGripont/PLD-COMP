#ifndef ITERATIONSTATEMENT_H
#define ITERATIONSTATEMENT_H
#include <iostream>
#include "statement.h"
#include "multiplestatement.h"

using namespace std;

class IterationStatement : public Statement {
public:
	IterationStatement(MultipleStatement *statements);
	~IterationStatement();
	virtual string print() const = 0;
private:
	MultipleStatement *statements;
};
#endif
