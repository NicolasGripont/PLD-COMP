#ifndef IR_INSTR_RMEM_H
#define IR_INSTR_RMEM_H

#include <vector>

#include "IRInstrTwoOp.h"

class IRInstrRmem : public IRInstrTwoOp
{
public:
    IRInstrRmem(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2);
    ~IRInstrRmem();

    virtual void genAsm(ostream &o);
private:

};

#endif
