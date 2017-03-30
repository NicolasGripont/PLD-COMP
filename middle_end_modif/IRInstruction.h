#ifndef IR_INSTRUCTION_H
#define IR_INSTRUCTION_H

#include "DataType.h"
#include "OperationType.h"

class BasicBlock;

class IRInstruction {
public:
	IRInstruction(BasicBlock* _basicBlock, OperationType _opType, DataType _dataType);
    ~IRInstruction();

    DataType getDataType();
    OperationType getOperationType();

	/** Actual code generation */
	virtual void genAsm(ostream &o) = 0; /**< x86 assembly code generation for this IR instruction */
 private:
	BasicBlock* basicBlock; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
	OperationType opType;
	DataType dataType;
};

#endif
