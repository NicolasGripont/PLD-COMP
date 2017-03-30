#include "IRInstrJump.h"

IRInstrJump::IRInstrJump(BasicBlock* _basicBlock, std::string _label)
   : IRInstruction(_basicBlock, OperationType::jump, DataType::INT64), label(_label)
{

}

IRInstrJump::~IRInstrJump()
{

}

void IRInstrJump::genAsm(ostream &o)
{

}
