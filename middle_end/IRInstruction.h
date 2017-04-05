#ifndef _IRINSTRUCTION_H
#define _IRINSTRUCTION_H

#include "BasicBlock.h"

#include "../front_end/Printable.h"

#include <iostream>
//! The class for one 3-address instruction

class IRInstruction : public Printable
{
public:
    enum class Type
    {
        BINARY_OP,
        LOAD_CONSTANT,
        RWMEMORY,
        CALL,
        JUMP,
        SELECTION,
        RETURN
    };

    IRInstruction(Type _type);
    virtual ~IRInstruction() = default;

    Type getOperation() const;

protected:
    Type type;
};

#endif
