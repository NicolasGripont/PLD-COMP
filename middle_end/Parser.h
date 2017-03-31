#ifndef _PARSER_H
#define _PARSER_H

#include "CFG.h"
#include "Genesis.h"
#include "Symbol.h"

#include <map>
#include <vector>
#include <string>

class Parser
{
public:
    Parser() = default;
    ~Parser();

    void generateIR(Genesis * genesis);

    void addNewSymbolsInTable(GlobalDeclarationVariable *declaration);

    void generateCFG(DeclarationFunction * declaration);

private:

    std::map <std::string, Symbol*> symbolTable;
    std::map<std::string,CFG*> functionCFG;     //std::map<nom_de_fonction, CFG_de_la_fonction>

};

#endif // _PARSER_H
