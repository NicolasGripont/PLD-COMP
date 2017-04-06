#include <string.h>
#include <iostream>

#include "Argument.h"

std::string Argument::unnamedBase = "UNNAMED_";
int Argument::unnamedCount = 0;

Argument::Argument(Type* _type, char* _id, bool _array)
    : Printable(), type(_type), id(_id), array(_array)
{
    if(id == nullptr)
    {
        id = (char*)unnamedBase.c_str();
        char s[20];
        sprintf(s, "%d", unnamedCount);
        id = strdup(strcat(id, s));

        ++unnamedCount;
    }
}

Argument::~Argument() 
{
    if(id != nullptr) 
    {
        free(id);
    }
    if(type != nullptr) 
    {
        delete type;
    }
}

std::string Argument::toString() const
{
    std::string txt = "";
    if (type != nullptr)
    {
        txt = type->toString();
        if (id != nullptr)
        {
            txt += " " + std::string(id);
        }
        if (array)
        {
            txt += "[]";
        }
    }
    return txt;
}

void Argument::buildIR(CFG *cfg) const
{
    //do nothing
}

Type* Argument::getType()
{
    return type;
}

char* Argument::getName()
{
    return id;
}

bool Argument::isArray()
{
    return array;
}
