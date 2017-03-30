#ifndef IR_INSTR_LD_CONST_H
#define IR_INSTR_LD_CONST_H

#include <vector>

#include "IRInstruction.h"

class IRInstruction;

class IRInstrLDConst : public IRInstruction
{
public:
    IRInstrLDConst(BasicBlock* _basicBlock, DataType _dataType, std::string _varName, int _constValue);
    ~IRInstrLDConst();

    virtual void genAsm(ostream &o);
private:
    std::string varName;
    int constValue;
};

#endif
