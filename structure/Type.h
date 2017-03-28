#ifndef _TYPE_H
#define _TYPE_H

#include "Printer.h"
#include "Enumeration.h"

class Type : public Printer
{
public:
    //Type(TypeEnum _type);
    Type(int _type);
    virtual ~Type();
    virtual string print() const;
    //TypeEnum getType();
    int getType();

private:
    //TypeEnum type;
    int type;
};

#endif
