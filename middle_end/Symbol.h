#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

enum class SymbolType
{
    INT_32,
    INT_64,
    CHAR,
    FUNCTION,
    PTR
};

class Symbol
{
public:
    Symbol( std::string _name, SymbolType _type,int _offset);
    std::string getName() const;
    SymbolType getType() const;
    int getOffset() const;

private:
    std::string name;
    SymbolType type;
    int offset;
};

#endif // SYMBOL_H
