#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>


class Symbol
{
public:
    enum class Type
    {
        INT_32,
        INT_64,
        CHAR,
        FUNCTION,
        PTR
    };
    Symbol(std::string _name, Type _type, int offset);
    std::string getName() const;
    Symbol::Type getType() const;
    int getOffset() const;
    void setOffset(int);
private:
    std::string name;
    Type type;
    int offset;
};

#endif // SYMBOL_H
