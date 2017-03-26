#ifndef SELECTIONSTATEMENT_H
#define SELECTIONSTATEMENT_H
#include <iostream>
#include "statement.h"
#include "expression.h"
#include "multiplestatement.h"

using namespace std;

class SelectionStatement : public Statement {
public:
	SelectionStatement(Expression* expr, MultipleStatement *statements);
	~SelectionStatement();
	virtual string print() const = 0;
private:
	Expression* expr;
	MultipleStatement *statements;
};
#endif
