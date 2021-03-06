#ifndef _EXPRESSIONINTEGER_H
#define _EXPRESSIONINTEGER_H

#include "Expression.h"

class ExpressionInteger : public Expression 
{
public:
	ExpressionInteger(int _value, int _type);
	virtual ~ExpressionInteger();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

	int getValue();
private:
	int value;
};

#endif
