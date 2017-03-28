#ifndef _TYPE_H
#define _TYPE_H

#include "Printer.h"
#include "Enumeration.h"

class Type : public Printer
{
public:
    Type(TypeEnum _type);
    virtual ~Type();
    virtual string print() const;
    TypeEnum getType();

private:
    TypeEnum type;
};

#endif
