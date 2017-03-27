#ifndef _MULTIPLESTATEMENT_H
#define _MULTIPLESTATEMENT_H

#include <vector>

#include "SimpleStatement.h"

class MultipleStatement
{
public:
    MultipleStatement();

    void addStatement(SimpleStatement* statement);
    int countStatements();

    SimpleStatement*& operator[] (int i);

private:
    std::vector<SimpleStatement*> statements;
};

#endif
