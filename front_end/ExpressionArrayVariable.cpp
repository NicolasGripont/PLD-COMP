#include "ExpressionArrayVariable.h"

#include "../middle_end/Symbol.h"
#include "../middle_end/CFG.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/IRRWMemory.h"
#include "../middle_end/IRRWMemoryArray.h"
#include "../middle_end/IRLoadConstant.h"
#include "../middle_end/IRBinaryOp.h"

ExpressionArrayVariable::ExpressionArrayVariable(char *_id, Expression *_expr, int _type)
    : ExpressionVariable(_id, _type), expr(_expr)
{
    setExpressionType(EXPRESSION_ARRAY_VARIABLE);
}

ExpressionArrayVariable::~ExpressionArrayVariable()
{
    if (expr != nullptr)
    {
        delete expr;
    }
}

void ExpressionArrayVariable::buildIR(CFG *cfg) const
{
    Symbol *resultat = cfg->getCurrentBasicBlock()->getSymbol(id);
    if (resultat == nullptr)
    {
        std::cout << "Error : ExpressionVariable::buildIR " << std::endl;
    }
    else
    {
        IRRWMemory *instruction = new IRRWMemory(IRRWMemory::Type::READ_MEMORY, resultat, resultat);
        cfg->addInstructionInCurrentBasicBlock(instruction);

        expr->buildIR(cfg);
        Symbol *target = cfg->getLastInstructionDestination();

        // Ajouter l'offset de la première case du tableau dans les symboles
      /*  std::string tmpName = cfg->getTempVariableName();
        Symbol *constOffset = new Symbol(tmpName, getType(), cfg->getOffsetFromCurrentBasicBlock());
        IRLoadConstant *instructionLoadOffset = new IRLoadConstant(constOffset, resultat->getOffset());
        cfg->addInstructionInCurrentBasicBlock(instructionLoadOffset);*/

        // Multiplier la position par -1 (car les positions du tableau remontent dans l'AR)
        std::string tmpName = cfg->getTempVariableName();
        Symbol *negativeSymbol = new Symbol(tmpName, getType(), cfg->getOffsetFromCurrentBasicBlock());
        IRLoadConstant *instructionLoadNeg = new IRLoadConstant(negativeSymbol, -1);
        cfg->addInstructionInCurrentBasicBlock(instructionLoadNeg);

        IRBinaryOp *multInstruction = new IRBinaryOp(IRBinaryOp::Type::MUL, target, target, negativeSymbol);
        cfg->addInstructionInCurrentBasicBlock(multInstruction);

        // SymbolAccessArray *arrayAccessSymbol = new Symbol(tmpName, getType(), target);
        IRRWMemoryArray* instructionArr = new IRRWMemoryArray(IRRWMemoryArray::Type::READ_MEMORY, target, resultat, target);
        cfg->addInstructionInCurrentBasicBlock(instructionArr);

        instruction = new IRRWMemory(IRRWMemory::Type::READ_MEMORY, target, target);
        cfg->addInstructionInCurrentBasicBlock(instruction);
    }
}

std::string ExpressionArrayVariable::toString() const
{
    return std::string(id) + "[" + expr->toString() + "]";
}

Expression *ExpressionArrayVariable::getExpr() const
{
    return expr;
}
