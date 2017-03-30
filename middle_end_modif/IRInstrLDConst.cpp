#include "IRInstrLDConst.h"

IRInstrLDConst::IRInstrLDConst(BasicBlock* _basicBlock, DataType _dataType, std::string _varName, int _constValue)
    : IRInstruction(_basicBlock, OperationType::ldconst, _dataType)
    , varName(_varName), constValue(_constValue)
{

}

IRInstrLDConst::~IRInstrLDConst()
{

}

void IRInstrLDConst::genAsm(ostream &o)
{

}
