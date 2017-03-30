#include "IRInstruction.h"
#include "BasicBlock.h"

IRInstruction::IRInstruction(BasicBlock* _basicBlock, OperationType _opType, DataType _dataType)
    : basicBlock(_basicBlock), opType(_opType), dataType(_dataType)
{

}

IRInstruction::~IRInstruction()
{

}
