#ifndef IR_INSTR_LE_H
#define IR_INSTR_LE_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrLe : public IRInstrThreeOp
{
public:
    IRInstrLe(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrLe();

    virtual void genAsm(ostream &o);
private:

};

#endif
