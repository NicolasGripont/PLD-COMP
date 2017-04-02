#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

class Symbol
{
public:
    Symbol(std::string _name, int _type, int offset);
    std::string getName() const;
    int getType() const;
    int getOffset() const;
    void setOffset(int);

private:
    std::string name;
    int type;
    int offset;
};

#endif // SYMBOL_H
