#ifndef IR_INSTR_LD_CONST_H
#define IR_INSTR_LD_CONST_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrAdd : public IRInstrThreeOp
{
public:
    IRInstrAdd(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrAdd();

    virtual void genAsm(ostream &o);
private:

};

#endif
