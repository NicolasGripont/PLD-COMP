#include "Argument.h"

Argument::Argument(Type* _type, char* _id, bool _isArray)
    : Printer(), type(_type), id(_id), isArray(_isArray)
{

}

string Argument::print() {
	return "Argument";
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
>>>>>>> origin/dev
