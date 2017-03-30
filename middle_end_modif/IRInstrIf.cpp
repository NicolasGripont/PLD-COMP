#include "IRInstrIf.h"

IRInstrIf::IRInstrIf(BasicBlock* _basicBlock, std::string _reg, std::string _label1, std::string _label2)
    : IRInstruction(_basicBlock, OperationType::selection, DataType::INT64)
    , reg(_reg), label1(_label1), label2(_label2)
{

}

IRInstrIf::~IRInstrIf()
{

}

void IRInstrIf::genAsm(ostream &o)
{

}
