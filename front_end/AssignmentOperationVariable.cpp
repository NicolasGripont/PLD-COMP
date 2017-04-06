#include "AssignmentOperationVariable.h"
#include "../comp.tab.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IRBinaryOp.h"

AssignmentOperationVariable::AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op)
    : AssignmentVariable(_exprVar,_expr), op(_op)
{

}

AssignmentOperationVariable::~AssignmentOperationVariable()
{

}

std::string AssignmentOperationVariable::toString() const
{
    std::string txt = exprVar->toString();

    switch(op)
    {
    case MUL_ASSIGN:
        txt += " *= ";
        break;
    case DIV_ASSIGN:
        txt += " /= ";
        break;
    case MOD_ASSIGN:
        txt += " %= ";
        break;
    case PLUS_ASSIGN:
        txt += " += ";
        break;
    case MINUS_ASSIGN:
        txt += " -= ";
        break;
    case LEFT_DEC_ASSIGN:
        txt += " <<= ";
        break;
    case RIGHT_DEC_ASSIGN:
        txt += " >>= ";
        break;
    case AND_ASSIGN:
        txt += " &= ";
        break;
    case OR_ASSIGN:
        txt += " |= ";
        break;
    case OR_EXCL_ASSIGN:
        txt += " ^= ";
        break;
    default:
        return "ERROR_AssignmentOperationVariable";
    }
    return txt + expr->toString();
}

void AssignmentOperationVariable::buildIR(CFG *cfg) const
{
    Symbol * symbol = cfg->getCurrentBasicBlock()->getSymbol(this->exprVar->getId());
    if(symbol != nullptr)
    {
            expr->buildIR(cfg);
            Symbol * source = cfg->getLastInstructionDestination();
            IRBinaryOp * instruction = nullptr;
            switch(op)
            {
            case MUL_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::MUL,symbol,symbol,source);
                break;
            case DIV_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::DIV,symbol,symbol,source);
                break;
            case MOD_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::MOD,symbol,symbol,source);
                break;
            case PLUS_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::ADD,symbol,symbol,source);
                break;
            case MINUS_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::SUB,symbol,symbol,source);
                break;
            case LEFT_DEC_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::LEFT_DEC,symbol,symbol,source);
                break;
            case RIGHT_DEC_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::RIGHT_DEC,symbol,symbol,source);
                break;
            case AND_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::AND,symbol,symbol,source);
                break;
            case OR_ASSIGN:
                instruction = new IRBinaryOp(IRBinaryOp::Type::OR,symbol,symbol,source);
                break;
            case OR_EXCL_ASSIGN:
                std::cout << "OR_EXCL_ASSIGN not implemented" << std::endl;
                break;
            }

            if(instruction != nullptr)
            {
                cfg->addInstructionInCurrentBasicBlock(instruction);
            }
    }
}


