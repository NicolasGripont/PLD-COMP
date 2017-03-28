#include "BinaryOperatorExpression.h"
#include "../comp.tab.h"


BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op)

	:Expression(),expr1(_expr1),expr2(_expr2),op(_op)
{
    int type1 = _expr1->getType();
    int type2 = _expr2->getType();

    if (isArrayType(type1) != isArrayType(type2))
    {
        setType(EXPRESSION_TYPE_CONFLICT);
    }
    else if(sizeOfType(type1) > sizeOfType(type2))
    {
        setType(type1);
    }
    else
    {
        setType(type2);
    }
}

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op, int _type)
    :Expression(),expr1(_expr1),expr2(_expr2),op(_op)
{
    setType(_type);
}

BinaryOperatorExpression::~BinaryOperatorExpression()
{
    delete expr1;
    delete expr2;
}

string BinaryOperatorExpression::toString() const
{
    string txt = expr1->toString();

    string typeStr = "";
    switch(op)  
    {  
        case MUL:  
            txt += " * ";  
            break;  
        case DIV:  
            txt += " / ";  
            break; 
        case MOD:  
            txt += " % ";  
            break;  
        case PLUS:  
            txt += " + ";  
            break;  
        case MINUS:  
            txt += " - ";  
            break;  
        case AND:
            txt += " & ";  
            break; 
        case OR:  
            txt += " | ";  
            break;  
        case POW:  
            txt += " ^ ";  
            break;  
        case LEFT_DEC:  
            txt += " << ";  
            break;  
        case RIGHT_DEC:  
            txt += " >> ";  
            break;  
        default:  
            return "ERROR_AssignmentOperationVariable";  
    }  
    return txt + expr2->toString();
}
