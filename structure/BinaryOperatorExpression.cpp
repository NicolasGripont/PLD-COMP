#include "BinaryOperatorExpression.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op)

	:Expression(),expr1(_expr1),expr2(_expr1),op(_op)
{
    if(_expr1->getType() == _expr2->getType())
    {
        setType(_expr1->getType());
    }
    else if (op != ',')
    {
        setType(EXPRESSION_TYPE_CONFLICT);
    }
}

BinaryOperatorExpression::~BinaryOperatorExpression()
{

}

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op, int _type)
    :Expression(),expr1(_expr1),expr2(_expr1),op(_op)
{
    setType(_type);
}

string BinaryOperatorExpression::print() const
{
	return "BinaryOperatorExpression";
}
