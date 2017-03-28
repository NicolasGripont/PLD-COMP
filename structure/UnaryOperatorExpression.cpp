#include "UnaryOperatorExpression.h"
#include "../comp.tab.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr, int _op)
	:Expression(),expr(_expr),op(_op)
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

string UnaryOperatorExpression::toString() const
{
	string exprStr = "(";
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
