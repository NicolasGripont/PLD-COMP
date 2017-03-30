#ifndef IR_INSTR_SUB_H
#define IR_INSTR_SUB_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrSub : public IRInstrThreeOp
{
public:
    IRInstrSub(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrSub();

    virtual void genAsm(ostream &o);
private:

};

#endif
