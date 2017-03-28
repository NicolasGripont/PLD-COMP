#include "Type.h"

Type::Type(int _type) : Printer(), type(_type)
{

}

Type::~Type()
{

}

int Type::getType()
{
    return type;
}

string Type::print() const
{
	return "Type";
}
