#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "MultipleStatement.h"
#include "Printer.h"

class Statement : public Printer
{
public:
    Statement(MultipleStatement* _multipleStatement);
    virtual ~Statement();
    virtual string print() const;

private:
    MultipleStatement* multipleStatement;
};

#endif