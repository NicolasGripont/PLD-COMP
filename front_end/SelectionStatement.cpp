#include "SelectionStatement.h"

#include "../middle_end/CFG.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/IRConditionnal.h"

#include "ExpressionVariable.h"

SelectionStatement::SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
    : SimpleStatement(SELECTION_STATEMENT), expr(_expr), stat(_stat), elseStat(_elseStat)
{

}

SelectionStatement::~SelectionStatement()
{
    if(expr != nullptr)
    {
        delete expr;
    }
    if(stat != nullptr)
    {
        delete stat;
    }
    if(elseStat != nullptr)
    {
        delete elseStat;
    }
}

std::string SelectionStatement::toString() const
{
    std::string txt = "";
    if(expr != nullptr && stat != nullptr && elseStat != nullptr)
    {
        txt += "if(" + expr->toString() + ")" + stat->toString() + " else " + elseStat->toString();
    }
    else if (expr != nullptr && stat != nullptr && elseStat == nullptr)
    {
        txt += "if(" + expr->toString() + ")" + stat->toString();
    }
    else if (expr != nullptr && stat == nullptr && elseStat == nullptr)
    {
        txt += "if(" + expr->toString() + "){}";
    }
    else
    {
        txt = "ERROR_SelectionStatement";
    }
    return txt;
}

void SelectionStatement::buildIR(CFG *cfg) const
{
    // On crée le nouveau basic block contenant la condition
    int level = cfg->getCurrentBasicBlock()->getLevel();

    BasicBlock * bbCondition = cfg->createNewBasicBlock(level);
    cfg->attachNewBasicBlock(bbCondition);

    // On récupère le registre contenant le résultat
    expr->buildIR(cfg);
    Symbol * result = cfg->getLastInstructionDestination();

    BasicBlock * bbThen = cfg->createNewBasicBlock(level + 1,bbCondition->getLabel() + "_THEN");
    cfg->attachNewBasicBlock(bbThen);

    if(stat != nullptr)
    {
        stat->buildIR(cfg);
    }

    BasicBlock * bbEnd = cfg->createNewBasicBlock(level);
    cfg->attachNewBasicBlock(bbEnd);

    if(elseStat != nullptr)
    {
        cfg->setCurrentBasicBlock(bbCondition);
        BasicBlock * bbElse = cfg->createNewBasicBlock(level + 1,bbCondition->getLabel() + "_ELSE");
        bbCondition->setExitFalse(bbElse);
        cfg->setCurrentBasicBlock(bbElse);
        elseStat->buildIR(cfg);
        cfg->getCurrentBasicBlock()->setExitTrue(bbEnd);
    }

    cfg->setCurrentBasicBlock(bbEnd);

    IRConditionnal * instruction = new IRConditionnal(IRConditionnal::Type::SELECTION, result, bbCondition, bbEnd);
    bbCondition->addIRInstruction(instruction);
}
