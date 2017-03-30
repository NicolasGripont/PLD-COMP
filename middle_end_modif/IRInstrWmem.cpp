#include "IRInstrWmem.h"

IRInstrWmem::IRInstrWmem(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2)
    : IRInstrTwoOp(_basicBlock, OperationType::wmem, _dataType, _var1, _var2)
{

}

IRInstrWmem::~IRInstrWmem()
{

}

void IRInstrWmem::genAsm(ostream &o)
{

}
