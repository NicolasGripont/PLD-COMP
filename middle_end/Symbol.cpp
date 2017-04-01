#include "Symbol.h"

Symbol::Symbol(std::string _name, int _type, int _offset)
	: name(_name), type(_type), offset(_offset)
{

}

std::string Symbol::getName() const
{
	return name;
}

int Symbol::getType() const
{
	return type;
}

int Symbol::getOffset() const
{
	return offset;
}

void Symbol::setOffset(int _offset)
{
	offset = _offset;
}
