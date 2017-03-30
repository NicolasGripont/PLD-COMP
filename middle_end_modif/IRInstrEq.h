#ifndef IR_INSTR_EQ_H
#define IR_INSTR_EQ_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrEq : public IRInstrThreeOp
{
public:
    IRInstrEq(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrEq();

    virtual void genAsm(ostream &o);
private:

};

#endif
