#ifndef IR_INSTR_TWO_OP_H
#define IR_INSTR_TWO_OP_H

#include <vector>

#include "IRInstruction.h"

class IRInstrTwoOp : public IRInstruction
{
public:
    IRInstrTwoOp(BasicBlock* _basicBlock, OperationType opType, DataType _dataType,
         std::string _var1, std::string _var2);
    ~IRInstrTwoOp();

    virtual void genAsm(ostream &o) = 0;
private:
    std::string var1;
    std::string var2;
};

#endif
