#ifndef _TYPE_H
#define _TYPE_H

#include "Printable.h"
#include "IRTranslatable.h"
#include "Enumeration.h"

class Type : public Printable, IRTranslatable
{
public:
    Type(int _type);
    virtual ~Type();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

    int getType();

private:
    int type;
};

#endif
