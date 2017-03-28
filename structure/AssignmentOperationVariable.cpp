#include "AssignmentOperationVariable.h"

AssignmentOperationVariable::AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op)
	: AssignmentVariable(_exprVar,_expr), op(_op)
{

}

AssignmentOperationVariable::~AssignmentOperationVariable()
{}

string AssignmentOperationVariable::print() const
{
    string txt = exprVar->print();

    string typeStr = "";
	// switch(type)  
 //      {  
 //        case TOKEN_MUL_ASSIGN:  
 //            txt += " *= ";  
 //            break;  
 //        case TOKEN_DIV_ASSIGN:  
 //            txt += " /= ";  
 //            break; 
 //        case TOKEN_MOD_ASSIGN:  
 //            txt += " %= ";  
 //            break;  
 //        case TOKEN_PLUS_ASSIGN:  
 //            txt += " += ";  
 //            break;  
 //        case TOKEN_MINUS_ASSIGN:  
 //            txt += " -= ";  
 //            break;  
 //        case TOKEN_LEFT_DEC_ASSIGN:  
 //            txt += " <<= ";  
 //            break; 
 //        case TOKEN_RIGHT_DEC_ASSIGN:  
 //            txt += " >>= ";  
 //            break;  
 //        case TOKEN_AND_ASSIGN:  
 //            txt += " &= ";  
 //            break;  
 //        case TOKEN_OR_ASSIGN:  
 //            txt += " |= ";  
 //            break;  
 //        case TOKEN_OR_EXCL_ASSIGN:  
 //            txt += " ^= ";  
 //            break;  
 //        default:  
 //            return "ERROR_AssignmentOperationVariable";  
 //      }  
    return txt + expr->print();
}



