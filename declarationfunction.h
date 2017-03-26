#ifndef DECLARATIONFUNCTION_H
#define DECLARATIONFUNCTION_H
#include <iostream>
#include <vector>
#include "declaration.h"
#include "type.h"
#include "multipleargument.h"
#include "multiplestatement.h"

using namespace std;

class DeclarationFunction : public Declaration {
public:
	DeclarationFunction(TYPE type, string name, MultipleArgument * arguments, MultipleStatement *statements);
	~DeclarationFunction();
	virtual string print() const;
private:
	TYPE type;
	string name;
	MultipleArgument *arguments;
	MultipleStatement *statements;
};
#endif
