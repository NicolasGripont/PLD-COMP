#include "BasicBlock.h"
#include "CFG.h"
#include "IRInstruction.h"

BasicBlock::BasicBlock(CFG *_cfg, std::string _entry_label)
    : cfg(_cfg), label(_entry_label)
{
    localSymbolsTable = cfg->getSymbolsTable();

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

void BasicBlock::addIRInstruction(IRInstruction* instruction)
{
    if (instruction != nullptr)
    {
	instructions.push_back(instruction);
    }
}

const BasicBlock *BasicBlock::getExitTrue() const
{
    return exit_true;
}

const BasicBlock *BasicBlock::getExitFalse() const
{
    return exit_false;
}

const std::string &BasicBlock::getLabel() const
{
    return label;
}

const CFG *BasicBlock::getCFG() const
{
    return cfg;
}

const std::vector<IRInstruction *> &BasicBlock::getInstructions() const
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

int BasicBlock::getPrologMaximalOffset() const
{
    // Pour nos tests, 3 variables de 8 octets
    return 3*8;
}

const std::map<std::string, const Symbol *> &BasicBlock::getLocalSymbolsTable() const
{
    return localSymbolsTable;
}

void BasicBlock::addLocalSymbol(const Symbol * sym)
{
    localSymbolsTable.insert(std::pair<std::string,const Symbol *>(sym->getName(), sym));
}

