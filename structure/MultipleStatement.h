#ifndef _MULTIPLESTATEMENT_H
#define _MULTIPLESTATEMENT_H

#include <vector>

#include "SimpleStatement.h"
#include "Printer.h"

class MultipleStatement : public Printer
{
public:
    MultipleStatement();
	virtual string print() const;

    void addStatement(SimpleStatement* statement);
    int countStatements();

    SimpleStatement*& operator[] (int i);

private:
    std::vector<SimpleStatement*> statements;
};

#endif
