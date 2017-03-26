#ifndef IFELSESTATEMENT_H
#define IFELSESTATEMENT_H
#include <iostream>
#include "multiplestatement.h"
#include "selectionstatement.h"

using namespace std;

class IfElseStatement : public SelectionStatement {
public:
	IfElseStatement(Expression* expr, MultipleStatement *ifStatement, MultipleStatement *elseStatement);
	~IfElseStatement();
	virtual string print() const;
protected:
	MultipleStatement *elseStatement;
};
#endif
