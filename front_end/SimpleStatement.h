#ifndef _SIMPLESTATEMENT_H
#define _SIMPLESTATEMENT_H

#include "SimpleStatementType.h"
#include "Printable.h"
#include "IRTranslatable.h"

class SimpleStatement : public Printable, public IRTranslatable
{
public:
	SimpleStatement(SimpleStatementType _type);
	virtual ~SimpleStatement();
    SimpleStatementType getType();

private:
    SimpleStatementType type;
};

#endif
