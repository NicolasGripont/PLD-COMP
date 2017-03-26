#ifndef DECLARATIONARRAYVARIABLE_H
#define DECLARATIONARRAYVARIABLE_H
#include <iostream>
#include "declarationvariable.h"

using namespace std;

class DeclarationArrayVariable : public DeclarationVariable
{
public:
	DeclarationArrayVariable(TYPE _type, string _id, int _size);
	
	DeclarationArrayVariable(char*&, int&);
	
	virtual ~DeclarationArrayVariable();
	virtual string print() const;
private:
	int size;
};
#endif
