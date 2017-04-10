#ifndef _DECLARATIONFUNCTIONSTATEMENT_H
#define _DECLARATIONFUNCTIONSTATEMENT_H

#include "Printable.h"
#include "IRTranslatable.h"

class DeclarationFunctionStatement : public Printable, public IRTranslatable
{
public:
	DeclarationFunctionStatement(bool _declaration);
	virtual ~DeclarationFunctionStatement();

    bool isDeclaration();

private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
};

#endif
