#ifndef MULTIPLESTATEMENT_H
#define MULTIPLESTATEMENT_H
#include <iostream>
#include <vector>
#include "statement.h"

using namespace std;

class MultipleStatement {
public:
	MultipleStatement();
	~MultipleStatement();
	void addStatement(Statement *);
	virtual string print() const;
private:
	vector<Statement *> statements;
};
#endif
