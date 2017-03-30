#ifndef IR_INSTR_THREE_OP_H
#define IR_INSTR_THREE_OP_H

#include <vector>

#include "IRInstrTwoOp.h"

class IRInstrThreeOp : public IRInstrTwoOp
{
public:
    IRInstrThreeOp(BasicBlock* _basicBlock, OperationType opType, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrThreeOp();

    virtual void genAsm(ostream &o) = 0;
private:
    std::string var3;
};

#endif
