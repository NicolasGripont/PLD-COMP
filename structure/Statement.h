#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "MultipleStatement.h"

class Statement
{
public:
    Statement(MultipleStatement* _multipleStatement);

private:
    MultipleStatement* multipleStatement;
};

#endif