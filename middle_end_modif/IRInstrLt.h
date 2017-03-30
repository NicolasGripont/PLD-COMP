#ifndef IR_INSTR_LT_H
#define IR_INSTR_LT_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrLt : public IRInstrThreeOp
{
public:
    IRInstrLt(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrLt();

    virtual void genAsm(ostream &o);
private:

};

#endif
