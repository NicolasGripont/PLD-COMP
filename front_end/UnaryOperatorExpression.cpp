#include "UnaryOperatorExpression.h"
#include "../comp.tab.h"
#include "../middle_end/IRLoadConstant.h"
#include "../middle_end/IRBinaryOp.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr, int _op)
	: Expression(), expr(_expr), op(_op)
{

    type = _expr->getType();
}

UnaryOperatorExpression::~UnaryOperatorExpression()
{
	if(expr != nullptr) 
	{
		delete expr;
	}
}

std::string UnaryOperatorExpression::toString() const
{
	std::string exprStr = "(";
	switch(op){
		case PLUS:
			exprStr += '+';
			break;
		case MINUS:
			exprStr += '-';
			break;
		case NOT_BIT:
			exprStr += '~';
			break;
		case NOT:
			exprStr += '!';
			break;
		default :
			return "ERROR_UnaryOperatorExpression";

	}
	
	exprStr += expr->toString() + ")";
	
    return exprStr;
}

void UnaryOperatorExpression::buildIR(CFG *cfg) const
{
    Symbol* symbol0;
    IRLoadConstant* instruction0;
    Symbol* dest;
    IRBinaryOp* instructionMinus;
    switch(op){
        /*case PLUS:

            break;*/
        case MINUS:
            symbol0 = new Symbol(cfg->getTempVariableName(),INT64,cfg->getOffsetFromCurrentBasicBlock());
            instruction0 = new IRLoadConstant(symbol0, 0);
            cfg->addInstructionInCurrentBasicBlock(instruction0);
            expr->buildIR(cfg);
            dest = cfg->getCurrentBasicBlock()->getLastInstructionDestination();
            instructionMinus = new IRBinaryOp(IRBinaryOp::Type::SUB,dest, symbol0, dest);
            cfg->addInstructionInCurrentBasicBlock(instructionMinus);
            break;
        /*case NOT_BIT:

            break;
        case NOT:

            break;*/
        default :
            return;
    }
}
