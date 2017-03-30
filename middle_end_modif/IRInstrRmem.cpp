#include "IRInstrRmem.h"

IRInstrRmem::IRInstrRmem(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2)
    : IRInstrTwoOp(_basicBlock, OperationType::rmem, _dataType, _var1, _var2)
{

}

IRInstrRmem::~IRInstrRmem()
{

}

void IRInstrRmem::genAsm(ostream &o)
{

}
