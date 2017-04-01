#ifndef _PARSER_H
#define _PARSER_H

#include "CFG.h"
#include "Symbol.h"
#include "../front_end/Genesis.h"
#include "../front_end/Declaration.h"
#include "../front_end/GlobalDeclarationVariable.h"
#include "../front_end/InitFunctionStatement.h"
#include "../front_end/DeclarationFunction.h"

#include <map>
#include <vector>
#include <string>

class Parser
{
public:
    Parser() = default;
    ~Parser();

    void generateIR(Genesis * genesis);

    const std::map<std::string, const Symbol *> &getGlobalSymbolTable() const;

private:
    void handleNewSymbolInTable(GlobalDeclarationVariable *declaration);
    void addSymbolToTable(Symbol* symbol);

    void addNewFunctionInTable(CFG *controllFlowGraph);
    void generateCFG(DeclarationFunction * declaration);

    std::map <std::string, const Symbol*> globalSymbolTable;
    std::map<std::string,CFG*> functionCFG;     //std::map<nom_de_fonction, CFG_de_la_fonction>
};

#endif // _PARSER_H
