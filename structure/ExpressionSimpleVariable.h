#ifndef _EXPRESSIONSIMPLEVARIABLE_H
#define _EXPRESSIONSIMPLEVARIABLE_H

#include "ExpressionVariable.h"

class ExpressionSimpleVariable : public ExpressionVariable 
{
public:

	ExpressionSimpleVariable(char* _id, int _type);
	virtual ~ExpressionSimpleVariable();
	virtual string toString() const;

private:
	char* id;
};

#endif
