#include "WhileLoop.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/IRConditionnal.h"

WhileLoop::WhileLoop(Expression* _expr, Statement* _statement)
	: IterationStatement(_statement), expr(_expr)
{

}

WhileLoop::~WhileLoop()
{
	if(expr != nullptr) 
	{
		delete expr;
	}
}

std::string WhileLoop::toString() const
{
	std::string txt = "while(" + expr->toString() + ")";
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

void WhileLoop::buildIR(CFG *cfg) const
{
    // On crée le nouveau basic block contenant la condition
    int level = cfg->getCurrentBasicBlock()->getLevel();

    BasicBlock * bbCondition = cfg->createNewBasicBlock(level);
    cfg->attachNewBasicBlock(bbCondition);

    // On récupère le registre contenant le résultat
    expr->buildIR(cfg);
    Symbol * result = cfg->getLastInstructionDestination();

    BasicBlock * bbStatement = cfg->createNewBasicBlock(level + 1,bbCondition->getLabel() + "_STATEMENT");
    cfg->attachNewBasicBlock(bbStatement);

    if(statement != nullptr)
    {
        statement->buildIR(cfg);
    }

    BasicBlock * bbEnd = cfg->createNewBasicBlock(level);
    cfg->attachNewBasicBlock(bbEnd);

    cfg->setCurrentBasicBlock(bbEnd);

    IRConditionnal * instruction = new IRConditionnal(IRConditionnal::Type::WHILE, result, bbCondition, bbEnd);
    bbCondition->addIRInstruction(instruction);
}
