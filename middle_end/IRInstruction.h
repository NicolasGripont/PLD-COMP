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
        RWMEMORY,
        CALL,
        JUMP,
        SELECTION
    };
    IRInstruction();
    IRInstruction(BasicBlock* block, Type _type);
    virtual ~IRInstruction();

    Type getOperation() const;
    BasicBlock * getBasicBlock() const;

protected:
    BasicBlock * block = nullptr; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    Type type;
};

#endif

/**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
