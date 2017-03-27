#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "MultipleStatement.h"
#include "Printer.h"

class Statement : public Printer
{
public:
    Statement(MultipleStatement* _multipleStatement);
    virtual string print();

private:
    MultipleStatement* multipleStatement;
};

#endif