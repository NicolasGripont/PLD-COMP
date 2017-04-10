#include "ForLoop.h"
#include "../middle_end/CFG.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/IRConditionnal.h"

ForLoop::ForLoop(LoopExpression* _expr1, LoopExpression* _expr2, LoopExpression* _expr3, Statement* _statement)
    : IterationStatement(_statement), expr1(_expr1), expr2(_expr2), expr3(_expr3)
{

}

ForLoop::~ForLoop()
{
    if(expr1 != nullptr)
    {
        delete expr1;
    }
    if(expr2 != nullptr)
    {
        delete expr2;
    }
    if(expr3 != nullptr)
    {
        delete expr3;
    }
}

std::string ForLoop::toString() const
{
    std::string txt = "for(" + expr1->toString() + "; " + expr2->toString() + "; " + expr3->toString() + ")";
    if(statement != nullptr)
    {
        txt += statement->toString();
    }
    else
    {
        txt += "{}";
    }
    return txt;
}

void ForLoop::buildIR(CFG *cfg) const
{
    int level = cfg->getCurrentBasicBlock()->getLevel();

    //Gestion de l'initialisation de la variable index
    //l'initialisation se met dans le basic block avant celui de condition
    if(expr1 != nullptr)
    {
        expr1->buildIR(cfg);
    }

    //Gestion de la condition
    // On crée le nouveau basic block contenant la condition
    BasicBlock * bbCondition = cfg->createNewBasicBlock(level);;
    cfg->attachNewBasicBlock(bbCondition);

    Symbol * condition = nullptr;

    if(expr2 != nullptr)
    {
        expr2->buildIR(cfg);
        // On récupère le registre contenant le résultat
        condition = cfg->getLastInstructionDestination();
    }

    //Gestion du statement
    BasicBlock * bbStatement = cfg->createNewBasicBlock(level + 1,bbCondition->getLabel() + "_STATEMENT");
    cfg->attachNewBasicBlock(bbStatement);

    if(statement != nullptr)
    {
        statement->buildIR(cfg);
    }

    //Gestion de l'expression d'avancement dans la boucle
    if(expr3 != nullptr)
    {
        expr3->buildIR(cfg);
    }

    BasicBlock * bbEnd = cfg->createNewBasicBlock(level);

    bbCondition->setExitFalse(bbEnd);

    cfg->getCurrentBasicBlock()->setExitTrue(bbCondition);

    cfg->setCurrentBasicBlock(bbEnd);

    IRConditionnal * instruction = new IRConditionnal(IRConditionnal::Type::FOR, condition, bbCondition, bbEnd);
    bbCondition->addIRInstruction(instruction);
}
