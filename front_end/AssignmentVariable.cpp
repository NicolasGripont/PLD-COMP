#include "AssignmentVariable.h"

#include "../middle_end/CFG.h"
#include "../middle_end/IROperationWithDestination.h"
#include "../middle_end/IRRWMemory.h"
#include "ExpressionArrayVariable.h"

AssignmentVariable::AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr)
    :Expression(),exprVar(_exprVar),expr(_expr)
{
    int type1 = _exprVar->getType();
    int type2 = _expr->getType();

    if(type1 == type2)
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
    if(exprVar != nullptr)
    {
        delete exprVar;
    }
    if(expr != nullptr)
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
    exprVar->buildIR(cfg);

    const Symbol * destination;

    auto pair = cfg->getCurrentBasicBlock()->getLocalSymbolsTable().find(exprVar->getId());

    if(pair != cfg->getCurrentBasicBlock()->getLocalSymbolsTable().end())
    {
        ExpressionArrayVariable* arrayVariable = dynamic_cast<ExpressionArrayVariable*>(exprVar);
        if(arrayVariable != nullptr)
        {
            std::cout << "not implemented yet ;)" << std::endl;
        }
        else
        {
            destination = pair->second;
        }


        // ON CONSTRUIT LA SOURCE
        expr->buildIR(cfg);

        const Symbol * source = cfg->getLastInstructionDestination();

        if(source != nullptr)
        {
            // ON GENERE L'INSTRUCTION
            IRRWMemory * instruction = new IRRWMemory(IRRWMemory::Type::WRITE_MEMORY,destination,source);
            cfg->addInstructionInCurrentBasicBlock(instruction);
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
