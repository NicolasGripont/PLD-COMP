#include "AssignmentOperationVariable.h"
#include "../comp.tab.h"

AssignmentOperationVariable::AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op)
	: AssignmentVariable(_exprVar,_expr), op(_op)
{

}

AssignmentOperationVariable::~AssignmentOperationVariable()
{

}

string AssignmentOperationVariable::toString() const
{
    string txt = exprVar->toString();

    string typeStr = "(";
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
    return txt + expr->toString() + ")";
}



