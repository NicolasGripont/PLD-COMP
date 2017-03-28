#ifndef _TYPE_H
#define _TYPE_H

#include "Printer.h"
#include "Enumeration.h"

class Type : public Printer
{
public:
    Type(int _type);
    virtual ~Type();
    virtual string print() const;
    int getType();

private:
    int type;
};

#endif
