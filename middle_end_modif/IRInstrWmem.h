#ifndef IR_INSTR_WMEM_H
#define IR_INSTR_WMEM_H

#include <vector>

#include "IRInstrTwoOp.h"

class IRInstrWmem : public IRInstrTwoOp
{
public:
    IRInstrWmem(BasicBlock* _basicBlock, DataType _dataType, std::string _var1, std::string _var2);
    ~IRInstrWmem();

    virtual void genAsm(ostream &o);
private:

};

#endif
