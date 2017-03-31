#ifndef _IRINSTRUCTION_H
#define _IRINSTRUCTION_H

#include <iostream>

class BasicBlock;

//! The class for one 3-address instruction

class IRInstruction
{
public:
    enum IRInstructionType
    {
        BINARY_OP,
        RWMEMORY,
        CALL,
        JUMP,
        SELECTION
    };
    IRInstruction();
    IRInstruction(BasicBlock* block, IRInstructionType _type);
    virtual ~IRInstruction();
    virtual std::string toString() const = 0;

    IRInstructionType getOperation() const;
    BasicBlock * getBasicBlock() const;

protected:
    BasicBlock * block = nullptr; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    IRInstructionType type;
};

#endif

/**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
