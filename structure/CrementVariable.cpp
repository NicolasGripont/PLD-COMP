#include "CrementVariable.h"

CrementVariable::CrementVariable(ExpressionVariable* _exprVar, bool _increment, bool _preCrement)
	: Expression(), exprVar(_exprVar), increment(_increment), preCrement(_preCrement)
{
    setType(_exprVar->getType());
}

CrementVariable::~CrementVariable()
{

}

string CrementVariable::toString() const
{
	return "CrementVariable";
}