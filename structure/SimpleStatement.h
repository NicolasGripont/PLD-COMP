#ifndef _SIMPLESTATEMENT_H
#define _SIMPLESTATEMENT_H

#include "SimpleStatementType.h"
#include "Printable.h"

class SimpleStatement : public Printable
{
public:
	SimpleStatement(SimpleStatementType _type);
	virtual ~SimpleStatement();
	virtual string toString() const;
    SimpleStatementType getType();

private:
    SimpleStatementType type;
};

#endif
