#include "Argument.h"

Argument::Argument(Type* _type, char* _id, bool _array)
    : Printable(), type(_type), id(_id), array(_array)
{

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
