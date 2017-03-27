#include "CrementVariable.h"

CrementVariable::CrementVariable(ExpressionVariable* _exprVar, bool _increment, bool _preCrement)
	: Expression(), exprVar(_exprVar), increment(_increment), preCrement(_preCrement)
{

}

string CrementVariable::print() const
{
	return "CrementVariable";
}