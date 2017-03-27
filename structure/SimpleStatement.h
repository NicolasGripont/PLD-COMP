#ifndef _SIMPLESTATEMENT_H
#define _SIMPLESTATEMENT_H

#include "SimpleStatementType.h"

class SimpleStatement
{
private:
    SimpleStatementType type;
public:
	SimpleStatement(SimpleStatementType _type);

    SimpleStatementType getType();
};

#endif
