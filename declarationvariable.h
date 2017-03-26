#ifndef DECLARATIONVARIABLE_H
#define DECLARATIONVARIABLE_H
#include <iostream>
#include "type.h"
using namespace std;

class DeclarationVariable {
public:
	DeclarationVariable(TYPE type, string name);
	
	DeclarationVariable(char*&);
    DeclarationVariable(char*&, int&);
	
	~DeclarationVariable();
	virtual string print() const;
private:
	TYPE type;
	string name;
};
#endif
