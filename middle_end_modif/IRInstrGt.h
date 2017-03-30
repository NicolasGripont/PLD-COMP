#ifndef IR_INSTR_GT_H
#define IR_INSTR_GT_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrGt : public IRInstrThreeOp
{
public:
    IRInstrGt(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrGt();

    virtual void genAsm(ostream &o);
private:

};

#endif
