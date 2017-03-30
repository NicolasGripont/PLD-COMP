#include "IRInstrDiv.h"

IRInstrDiv::IRInstrDiv(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2, std::string _var3)
    : IRInstrThreeOp(_basicBlock, OperationType::div, _dataType, _var1, _var2, _var3)
{

}

IRInstrDiv::~IRInstrDiv()
{

}

void IRInstrDiv::genAsm(ostream &o)
{

}
