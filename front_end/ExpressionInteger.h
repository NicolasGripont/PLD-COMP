#ifndef _EXPRESSIONINTEGER_H
#define _EXPRESSIONINTEGER_H

#include "Expression.h"

class ExpressionInteger : public Expression 
{
public:
	ExpressionInteger(int _value, int _type);
	virtual ~ExpressionInteger();
	virtual string toString() const;

private:
	int value;
};

#endif
