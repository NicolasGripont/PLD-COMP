#ifndef IR_INSTR_IF_H
#define IR_INSTR_IF_H

#include "IRInstruction.h"

class IRInstrIf : public IRInstruction {
public:
	IRInstrIf(BasicBlock* _basicBlock, std::string _reg, std::string _label1, std::string _label2);
    ~IRInstrIf();

	virtual void genAsm(ostream &o);
private:
    std::string reg;
	std::string label1;
    std::string label2;
};

#endif
