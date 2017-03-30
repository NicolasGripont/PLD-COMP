#include "IRInstrCall.h"

IRInstrCall::IRInstrCall(BasicBlock* _basicBlock, DataType _dataType,
     std::string _var, std::string _funcName, std::vector<std::string> _params)
    : IRInstruction(_basicBlock, OperationType::call, _dataType), funcName(_funcName), params(_params)
{

}

IRInstrCall::~IRInstrCall()
{

}

void IRInstrCall::genAsm(ostream &o)
{

}
