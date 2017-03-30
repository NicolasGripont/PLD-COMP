#include "IRInstrAdd.h"

IRInstrAdd::IRInstrAdd(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrThreeOp(_basicBlock, OperationType::add, _dataType, _var1, _var2, _var3)
{

}

IRInstrAdd::~IRInstrAdd()
{

}

void IRInstrAdd::genAsm(ostream &o)
{

}
