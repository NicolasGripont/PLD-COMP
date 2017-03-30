#include "IRInstrTwoOp.h"

IRInstrTwoOp::IRInstrTwoOp(BasicBlock* _basicBlock, OperationType opType,
     DataType _dataType, std::string _var1, std::string _var2)
    : IRInstruction(_basicBlock, opType, _dataType), var1(_var1), var2(_var2)
{

}

IRInstrTwoOp::~IRInstrTwoOp()
{

}
