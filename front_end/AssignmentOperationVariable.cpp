#include "AssignmentOperationVariable.h"
#include "../comp.tab.h"

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

    switch(op)
    {
    case MUL_ASSIGN:
        break;
    case DIV_ASSIGN:

        break;
    case MOD_ASSIGN:

        break;
    case PLUS_ASSIGN:

        break;
    case MINUS_ASSIGN:

        break;
    case LEFT_DEC_ASSIGN:

        break;
    case RIGHT_DEC_ASSIGN:

        break;
    case AND_ASSIGN:

        break;
    case OR_ASSIGN:

        break;
    case OR_EXCL_ASSIGN:

        break;
    }
}


