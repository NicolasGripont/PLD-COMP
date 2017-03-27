#ifndef _GLOBALDECLARATIONVARIABLE_H
#define _GLOBALDECLARATIONVARIABLE_H

#include "Declaration.h"
#include "MultipleDeclarationVariable.h"

class GlobalDeclarationVariable : public Declaration
{
public:
	GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable);
	virtual string print();

private:
	MultipleDeclarationVariable* multipleDeclarationVariable;
};


#endif