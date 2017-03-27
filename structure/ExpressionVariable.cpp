#include "ExpressionVariable.h"


ExpressionVariable::ExpressionVariable(int _type)
:Expression()
{
    setType(_type);
}
string ExpressionVariable::print() const
{
	return "ExpressionVariable";
}
