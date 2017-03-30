#include <cassert>

#include "../comp.tab.h"

#include "CFG.h"
#include "BasicBlock.h"
#include "SymbolGlobalVariable.h"

CFG::CFG()
{
}

void CFG::parseAst(Genesis *ast)
{
    nextBBnumber = 0;
    nextFreeSymbolIndex = 0;
    nextTmpVarNumber = 1;

    for (int declarationId = 0; declarationId < ast->countDeclaration(); ++declarationId)
    {
        Declaration *declaration = (*ast)[declarationId];
        if (declaration->getType() == GLOBAL_DECLARATION_VARIABLE)
        {
            parseGlobalDeclarationVariable((GlobalDeclarationVariable *)declaration);
        }
        else if (declaration->getType() == DECLARATION_FUNCTION)
        {
            parseGlobalDeclarationFunction((DeclarationFunction *)declaration);
        }
    }
}

void CFG::parseGlobalDeclarationVariable(GlobalDeclarationVariable *globalDeclarationVariable)
{
    MultipleDeclarationVariable *multipleDeclarationVariable;
    multipleDeclarationVariable = globalDeclarationVariable->getMultipleDeclarationVariable();
    DataType dataType = dataTypeFromInt(multipleDeclarationVariable->getType()->getType());

    for (int declarationId = 0; declarationId < multipleDeclarationVariable->countDeclaration(); ++declarationId)
    {
        DeclarationVariable *declarationVariable = (*multipleDeclarationVariable)[declarationId];
        std::string varName = declarationVariable->getId();
        SymbolGlobalVariable *globalVariable = new SymbolGlobalVariable(varName, dataType);

        variables[varName] = globalVariable;
    }
}

void CFG::parseGlobalDeclarationFunction(DeclarationFunction *DeclarationFunction)
{
}

void CFG::addBB(BasicBlock *bb)
{
    bbs.push_back(bb);
}

std::string CFG::IRRegToAsm(std::string reg)
{
}

void CFG::genAsmPrologue(std::ostream &o)
{
}

void CFG::genAsmEpilogue(std::ostream &o)
{
}

std::string CFG::createNewTempvar(DataType dataType)
{
    //std::string varName = "!tmp"+nextTmpVarNumber;
    //++nextTmpVarNumber;
    //addToSymbolTable(varName, dataType);
}

std::string CFG::newBBName()
{
    std::string name = "basic_block_" + nextBBnumber;
    ++nextBBnumber;
    return name;
}

Genesis *CFG::getAst()
{
    return ast;
}

BasicBlock *CFG::getCurrentBB()
{
    return currentBB;
}

DataType CFG::dataTypeFromInt(int type)
{
    switch (type)
    {
    case CHAR:
        return DataType::INT8;
    case INT32:
        return DataType::INT32;
    case INT64:
    default:
        return DataType::INT64;
    }
}