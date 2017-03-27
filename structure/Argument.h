#ifndef _ARGUMENT_H
#define _ARGUMENT_H

#include "Type.h"
#include "Printer.h"

class Argument : public Printer
{
public:
    Argument(Type* _type, char* _id = nullptr, bool _isArray = false);
    virtual string print();
    Type* getType();
    char* getName();
    bool isArray();

private:
    Type* type;
    char* id;
    bool array;
};

#endif
