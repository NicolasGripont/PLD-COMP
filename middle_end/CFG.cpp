#include "CFG.h"

CFG::CFG()
{

}

CFG::~CFG()
{

}

string CFG::toString() const
{

}

void
CFG::addBasicBlock
(
    BasicBlock
     *bb
)
{

}

void CFG::addSymbol(Symbol *symbol)
{

}

Symbol *CFG::getSymbol(string name)
{

}

string CFG::getUsableBasicBlockName() const
{

}

void CFG::parseGenesis(Genesis* genesis)
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
}

void CFG::parseGlobalDeclarationFunction(DeclarationFunction* DeclarationFunction)
{

}
