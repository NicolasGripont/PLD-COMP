#ifndef MULTIPLEDECLARATIONVARIABLELOCAL_H
#define MULTIPLEDECLARATIONVARIABLELOCAL_H
#include <iostream>
#include <vector>
#include "statement.h"
#include "declarationvariable.h"
using namespace std;

class MultipleDeclarationVariableLocal : public Statement {
public:
	MultipleDeclarationVariableLocal();
	~MultipleDeclarationVariableLocal();
	void addDeclarationVariable(DeclarationVariable *);
	virtual string print() const;
private:
	vector<DeclarationVariable *> declarations;
};
#endif
