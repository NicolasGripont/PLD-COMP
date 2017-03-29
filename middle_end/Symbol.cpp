#include "Symbol.h"

Symbol::Symbol(std::string _name, SymbolType _type, int _offset, bool _function, bool _array)
	: name(_name), type(_type), offset(_offset), function(_function), array(_array)
{

}

std::string Symbol::getName() const
{
	return name;
}

SymbolType Symbol::getType() const
{
	return type;
}

int Symbol::getOffset() const
{
	return offset;
}
