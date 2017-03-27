#ifndef _EXPRESSIONINTEGER_H
#define _EXPRESSIONINTEGER_H

#include "Expression.h"

class ExpressionInteger : public Expression 
{
public:
	ExpressionInteger(int _value);

private:
	int value;
};

#endif