#ifndef MULTIPLEDECLARATIONVARIABLEGLOBAL_H
#define MULTIPLEDECLARATIONVARIABLEGLOBAL_H
#include <iostream>
#include <vector>
#include "declaration.h"
#include "declarationvariable.h"
using namespace std;

class MultipleDeclarationVariableGlobal : public Declaration {
public:
	MultipleDeclarationVariableGlobal();
	~MultipleDeclarationVariableGlobal();
	void addDeclarationVariable(DeclarationVariable *);
	virtual string print() const;
private:
	vector<DeclarationVariable *> declarations;
};
#endif
