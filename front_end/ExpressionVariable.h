#ifndef _EXPRESSIONVARIABLE_H
#define _EXPRESSIONVARIABLE_H

#include "Expression.h"

class ExpressionVariable : public Expression
{
public:
	ExpressionVariable(int _type);
	virtual ~ExpressionVariable();
};

#endif
