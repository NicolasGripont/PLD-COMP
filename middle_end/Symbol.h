#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

class Symbol
{
public:
    Symbol( std::string _name, Type _type,int _offset);

    enum class Type
    {
        INT_32,
        INT_64,
        CHAR,
        FUNCTION,
        PTR
    };

    std::string getName() const;
    Type getType() const;
    int getOffset() const;

private:
    std::string name;
    Type type;
    int offset;
};

#endif // SYMBOL_H