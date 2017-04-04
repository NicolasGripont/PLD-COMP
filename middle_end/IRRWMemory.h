#ifndef _IRRWMEMORY_H
#define _IRRWMEMORY_H

#include "Symbol.h"
#include "IROperationWithDestination.h"

class IRRWMemory : public IROperationWithDestination
{
public:
    enum class Type {
        READ_MEMORY,
        WRITE_MEMORY,
    };

    IRRWMemory(Type _type, Symbol* dest, Symbol* sour);
    ~IRRWMemory();

    virtual std::string toString() const;

    Type getType() const;
    Symbol* getSource() const;

private:
    Type type;

    Symbol* source;

};

#endif // IRRWMEMORY_H
