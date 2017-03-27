#ifndef _DECLARATIONVARIABLESTATEMENT_H
#define _DECLARATIONVARIABLESTATEMENT_H

#include "SimpleStatement.h"

class DeclarationVariableStatement : public SimpleStatement
{
public:
	DeclarationVariableStatement();
	virtual string print() const;
};

#endif