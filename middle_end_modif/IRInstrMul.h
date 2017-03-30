#ifndef IR_INSTR_MUL_H
#define IR_INSTR_MUL_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrMul : public IRInstrThreeOp
{
public:
    IRInstrMul(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrMul();

    virtual void genAsm(ostream &o);
private:

};

#endif
