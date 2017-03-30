#include "IRInstrSub.h"

IRInstrSub::IRInstrSub(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrThreeOp(_basicBlock, OperationType::sub, _dataType, _var1, _var2, _var3)
{

}

IRInstrSub::~IRInstrSub()
{

}

void IRInstrSub::genAsm(ostream &o)
{

}
