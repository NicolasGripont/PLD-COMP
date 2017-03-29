#include "CrementVariable.h"

CrementVariable::CrementVariable(ExpressionVariable* _exprVar, bool _increment, bool _preCrement)
	: Expression(), exprVar(_exprVar), increment(_increment), preCrement(_preCrement)
{
    setType(_exprVar->getType());
}

CrementVariable::~CrementVariable()
{
    delete exprVar;
}

string CrementVariable::toString() const
{
	string crement = "";
	string txt = "";
	if(increment) 
	{
		crement = "++";
	}
	else 
	{
		crement = "--";
	}

	if(preCrement) 
	{
		txt = crement + exprVar->toString();
	}
	else 
	{
		txt = exprVar->toString() + crement;
	}

	return txt;
}
