#include "FunctionCallExpression.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IRCall.h"
#include <vector>

#include "../comp.tab.h"

FunctionCallExpression::FunctionCallExpression(char* _id, Expression* _expr, int _type)
    : Expression(), id(_id), expr(_expr)
{

    type = _type;
}

FunctionCallExpression::~FunctionCallExpression()
{
    if(id != nullptr)
    {
        free(id);
    }
    if(expr != nullptr)
    {
        delete expr;
    }
}

std::string FunctionCallExpression::toString() const
{

    std::string exprStr = "";
    if(expr != nullptr)
    {
        exprStr = expr->toString();
    }
    return std::string(id) + "(" + exprStr + ")";
}

void FunctionCallExpression::buildIR(CFG *cfg) const
{
    IRCall * instruction;

    Symbol * returnSymbol = nullptr;

    if(getType() != VOID)
    {
        returnSymbol = new Symbol(cfg->getTempVariableName(),getType(),cfg->getOffsetFromCurrentBasicBlock());
    }

    instruction = new IRCall(id,returnSymbol,getType() == VOID);

    // On ajoute les params
    if(expr != nullptr)
    {
        BinaryOperatorExpression* binaryExpr = dynamic_cast<BinaryOperatorExpression*>(expr);
        Expression * next = expr;

        std::vector<const Symbol *> vectorParameters;

        while(binaryExpr != nullptr)
        {
            vectorParameters.push_back(computeParameters(cfg,binaryExpr->getRight()));
            next = binaryExpr->getLeft();
            binaryExpr = dynamic_cast<BinaryOperatorExpression*>(binaryExpr->getLeft());
        }

        vectorParameters.push_back(computeParameters(cfg,next));

        for(int i = vectorParameters.size()-1; i >= 0; --i)
        {
            instruction->addParameter(vectorParameters[i]);
        }

    }

    cfg->addInstructionInCurrentBasicBlock(instruction);
}

const Symbol * FunctionCallExpression::computeParameters(CFG *cfg, Expression* binaryExprRight) const
{
    ExpressionVariable * variable = dynamic_cast<ExpressionVariable*>(binaryExprRight);

    const Symbol * param;
    if(variable != nullptr)
    {
        param = cfg->getCurrentBasicBlock()->getLocalSymbolsTable().find(variable->getId())->second;
    }
    else
    {
        binaryExprRight->buildIR(cfg);
        param = cfg->getLastInstructionDestination();
    }

    return param;
}
