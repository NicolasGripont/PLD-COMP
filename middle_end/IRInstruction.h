#ifndef _IRINSTRUCTION_H
#define _IRINSTRUCTION_H

#include "BasicBlock.h"

#include "../front_end/Printable.h"

#include <iostream>
//! The class for one 3-address instruction

class IRInstruction : public Printable
{
public:
    enum class Operation
    {
        BINARY_OP,
        LOAD_CONSTANT,
        RWMEMORY,
        RWMEMORYARRAY,
        CALL,
        CONDITIONNAL,
        RETURN
    };

    IRInstruction(Operation _op);
    virtual ~IRInstruction() = default;

    Operation getOperation() const;

protected:
    Operation type;
};

#endif
