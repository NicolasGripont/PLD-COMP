#ifndef _IRRWMEMORY_H
#define _IRRWMEMORY_H

#include "Symbol.h"
#include "IRInstruction.h"

class IRRWMemory : public IRInstruction
{
public:
    enum class Type {
        READ_MEMORY,
        WRITE_MEMORY,
        LOAD_CST
    };

    IRRWMemory(Type _type, Symbol * sour, Symbol * dest);
    ~IRRWMemory();

    std::string toString() const;

    Type getType() const;
    Symbol *getSource() const;
    Symbol *getDestination() const;

private:
    Type type;

    Symbol * source;
    Symbol * destination;
};

#endif // IRRWMEMORY_H