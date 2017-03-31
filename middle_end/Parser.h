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
    void addNewSymbolInTable(GlobalDeclarationVariable *declaration);
    void addNewFunctionInTable(CFG *controllFlowGraph);
    void generateCFG(DeclarationFunction * declaration);
    void parseFunctionStatement(BasicBlock* prologue, BasicBlock* epilogue, InitFunctionStatement *statement);
private:
	void addSymbolToTable(Symbol* symbol);
    std::map <std::string, Symbol*> symbolTable;
    std::map<std::string,CFG*> functionCFG;     //std::map<nom_de_fonction, CFG_de_la_fonction>
    int offset = 0;
};

#endif // _PARSER_H
