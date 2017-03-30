#include "IRInstrGt.h"

IRInstrGt::IRInstrGt(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrThreeOp(_basicBlock, OperationType::cmp_gt, _dataType, _var1, _var2, _var3)
{

}

IRInstrGt::~IRInstrGt()
{

}

void IRInstrGt::genAsm(ostream &o)
{

}
