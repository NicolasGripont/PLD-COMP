#include "Parser.h"

Parser::~Parser()
{
    for(auto item : functionCFG)
    {
        delete item.second;
    }

    for(auto item : symbolTable)
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
            addNewSymbolsInTable((GlobalDeclarationVariable*)declaration);
        }
        else if (declaration->getType() == DECLARATION_FUNCTION)
        {
            generateCFG((DeclarationFunction*)declaration);
        }
    }
}

// crée les symboles liés aux nouvelles déclarations/définition et les ajoute à la table
void Parser::addNewSymbolsInTable(GlobalDeclarationVariable* declaration)
{

}

// Génère le CFG d'une fonction et le stock dans la map des CFG
CFG Parser::generateCFG(DeclarationFunction * declaration)
{
    CFG controllFlowGraph = new CFG();


}

