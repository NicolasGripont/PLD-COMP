#include "CrementVariable.h"
#include "../middle_end/Symbol.h"
#include "../middle_end/IRBinaryOp.h"
#include "../middle_end/IRLoadConstant.h"
#include "../middle_end/CFG.h"

CrementVariable::CrementVariable(ExpressionVariable* _exprVar, bool _increment, bool _preCrement)
	: Expression(), exprVar(_exprVar), increment(_increment), preCrement(_preCrement)
{
    setType(_exprVar->getType());
}

CrementVariable::~CrementVariable()
{
	if(exprVar != nullptr) 
    {
        delete exprVar;
    }
}

std::string CrementVariable::toString() const
{
	std::string crement = "";
	std::string txt = "";
	if(increment) 
	{
		crement = "++";
	}
	else 
	{
		crement = "--";
	}

	if(preCrement) 
	{
		txt = crement + exprVar->toString();
	}
	else 
	{
		txt = exprVar->toString() + crement;
	}

    return txt;
}

void CrementVariable::buildIR(CFG *cfg) const
{

    Symbol * variableToIncrment = cfg->getCurrentBasicBlock()->getLocalSymbolsTable().find(exprVar->getId())->second;


    if(variableToIncrment != nullptr)
    {
        Symbol * constant = new Symbol(cfg->getTempVariableName(),getType(),cfg->getOffsetFromCurrentBasicBlock());

        IRLoadConstant * prepConstant = new IRLoadConstant(constant,1);

        cfg->addInstructionInCurrentBasicBlock(prepConstant);

        IRBinaryOp * instruction;

        if(increment)
        {
            instruction = new IRBinaryOp(IRBinaryOp::Type::ADD,variableToIncrment,variableToIncrment,constant);
        }
        else
        {
            instruction = new IRBinaryOp(IRBinaryOp::Type::SUB,variableToIncrment,variableToIncrment,constant);
        }

        cfg->addInstructionInCurrentBasicBlock(instruction);
    }
    else
    {
        std::cout << "Error : crement build IR" << std::endl;
    }
}
