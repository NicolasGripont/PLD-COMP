#ifndef _DECLARATIONFUNCTIONSTATEMENT_H
#define _DECLARATIONFUNCTIONSTATEMENT_H

#include "Printer.h"

class DeclarationFunctionStatement : public Printer
{
public:
	DeclarationFunctionStatement(bool _declaration);
    bool isDeclaration();
    virtual string print();

private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
};

#endif