#ifndef _EXPRESSIONARRAYVARIABLE_H
#define _EXPRESSIONARRAYVARIABLE_H

#include "ExpressionVariable.h"
#include "Expression.h"

class ExpressionArrayVariable : public ExpressionVariable 
{
public:
	ExpressionArrayVariable(char* _id, Expression* _expr);
	virtual string print();
	
private:
	char* id;
	Expression* expr;
};

#endif