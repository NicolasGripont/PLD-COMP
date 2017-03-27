#include "Argument.h"

Argument::Argument(Type* _type, char* _id, bool _array)
    : type(_type), id(_id), array(_array)
{

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
