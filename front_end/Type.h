#ifndef _TYPE_H
#define _TYPE_H

#include "Printable.h"
#include "Enumeration.h"

class Type : public Printable
{
public:
    Type(int _type);
    virtual ~Type();
    virtual std::string toString() const;
    int getType();

private:
    int type;
};

#endif
