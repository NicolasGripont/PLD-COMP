#include "CFG.h"

#include "../front_end/Genesis.h"
#include "../front_end/Declaration.h"
#include "../front_end/GlobalDeclarationVariable.h"
#include "../front_end/DeclarationFunction.h"

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
//    std::string s = "";
//    for(BasicBlock * bb : blocks)
//    {
//        s += bb->toString();
//        s += "\n";
//    }
    return "not implemented";
}

BasicBlock * CFG::createNewBasicBlock(int level, const std::string &bbName)
{
    BasicBlock * bb = new BasicBlock(level,this,bbName);
    setlastBasicBlockFromLevel(level,bb);
    return bb;
}


BasicBlock * CFG::createNewBasicBlock(int level)
{
    BasicBlock * bb = new BasicBlock(level,this,getUsableBasicBlockName());
    setlastBasicBlockFromLevel(level,bb);
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

const std::map<std::string, const Symbol *> * CFG::getSymbolTableFromLevel(int level) const
{
    auto bb = lastBasicBlockbyLevel.find(level);
    if(bb == lastBasicBlockbyLevel.end())
        return nullptr;

    return &(bb->second->getLocalSymbolsTable());

}

void CFG::setlastBasicBlockFromLevel(int level, BasicBlock *block)
{
    lastBasicBlockbyLevel.insert(std::pair<int, BasicBlock *>(level,block));
}

const std::map <std::string, const Symbol*> & CFG::getSymbolsTable() const
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
    return "BB_" + std::to_string(nextBBnumber++);
}

void CFG::setCurrentBasicBlock(BasicBlock *bb)
{
    currentBasicBlock = bb;
}

void CFG::setCurrentBasicBlockExitTrue(BasicBlock *bb)
{
    currentBasicBlock->setExitTrue(bb);
}

void CFG::setCurrentBasicBlockExitFalse(BasicBlock *bb)
{
    currentBasicBlock->setExitFalse(bb);
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

