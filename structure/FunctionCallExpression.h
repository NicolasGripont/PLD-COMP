#ifndef _FUNCTIONCALLEXPRESSION_H
#define _FUNCTIONCALLEXPRESSION_H

#include "Expression.h"

class FunctionCallExpression : public Expression 
{
public:
	FunctionCallExpression(char* _id, Expression* _expr);
	virtual string print();
	
private:
	char* id;
	Expression* expr;
};

#endif