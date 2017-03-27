#ifndef _TYPE_H
#define _TYPE_H

#include "Printer.h"

class Type : public Printer
{
public:
    Type(int _type);
    virtual string print();
    int getType();

private:
    int type;
};

#endif
