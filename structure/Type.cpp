#include "Type.h"

Type::Type(TOKEN _type) : Printer(), type(_type)
{

}

Type::~Type()
{

}

TOKEN Type::getType()
{
    return type;
}

string Type::print() const
{
	return "Type";
}
