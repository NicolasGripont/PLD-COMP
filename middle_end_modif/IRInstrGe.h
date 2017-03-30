#ifndef IR_INSTR_GE_H
#define IR_INSTR_GE_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrGe : public IRInstrThreeOp
{
public:
    IRInstrGe(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrGe();

    virtual void genAsm(ostream &o);
private:

};

#endif
