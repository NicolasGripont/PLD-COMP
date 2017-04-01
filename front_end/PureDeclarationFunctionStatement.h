#ifndef _PUREDECLARATIONFUNCTIONSTATEMENT_H
#define _PUREDECLARATIONFUNCTIONSTATEMENT_H

#include "DeclarationFunctionStatement.h"

// Declaration sans initialisation de la fonction
class PureDeclarationFunctionStatement : public DeclarationFunctionStatement
{
public:
	PureDeclarationFunctionStatement();
	virtual ~PureDeclarationFunctionStatement();

    std::string toString() const;
    void buildIR(CFG * cfg) const;
};

#endif
