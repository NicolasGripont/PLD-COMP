#include "CFG.h"

CFG::CFG(DeclarationFunction * _function) : function(_function)
{
    _function->buildIR(this);
}

CFG::CFG() : function(nullptr)
{

}

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

void CFG::addBasicBlock(BasicBlock *bb)
{
    if(bb != nullptr) {
        blocks.push_back(bb);
    }
}

void CFG::addSymbol(Symbol *symbol)
{
    if(symbol != nullptr) {
        localSymbolsTable.insert(std::pair<std::string, Symbol*>(symbol->getName(), symbol));
    }
}

const Symbol* CFG::getSymbol(std::string name) const
{
    auto it = localSymbolsTable.find(name);
    if (it != localSymbolsTable.end())
        return it->second;
    else
        return nullptr;
}

std::string CFG::getName() const {
    if(function != nullptr)
        return function->getId();
    return "undefined";
}

std::string CFG::getUsableBasicBlockName() const
{
    return "not_implemented";
}

const std::map <std::string, Symbol*> & CFG::getLocalSymbolsTable() const
{
    return localSymbolsTable;
}

const std::vector<BasicBlock *> &CFG::getBasicBlocks() const
{
    return blocks;
}
