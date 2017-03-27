#ifndef _ARGUMENT_H
#define _ARGUMENT_H

#include "Type.h"

class Argument
{
public:
    Argument(Type* _type, char* _id = nullptr, bool _isArray = false);

private:
    Type* type;
    char* id;
    bool isArray;
};

#endif