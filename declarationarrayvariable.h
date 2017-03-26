#ifndef DECLARATIONARRAYVARIABLE_H
#define DECLARATIONARRAYVARIABLE_H
#include <iostream>
#include "declarationvariable.h"

using namespace std;

class DeclarationArrayVariable : public DeclarationVariable {
private:
	int size;
public:
	DeclarationArrayVariable(TYPE _type, string _id, int _size);
	virtual ~DeclarationArrayVariable();
	virtual string print() const;
};
#endif
