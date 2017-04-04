#include "CFG.h"

#include "../front_end/Genesis.h"
#include "../front_end/Declaration.h"
#include "../front_end/GlobalDeclarationVariable.h"
#include "../front_end/DeclarationFunction.h"

#include "IRInstruction.h"
#include "BasicBlock.h"
#include "Parser.h"

CFG::CFG(const Parser * parser, DeclarationFunction * _function) :
    function(_function), currentBasicBlock(nullptr), nextBBnumber(0)
{
    symbolsTable = parser->getGlobalSymbolTable();
    _function->buildIR(this);
    nextBBnumber = 0;
}

CFG::CFG() : function(nullptr)
{}

std::string CFG::toString() const
{
    std::string s = "===== " + this->getName() + " =====\n";

    BasicBlock * current = rootBasicBlock;

    while(current != currentBasicBlock)
    {
        s += current->toString();
        current = current->getExitTrue();
    }

    s += current->toString();

    return s;
}

BasicBlock * CFG::createNewBasicBlock(int level, const std::string &bbName)
{
    BasicBlock * bb = new BasicBlock(level,this,bbName);
    setLastBasicBlockFromLevel(level,bb);
    return bb;
}


BasicBlock * CFG::createNewBasicBlock(int level)
{
    BasicBlock * bb = new BasicBlock(level,this,getUsableBasicBlockName());
    setLastBasicBlockFromLevel(level,bb);
    return bb;
}

void CFG::addSymbol(Symbol *symbol)
{
    if(symbol != nullptr) {
        symbolsTable.insert(std::pair<std::string, Symbol*>(symbol->getName(), symbol));
    }
}

const Symbol* CFG::getSymbol(std::string name) const
{
    auto it = symbolsTable.find(name);
    if (it != symbolsTable.end())
        return it->second;
    else
        return nullptr;
}

const std::map<const std::string, const Symbol *> * CFG::getSymbolTableFromLevel(int level) const
{
    auto bb = lastBasicBlockbyLevel.find(level);
    if(bb == lastBasicBlockbyLevel.end())
        return nullptr;

    return &(bb->second->getLocalSymbolsTable());

}

void CFG::setLastBasicBlockFromLevel(int level, BasicBlock *block)
{
    lastBasicBlockbyLevel.insert(std::pair<int, BasicBlock *>(level,block));
}

const std::map <const std::string, const Symbol*> & CFG::getSymbolsTable() const
{
    return symbolsTable;
}

std::string CFG::getName() const {
    if(function != nullptr)
        return function->getId();
    return "undefined";
}

std::string CFG::getUsableBasicBlockName()
{
    return this->getName() + "_BB_" + std::to_string(nextBBnumber++);
}

void CFG::setCurrentBasicBlock(BasicBlock *bb)
{
    currentBasicBlock = bb;
}

const BasicBlock * CFG::getCurrentBasicBlock() const
{
    return currentBasicBlock;
}

const Symbol *CFG::getLastInstructionDestination()
{
    return currentBasicBlock->getLastInstructionDestination();
}

int CFG::getOffsetFromCurrentBasicBlock() const
{
    return currentBasicBlock->getLocalSymbolsTable().size();
}

std::string CFG::getTempVariableName()
{
    return currentBasicBlock->getTempVariableName();
}

void CFG::addSymbolToCurrentBasicBlock(const Symbol *symbole)
{
    currentBasicBlock->addLocalSymbol(symbole);
}

void CFG::setCurrentBasicBlockExitTrue(BasicBlock *bb)
{
    currentBasicBlock->setExitTrue(bb);
}

void CFG::setCurrentBasicBlockExitFalse(BasicBlock *bb)
{
    currentBasicBlock->setExitFalse(bb);
}

void CFG::addInstructionInCurrentBasicBlock(const IRInstruction *instruction)
{
    currentBasicBlock->addIRInstruction(instruction);
}

void CFG::attachNewBasicBlock(BasicBlock *block)
{
    setCurrentBasicBlockExitTrue(block);
    setCurrentBasicBlock(block);
}

void CFG::setRootBasicBlock(BasicBlock *block)
{
    rootBasicBlock = block;
}

const BasicBlock *CFG::getRootBasicBlock() const
{
    return rootBasicBlock;
}

