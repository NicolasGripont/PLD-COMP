#ifndef _DECLARATIONFUNCTIONSTATEMENT_H
#define _DECLARATIONFUNCTIONSTATEMENT_H

#include "Printable.h"

class DeclarationFunctionStatement : public Printable
{
public:
	DeclarationFunctionStatement(bool _declaration);
	virtual ~DeclarationFunctionStatement();
	virtual std::string toString() const = 0;
    bool isDeclaration();

private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
};

#endif