#include "Argument.h"

Argument::Argument(Type* _type, char* _id, bool _array)
    : Printer(), type(_type), id(_id), array(_array)
{

}

Argument::~Argument() 
{
    delete type;
    delete id;
}

string Argument::print() const
{
    string txt;
    if (type != nullptr)
    {
        txt = type->print();
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
