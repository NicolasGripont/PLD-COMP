#ifndef _PUREDECLARATIONFUNCTIONSTATEMENT_H
#define _PUREDECLARATIONFUNCTIONSTATEMENT_H

#include "DeclarationFunctionStatement.h"

// Declaration sans initialisation de la fonction
class PureDeclarationFunctionStatement : public DeclarationFunctionStatement
{
public:
	PureDeclarationFunctionStatement();
};

#endif