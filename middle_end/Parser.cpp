#include "Parser.h"

Parser::~Parser()
{
    for(auto item : functionCFG)
    {
        delete item.second;
    }

    for(auto item : globalSymbolTable)
    {
        delete item.second;
    }
}

void Parser::generateIR(Genesis *genesis)
{
    for(int declarationId = 0; declarationId < genesis->countDeclaration() ; ++declarationId)
    {
        Declaration* declaration = (*genesis)[declarationId];
        if(declaration->getType() == GLOBAL_DECLARATION_VARIABLE)
        {
            handleNewSymbolInTable((GlobalDeclarationVariable*)declaration);
        }
        else if (declaration->getType() == DECLARATION_FUNCTION)
        {
            generateCFG((DeclarationFunction*)declaration);
        }
    }
}

// crée les symboles liés aux nouvelles déclarations/définition et les ajoute à la table
void Parser::handleNewSymbolInTable(GlobalDeclarationVariable* declaration)
{
    MultipleDeclarationVariable* multipleDeclarationVariable;
    multipleDeclarationVariable = declaration->getMultipleDeclarationVariable();
    Symbol::Type type = Symbol::Type::INT_32; 
    switch(multipleDeclarationVariable->getType()->getType()) {
        case 1:
        type = Symbol::Type::CHAR;
        break;
        case 8:
        type = Symbol::Type::INT_64;
        break;
    }
    for(int declarationId = 0; declarationId < multipleDeclarationVariable->countDeclaration() ; ++declarationId)
    {
        DeclarationVariable* declarationVariable = (*multipleDeclarationVariable)[declarationId];
        Symbol *s = nullptr;
        if(declarationVariable->isArray()) {
            s = new Symbol(declarationVariable->getId(), Symbol::Type::PTR, offset);
        } else {    
            if(declarationVariable->isDeclaration()) {
                s = new Symbol(declarationVariable->getId(), type, offset);
            } else {
                std::cout << "Not implement yet" << std::endl;
            }
        }
        this->addSymbolToTable(s);
        offset++;
    }
}

void Parser::addNewFunctionInTable(CFG * controllFlowGraph)
{
    if(controllFlowGraph != nullptr) {
        functionCFG.insert(std::pair<std::string, CFG*>(controllFlowGraph->getName(), controllFlowGraph));
    }
}

// Génère le CFG d'une fonction et le stock dans la map des CFG
void Parser::generateCFG(DeclarationFunction * declaration)
{
    CFG * controllFlowGraph = new CFG(this,declaration);
    addNewFunctionInTable(controllFlowGraph);
}

const std::map<std::string, const Symbol *> & Parser::getGlobalSymbolTable() const
{
    return globalSymbolTable;
}

void Parser::addSymbolToTable(Symbol * symbol)
{
    if(symbol != nullptr) {
        globalSymbolTable.insert(std::pair<std::string, Symbol*>(symbol->getName(), symbol));
    }
}
