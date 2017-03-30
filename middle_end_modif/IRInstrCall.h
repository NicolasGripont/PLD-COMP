#ifndef IR_INSTR_CALL_H
#define IR_INSTR_CALL_H

#include <vector>
#include <string>

#include "IRInstruction.h"

class IRInstrCall : public IRInstruction
{
public:
    IRInstrCall(BasicBlock* _basicBlock, DataType _dataType,
         std::string _var, std::string _funcName, std::vector<std::string> _params);
    ~IRInstrCall();

    virtual void genAsm(ostream &o);
private:
    std::string var;
    std::string funcName;
    std::vector<std::string> params;
};

#endif
