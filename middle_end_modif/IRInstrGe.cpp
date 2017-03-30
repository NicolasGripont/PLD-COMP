#include "IRInstrGe.h"

IRInstrGe::IRInstrGe(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrThreeOp(_basicBlock, OperationType::cmp_ge, _dataType, _var1, _var2, _var3)
{

}

IRInstrGe::~IRInstrGe()
{

}

void IRInstrGe::genAsm(ostream &o)
{

}
