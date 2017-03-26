#ifndef DECLARATIONINITVARIABLE_H
#define DECLARATIONINITVARIABLE_H
#include <iostream>
#include "declarationvariable.h"
#include "expression.h"

using namespace std;

class DeclarationInitVariable : public DeclarationVariable
{
public:
	DeclarationInitVariable(TYPE _type, string _id, Expression* _expr);
	
	DeclarationInitVariable(char*&, Expression*&);
	
	virtual ~DeclarationInitVariable();
	virtual string print() const;
private:
	Expression* expr;
};
#endif
