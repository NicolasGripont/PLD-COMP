#ifndef IR_INSTR_DIV_H
#define IR_INSTR_DIV_H

#include <vector>

#include "IRInstrThreeOp.h"

class IRInstrDiv : public IRInstrThreeOp
{
public:
    IRInstrDiv(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var1, std::string _var2, std::string _var3);
    ~IRInstrDiv();

    virtual void genAsm(ostream &o);
private:

};

#endif
