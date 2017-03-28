#ifndef _DECLARATIONVARIABLESTATEMENT_H
#define _DECLARATIONVARIABLESTATEMENT_H

#include "SimpleStatement.h"

class DeclarationVariableStatement : public SimpleStatement
{
public:
	DeclarationVariableStatement();
	virtual ~DeclarationVariableStatement();
	virtual string toString() const;
};

#endif