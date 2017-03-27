#ifndef _DECLARATIONFUNCTIONSTATEMENT_H
#define _DECLARATIONFUNCTIONSTATEMENT_H


class DeclarationFunctionStatement 
{
public:

	DeclarationFunctionStatement(bool _declaration);
    bool isDeclaration();

private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
};

#endif