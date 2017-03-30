#include "Symbol.h"

Symbol::Symbol(SymbolType _type, std::string _name)
    :type(_type),name(_name)
{

}

SymbolType Symbol::getSymbolType()
{
    return type;
}
