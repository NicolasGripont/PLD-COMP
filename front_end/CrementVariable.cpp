#include "CrementVariable.h"

CrementVariable::CrementVariable(ExpressionVariable* _exprVar, bool _increment, bool _preCrement)
	: Expression(), exprVar(_exprVar), increment(_increment), preCrement(_preCrement)
{
    setType(_exprVar->getType());
}

CrementVariable::~CrementVariable()
{
	if(exprVar != nullptr) 
    {
        delete exprVar;
    }
}

std::string CrementVariable::toString() const
{
	std::string crement = "";
	std::string txt = "";
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

void CrementVariable::buildIR(CFG *cfg) const
{

}
