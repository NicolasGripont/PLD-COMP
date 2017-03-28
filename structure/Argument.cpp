#include "Argument.h"

Argument::Argument(Type* _type, char* _id, bool _array)
    : Printable(), type(_type), id(_id), array(_array)
{

}

Argument::~Argument() 
{
    delete type;
}

string Argument::toString() const
{
    string txt;
    if (type != nullptr)
    {
        txt = type->toString();
        if (id != nullptr)
        {
            txt += string(" ") + id;
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
