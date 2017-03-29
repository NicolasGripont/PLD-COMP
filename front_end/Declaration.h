#ifndef _DECLARATION_H
#define _DECLARATION_H

#include "Printable.h"

class Declaration : public Printable
{
public:
    Declaration();
    virtual ~Declaration();
    virtual string toString() const = 0;
};

#endif
