#include "BasicBlock.h"
#include "CFG.h"
#include "IRInstruction.h"

BasicBlock::BasicBlock(int lvl, CFG *_cfg, std::string _entry_label)
    : cfg(_cfg), label(_entry_label), level(lvl), indexTempVariable(0)
{
    // Si on est au premier niveau on prend les globaux
    if(lvl == 0)
    {
        localSymbolsTable = cfg->getSymbolsTable();
    }
    // sinon on va prendre le context d'avant (qui contiendra donc les globaux)
    else
    {
        auto previousContextSymbolTable = cfg->getSymbolTableFromLevel(lvl);

        // Si on est pas le premier bloc du niveau, on prend le context d'avant
        if(previousContextSymbolTable != nullptr)
        {
            for(auto pair : *previousContextSymbolTable)
            {
                localSymbolsTable.insert(pair);
            }
        }
        // Sinon on prend le context du niveau d'au dessus
        else
        {
            auto previousContextSymbolTable = cfg->getSymbolTableFromLevel(lvl - 1);

            if(previousContextSymbolTable != nullptr)
            {
                for(auto pair : *previousContextSymbolTable)
                {
                    localSymbolsTable.insert(pair);
                }
            }
        }
    }
    exit_true = nullptr;
    exit_false = nullptr;
}

BasicBlock::~BasicBlock()
{
    for(auto & instr : instructions)
    {
        delete instr;
    }

    for(auto & pair : localSymbolsTable)
    {
        delete pair.second;
    }

    delete exit_true;
    delete exit_false;
}

std::string BasicBlock::toString() const
{
    std::string ret = " ________" + this->getLabel() + "\n/\n";

    for(const IRInstruction * inst : instructions)
    {
        ret += inst->toString() + "\n";
    }

    return ret + "____________________\n\n";
}

void BasicBlock::addIRInstruction(const IRInstruction* instruction)
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

const std::string &BasicBlock::getLabel() const
{
    return label;
}

const CFG *BasicBlock::getCFG() const
{
    return cfg;
}

const std::vector<const IRInstruction *> & BasicBlock::getInstructions() const
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

std::string BasicBlock::getTempVariableName()
{
    return label + "_tmp_" + std::to_string(indexTempVariable++);
}

int BasicBlock::getPrologMaximalOffset() const
{
    // Pour nos tests, 3 variables de 8 octets
    return 3*8;
}

const std::map<const std::string, const Symbol *> &BasicBlock::getLocalSymbolsTable() const
{
    return localSymbolsTable;
}

void BasicBlock::addLocalSymbol(const Symbol * sym)
{
    localSymbolsTable.insert(std::pair<std::string,const Symbol *>(sym->getName(), sym));
}

int BasicBlock::getLevel() const
{
    return level;
}
