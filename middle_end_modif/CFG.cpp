#include <cassert>

#include "../comp.tab.h"
#include "../front_end/DeclarationInitVariable.h"

#include "CFG.h"
#include "BasicBlock.h"
#include "SymbolGlobalVariable.h"
#include "SymbolLocalVariable.h"
#include "SymbolFunction.h"
#include "IRInstrLDConst.h"

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

    // Pour chaque variable globale déclarée
    for (int declarationId = 0; declarationId < multipleDeclarationVariable->countDeclaration(); ++declarationId)
    {
        DeclarationVariable *declarationVariable = (*multipleDeclarationVariable)[declarationId];
        std::string varName = declarationVariable->getId();
        SymbolGlobalVariable *globalVariable = new SymbolGlobalVariable(varName, dataType);

        variables[varName] = globalVariable;

        // Si la partie droite est une expression
        if (!(declarationVariable->isDeclaration()))
        {
            DeclarationInitVariable *declarationInitVariable = (DeclarationInitVariable *)declarationVariable;
            Expression *expr = declarationInitVariable->getExpr();
            parseExpression(expr, globalVariable);
        }
    }
}

void CFG::parseExpression(Expression *expr, SymbolVariable *symbol)
{
    IRInstruction *instr;
    // Si l'expression de droite est une constante, on peut l'assigner directement
    if (expr->getType() == EXPRESSION_INTEGER)
    {
        ExpressionInteger *exprInt = (ExpressionInteger *)expr;
        int value = exprInt->getValue();
        std::string varName = symbol->getName();
        DataType dataType = symbol->getDataType();

        // Instruction LD Const
        instr = new IRInstrLDConst(currentBB, dataType, varName, value);
    }
    else
    {
        /// TODO : Calculer l'expression et l'assigner à la variable
    }
    currentBB->addIRInstr(instr);
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
    std::string varName = "!tmp" + nextTmpVarNumber;
    ++nextTmpVarNumber;
    /// TODO : Remplacer le memory_location du SymbolLocalVariable
    SymbolLocalVariable *var = new SymbolLocalVariable(varName, dataType, -1);
    variables[varName] = var;
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