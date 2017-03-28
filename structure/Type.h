#ifndef _TYPE_H
#define _TYPE_H

#include "Printer.h"
#include "Enumeration.h"

class Type : public Printer
{
public:
    Type(TOKEN _type);
    virtual ~Type();
    virtual string print() const;
    TOKEN getType();

private:
    TOKEN type;
};

#endif
