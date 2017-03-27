#ifndef _ARGUMENT_H
#define _ARGUMENT_H

#include "Type.h"

class Argument
{
public:
    Argument(Type* _type, char* _id = nullptr, bool _array = false);

    Type* getType();
    char* getName();
    bool isArray();
private:
    Type* type;
    char* id;
    bool array;
};

#endif
