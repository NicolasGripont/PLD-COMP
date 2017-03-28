#ifndef _SIMPLESTATEMENT_H
#define _SIMPLESTATEMENT_H

#include "SimpleStatementType.h"
#include "Printer.h"

class SimpleStatement : public Printer
{
public:
	SimpleStatement(SimpleStatementType _type);
	virtual ~SimpleStatement();
	virtual string print() const;
    SimpleStatementType getType();

private:
    SimpleStatementType type;
};

#endif
