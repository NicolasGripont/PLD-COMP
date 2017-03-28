#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op)

	:Expression(),expr1(_expr1),expr2(_expr1),op(_op)
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
    return "";
#warning Ligne a completer !
    //return expr1->toString() +  + expr2->toString();
}
