#include "Type.h"

//Type::Type(TypeEnum _type) : Printer(), type(_type)
Type::Type(int _type) : Printer(), type(_type)
{

}

Type::~Type()
{

}

//TypeEnum Type::getType()
int Type::getType()
{
    return type;
}

string Type::print() const
{
	// char typeStr = (char) type;
	return "Type";
}
