#ifndef _EXPRESSIONSIMPLEVARIABLE_H
#define _EXPRESSIONSIMPLEVARIABLE_H

#include "ExpressionVariable.h"

class ExpressionSimpleVariable : public ExpressionVariable 
{
public:

	ExpressionSimpleVariable(char* _id, int _type);
	virtual ~ExpressionSimpleVariable();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

private:
	char* id;
};

#endif
