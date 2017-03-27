#include "Type.h"

Type::Type(int _type) : Printer(), type(_type)
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