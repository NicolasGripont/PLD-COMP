#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printer.h"

class Expression : public Printer
{
public:
    Expression();
    virtual string print() const;
};

#endif