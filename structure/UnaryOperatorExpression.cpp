#include "UnaryOperatorExpression.h"

UnaryOperatorExpression::UnaryOperatorExpression(Expression* _expr, int _op)
	:expr(_expr),op(_op),Expression()
{

}