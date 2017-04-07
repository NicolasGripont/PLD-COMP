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
    std::vector<Symbol *> vectorParameters;
    // On ajoute les params
    if(expr != nullptr)
    {
        BinaryOperatorExpression* binaryExpr = dynamic_cast<BinaryOperatorExpression*>(expr);
        Expression * next = expr;

        while(binaryExpr != nullptr)
        {
            if(binaryExpr->getType() != COMMA)
            {
                next = binaryExpr;
                binaryExpr = nullptr;
            }
            else
            {
                vectorParameters.push_back(computeParameters(cfg,binaryExpr->getRight()));
                next = binaryExpr->getLeft();
                binaryExpr = dynamic_cast<BinaryOperatorExpression*>(binaryExpr->getLeft());
            }
        }
        vectorParameters.push_back(computeParameters(cfg,next));
    }

    IRCall * instruction;
    Symbol * returnSymbol = nullptr;

    if(getType() != VOID)
    {
        returnSymbol = new Symbol(cfg->getTempVariableName(),getType(),cfg->getOffsetFromCurrentBasicBlock());
    }

    instruction = new IRCall(id,returnSymbol,vectorParameters,getType() == VOID);

    cfg->addInstructionInCurrentBasicBlock(instruction);

    std::cout << "ERROR buildIR FunctionCallExpression " << std::endl;

}

Symbol * FunctionCallExpression::computeParameters(CFG *cfg, Expression* binaryExprRight) const
{   
    binaryExprRight->buildIR(cfg);
    return cfg->getLastInstructionDestination();;
}
