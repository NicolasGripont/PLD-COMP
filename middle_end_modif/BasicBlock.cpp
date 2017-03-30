#include "BasicBlock.h"
#include "CFG.h"

BasicBlock::BasicBlock(CFG *_cfg, string _entryLabel) : cfg(_cfg), entryLabel(_entryLabel)
{
}

void BasicBlock::genAsm(ostream &o)
{
}

void BasicBlock::addIRInstr(IRInstruction *instr)
{
    instrs.push_back(instr);
}