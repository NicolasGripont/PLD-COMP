#include "CFG.h"

CFG::CFG()
{

}

CFG::~CFG()
{

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
        globalSymbolsTable.insert(std::pair<std::string, Symbol*>(symbol->getName(), symbol));
    }
}

Symbol* CFG::getSymbol(std::string name)
{
    std::map<std::string,Symbol *>::iterator it;
    it = globalSymbolsTable.find(name);
    if (it != globalSymbolsTable.end())
        return it->second;
    else 
        return nullptr;
}

std::string CFG::getUsableBasicBlockName() const
{

}

std::map <std::string, Symbol*> CFG::getGlobalSymbolsTable() const {
    return globalSymbolsTable;
}
    
std::vector <BasicBlock*> CFG::getBasicBlocks() const {
    return blocks;
}

void CFG::parseAST(Genesis* genesis)
{
    for(int declarationId = 0; declarationId < genesis->countDeclaration() ; ++declarationId)
    {
        Declaration* declaration = (*genesis)[declarationId];
        if(declaration->getType() == GLOBAL_DECLARATION_VARIABLE)
        {
            parseGlobalDeclarationVariable((GlobalDeclarationVariable*)declaration);
        }
        else if (declaration->getType() == DECLARATION_FUNCTION)
        {
            parseGlobalDeclarationFunction((DeclarationFunction*)declaration);
        }
    }
}

void CFG::parseGlobalDeclarationVariable(GlobalDeclarationVariable* globalDeclarationVariable)
{
    MultipleDeclarationVariable* multipleDeclarationVariable;
    multipleDeclarationVariable = globalDeclarationVariable->getMultipleDeclarationVariable();

    for(int declarationId = 0; declarationId < multipleDeclarationVariable->countDeclaration() ; ++declarationId)
    {
        DeclarationVariable* declarationVariable = (*multipleDeclarationVariable)[declarationId];
    }
}

void CFG::parseGlobalDeclarationFunction(DeclarationFunction* DeclarationFunction)
{

}
