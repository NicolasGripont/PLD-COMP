#ifndef _DECLARATION_H
#define _DECLARATION_H

#include "Printer.h"

class Declaration : public Printer
{
public:
    Declaration();
    virtual ~Declaration();
    virtual string print() const;
};

#endif
