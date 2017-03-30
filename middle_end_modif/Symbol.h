#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

#include "SymbolType.h"

class Symbol
{
public:
    Symbol(SymbolType _type, std::string _name);

    SymbolType getSymbolType();
private:
    SymbolType type;
    std::string name;
};

#endif
