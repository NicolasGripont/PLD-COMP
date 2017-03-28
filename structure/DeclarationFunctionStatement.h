#ifndef _DECLARATIONFUNCTIONSTATEMENT_H
#define _DECLARATIONFUNCTIONSTATEMENT_H

#include "Printable.h"

class DeclarationFunctionStatement : public Printable

{
public:

	DeclarationFunctionStatement(bool _declaration);
	virtual ~DeclarationFunctionStatement();
	virtual string toString() const;
    bool isDeclaration();

private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
};

#endif