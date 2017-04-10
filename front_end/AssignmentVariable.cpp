#include "AssignmentVariable.h"

#include "../middle_end/CFG.h"
#include "../middle_end/IROperationWithDestination.h"
#include "../middle_end/IRRWMemory.h"
#include "../middle_end/IRRWMemoryArray.h"
#include "../middle_end/IRLoadConstant.h"
#include "../middle_end/IRBinaryOp.h"
#include "ExpressionArrayVariable.h"

AssignmentVariable::AssignmentVariable(ExpressionVariable *_exprVar, Expression *_expr)
    : Expression(), exprVar(_exprVar), expr(_expr)
{
    int type1 = _exprVar->getType();
    int type2 = _expr->getType();

    if (type1 == type2)
    {
        setType(type1);
    }
    else if (isArrayType(type1) != isArrayType(type2))
    {
        setType(EXPRESSION_TYPE_CONFLICT);
    }
    else
    {
        setType(type1);
    }
}

AssignmentVariable::~AssignmentVariable()
{
    if (exprVar != nullptr)
    {
        delete exprVar;
    }
    if (expr != nullptr)
    {
        delete expr;
    }
}

std::string AssignmentVariable::toString() const
{
    return exprVar->toString() + " = " + expr->toString();
}

void AssignmentVariable::buildIR(CFG *cfg) const
{
    
    Symbol *destination;

    auto pair = cfg->getCurrentBasicBlock()->getLocalSymbolsTable().find(exprVar->getId());

    if (pair != cfg->getCurrentBasicBlock()->getLocalSymbolsTable().end())
    {
        ExpressionArrayVariable *arrayVariable = dynamic_cast<ExpressionArrayVariable *>(exprVar);
        destination = pair->second;

        // ON CONSTRUIT LA SOURCE
        expr->buildIR(cfg);

        Symbol *source = cfg->getLastInstructionDestination();

        if (source != nullptr)
        {
            // ON GENERE L'INSTRUCTION
            if (arrayVariable != nullptr)
            {
                arrayVariable->getExpr()->buildIR(cfg);
                Symbol *target = cfg->getLastInstructionDestination();

                // Multiplier la position par -1 (car les positions du tableau remontent dans l'AR)
                std::string tmpName = cfg->getTempVariableName();
                Symbol *negativeSymbol = new Symbol(tmpName, getType(), cfg->getOffsetFromCurrentBasicBlock());
                IRLoadConstant *instructionLoadNeg = new IRLoadConstant(negativeSymbol, -1);
                cfg->addInstructionInCurrentBasicBlock(instructionLoadNeg);

                IRBinaryOp *multInstruction = new IRBinaryOp(IRBinaryOp::Type::MUL, target, target, negativeSymbol);
                cfg->addInstructionInCurrentBasicBlock(multInstruction);
                
                IRRWMemoryArray *instruction = new IRRWMemoryArray(IRRWMemoryArray::Type::WRITE_MEMORY, destination, source, target);
                cfg->addInstructionInCurrentBasicBlock(instruction);
            }
            else
            {
                exprVar->buildIR(cfg);

                IRRWMemory *instruction = new IRRWMemory(IRRWMemory::Type::WRITE_MEMORY, destination, source);
                cfg->addInstructionInCurrentBasicBlock(instruction);
            }
        }
    }
    else
    {
        std::cout << "Error : variable not found in local symbol table" << std::endl;
    }
}

/// gestion tableau
//            arrayVariable->getExpr()->buildIR(cfg);

//            // On doit récupérer le résultat de l'expression et donc la derière instruction.
//            const IROperationWithDestination * irOp = dynamic_cast<const IROperationWithDestination*>
//                    (cfg->getCurrentBasicBlock()->getInstructions().back());

//            if(irOp != nullptr)
//            {
//                destination = irOp->getDestination();
//            }
