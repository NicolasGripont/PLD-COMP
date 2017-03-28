#ifndef _DECLARATIONFUNCTIONSTATEMENT_H
#define _DECLARATIONFUNCTIONSTATEMENT_H

#include "Printer.h"

class DeclarationFunctionStatement : public Printer

{
public:

	DeclarationFunctionStatement(bool _declaration);
	virtual ~DeclarationFunctionStatement();
	virtual string print() const;
    bool isDeclaration();

private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
};

#endif