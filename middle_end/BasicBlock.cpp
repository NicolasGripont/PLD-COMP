#include "BasicBlock.h"
#include "CFG.h"
#include "IRInstruction.h"

BasicBlock::BasicBlock(CFG *_cfg, std::string _entry_label)
    : cfg(_cfg), label(_entry_label)
{
    exit_true = nullptr;
    exit_false = nullptr;
}

BasicBlock::~BasicBlock()
{
}

std::string BasicBlock::toString() const
{
    return "";
}

void BasicBlock::addIRInstruction(IRInstruction *instruction)
{
    if (instruction != nullptr)
    {
	instructions.push_back(instruction);
    }
}

BasicBlock *BasicBlock::getExitTrue() const
{
    return exit_true;
}

BasicBlock *BasicBlock::getExitFalse() const
{
    return exit_false;
}

std::string BasicBlock::getLabel() const
{
    return label;
}

CFG *BasicBlock::getCFG() const
{
    return cfg;
}

std::vector<IRInstruction *> BasicBlock::getInstructions() const
{
    return instructions;
}

void BasicBlock::setExitTrue(BasicBlock *_bbExitTrue)
{
    exit_true = _bbExitTrue;
}

void BasicBlock::setExitFalse(BasicBlock *_bbExitFalse)
{
    exit_false = _bbExitFalse;
}