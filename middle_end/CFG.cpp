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

CFG::~CFG()
{
    for(auto bb : blocks)
        delete bb;
}

std::string CFG::toString() const
{
    std::string s = "";
    for(BasicBlock * bb : blocks) {
        s += bb->toString();
        s += "\n";
    }
    return s;
}

BasicBlock * CFG::createNewBasicBlock(const std::string &bbName)
{
    BasicBlock * bb = new BasicBlock(this,bbName);
    addBasicBlock(bb);
    return bb;
}


BasicBlock * CFG::createNewBasicBlock()
{
    BasicBlock * bb = new BasicBlock(this,getUsableBasicBlockName());
    addBasicBlock(bb);
    return bb;
}

void CFG::addBasicBlock(BasicBlock *bb)
{
    if(bb != nullptr) {
        blocks.push_back(bb);
    }
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

const std::map <std::string, const Symbol*> & CFG::getSymbolsTable() const
{
    return symbolsTable;
}

const std::vector<BasicBlock *> &CFG::getBasicBlocks() const
{
    return blocks;
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
