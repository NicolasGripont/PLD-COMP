#ifndef _SIMPLESTATEMENT_H
#define _SIMPLESTATEMENT_H

#include "Printer.h"

class SimpleStatement : public Printer
{
public:
	SimpleStatement();
	virtual string print();
};

#endif