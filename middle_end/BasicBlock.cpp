#include "BasicBlock.h"
#include "IRInstruction.h"
#include "IROperationWithDestination.h"

BasicBlock::BasicBlock(int lvl, CFG *_cfg, std::string _entry_label)
    : cfg(_cfg), label(_entry_label), level(lvl), indexTempVariable(0)
{
    // Si on est au premier niveau on prend les globaux
    if(lvl == 0)
    {
        localSymbolsTable = cfg->getSymbolsTable();
    }
    // sinon on va prendre le contexte d'avant (qui contiendra donc les globaux)
    else
    {
        auto levelData = cfg->getLevelData(lvl);

        // Si on est le premier bloc du niveau, on build par rapport au niveau n - 1
        if(levelData == nullptr)
        {
            this->buildFromUpperLevelData();
        }
        // Sinon on build avec les data du niveau
        else
        {
            this->buildFromLevelData(levelData);
        }
    }

    cfg->setLastBasicBlockFromLevel(level,this);

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

    for(IRInstruction * inst : instructions)
    {
        ret += inst->toString() + "\n";
    }

    return ret + "____________________\n\n";
}

void BasicBlock::addIRInstruction(IRInstruction* instruction)
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

const std::vector<IRInstruction *> & BasicBlock::getInstructions() const
{
    return instructions;
}

Symbol *BasicBlock::getLastInstructionDestination()
{
    IROperationWithDestination * irOp = dynamic_cast<IROperationWithDestination*>
            (instructions.back());

    if(irOp != nullptr)
    {
        return irOp->getDestination();
    }
    else
    {
        return nullptr;
    }
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
    // TODO: rendre générique
    return 3*8;
}

const std::map<std::string, Symbol *> &BasicBlock::getLocalSymbolsTable() const
{
    return localSymbolsTable;
}

void BasicBlock::addLocalSymbol(Symbol * sym)
{
    localSymbolsTable.insert(std::pair<std::string, Symbol *>(sym->getName(), sym));
}

Symbol* BasicBlock::getSymbol(std::string name) const
{
    Symbol * symbol = nullptr;
    symbol = localSymbolsTable.find(name)->second;
    return symbol;
}

int BasicBlock::getLevel() const
{
    return level;
}

// Privates functions
void BasicBlock::buildFromUpperLevelData()
{
    auto levelData = cfg->getLevelData(level - 1);

    if(levelData != nullptr)
    {
        buildFromLevelData(levelData);

        cfg->addNewLevelData(level, this);
    }
    else
    {
        std::cout << "Error BasicBlock::buildWithUpperLevelData levelData : " << std::to_string(level-1) << std::endl;
    }

}

void BasicBlock::buildFromLevelData(const CFG::LevelData* data)
{
    for(auto symbole : data->lastBasicBlock->getLocalSymbolsTable())
    {
        localSymbolsTable.insert(symbole);
    }
}
