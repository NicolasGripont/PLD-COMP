#include "IRInstrEq.h"

IRInstrEq::IRInstrEq(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrThreeOp(_basicBlock, OperationType::cmp_eq, _dataType, _var1, _var2, _var3)
{

}

IRInstrEq::~IRInstrEq()
{

}

void IRInstrEq::genAsm(ostream &o)
{

}
