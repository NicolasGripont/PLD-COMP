#ifndef _IRRWMEMORY_ARRAY_H
#define _IRRWMEMORY_ARRAY_H

#include "Symbol.h"
#include "IROperationWithDestination.h"

class IRRWMemoryArray : public IROperationWithDestination
{
public:
    enum class Type {
        READ_MEMORY,
        WRITE_MEMORY,
    };

    IRRWMemoryArray(Type _type, Symbol* dest, Symbol* sour, Symbol* targetPosition);
    ~IRRWMemoryArray();

    virtual std::string toString() const;

    Type getType() const;
    Symbol* getSource() const;
    Symbol* getTargetPosition() const;

private:
    Type type;

    Symbol* source;
    Symbol* targetPosition;
};

#endif // _IRRWMEMORY_ARRAY_H
