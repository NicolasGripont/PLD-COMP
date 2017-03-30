#include "IRInstrThreeOp.h"

IRInstrThreeOp::IRInstrThreeOp(BasicBlock* _basicBlock, OperationType opType,
     DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrTwoOp(_basicBlock, opType, _dataType, _var1, _var2), var3(_var3)
{

}

IRInstrThreeOp::~IRInstrThreeOp()
{

}
