#ifndef DECLARATIONINITVARIABLE_H
#define DECLARATIONINITVARIABLE_H
#include <iostream>
#include "declarationvariable.h"
#include "expression.h"

using namespace std;

class DeclarationInitVariable : public DeclarationVariable {
private:
	Expression* expr;
public:
	DeclarationInitVariable(TYPE _type, string _id, Expression* _expr);
	virtual ~DeclarationInitVariable();
	virtual string print() const;
};
#endif