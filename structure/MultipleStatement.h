#ifndef _MULTIPLESTATEMENT_H
#define _MULTIPLESTATEMENT_H

#include <vector>

#include "SimpleStatement.h"
#include "Printer.h"

class MultipleStatement : public Printer
{
public:
    MultipleStatement();
	virtual string print();
    void addStatement(SimpleStatement* statement);

private:
    std::vector<SimpleStatement*> statements;
};

#endif