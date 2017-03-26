#ifndef SIMPLESTATEMENT_H
#define SIMPLESTATEMENT_H
#include <iostream>
#include "statement.h"

using namespace std;

class SimpleStatement : public Statement {
public:
	SimpleStatement();
	~SimpleStatement();
	virtual string print() const;
};
#endif
