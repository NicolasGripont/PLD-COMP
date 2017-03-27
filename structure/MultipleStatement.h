#ifndef _MULTIPLESTATEMENT_H
#define _MULTIPLESTATEMENT_H

#include <vector>

#include "SimpleStatement.h"

class MultipleStatement
{
public:
    MultipleStatement();

    void addStatement(SimpleStatement* statement);

private:
    std::vector<SimpleStatement*> statements;
};

#endif