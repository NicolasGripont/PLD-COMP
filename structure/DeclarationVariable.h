#ifndef _DECLARATIONVARIABLE_H
#define _DECLARATIONVARIABLE_H

#include "Printer.h"

class DeclarationVariable : public Printer
{
public:
    DeclarationVariable(char* _id);
    char* getId();
    virtual string print();

protected:
    char* id;
};

#endif
