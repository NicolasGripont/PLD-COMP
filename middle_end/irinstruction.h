#ifndef _IRINSTRUCTION_H
#define _IRINSTRUCTION_H
#include <iostream>

#include "BasicBlock.h"

enum class IR_Operation {

    BINARY_OP,
    RWMEMORY,
    CALL,
    JUMP,
    SELECTION
};

//! The class for one 3-address instruction

class IRInstruction {

public:
    IRInstruction(BasicBlock* block, IR_Operation operation);
    ~IRInstruction();
    std::string toString() const;
	Type getType() const;
	Operation getOperation() const;
    BasicBlock * getBasicBlock() const;

protected:
    BasicBlock * block = nullptr; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
    IR_Operation operation;

    Symbol * operand_1 = nullptr;
    Symbol * operand_2 = nullptr;
    Symbol * operand_3 = nullptr;
};

#endif

/**< For 3-op instrs: d, x, y; for ldconst: d, c;  For call: label, d, params;  for wmem and rmem: choose yourself */
