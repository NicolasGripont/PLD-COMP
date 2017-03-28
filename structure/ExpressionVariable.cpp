#include "ExpressionVariable.h"


ExpressionVariable::ExpressionVariable(int _type)
:Expression()
{
    setType(_type);
}

ExpressionVariable::~ExpressionVariable()
{

}

string ExpressionVariable::print() const
{
	return "ExpressionVariable";
}
