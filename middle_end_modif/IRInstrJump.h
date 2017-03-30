#ifndef IR_INSTR_JUMP_H
#define IR_INSTR_JUMP_H

#include "IRInstruction.h"

class IRInstrJump : public IRInstruction {
public:
	IRInstrJump(BasicBlock* _basicBlock, std::string _label);
    ~IRInstrJump();

	virtual void genAsm(ostream &o);
private:
    std::string label;
};

#endif
