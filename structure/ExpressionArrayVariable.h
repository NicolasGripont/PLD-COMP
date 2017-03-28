#ifndef _EXPRESSIONARRAYVARIABLE_H
#define _EXPRESSIONARRAYVARIABLE_H

#include "ExpressionVariable.h"
#include "Expression.h"

class ExpressionArrayVariable : public ExpressionVariable 
{
public:

	ExpressionArrayVariable(char* _id, Expression* _expr, int _type);
	virtual ~ExpressionArrayVariable();
	virtual string print() const;
	
private:
	char* id;
	Expression* expr;
};

#endif
