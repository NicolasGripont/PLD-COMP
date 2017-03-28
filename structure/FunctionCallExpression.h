#ifndef _FUNCTIONCALLEXPRESSION_H
#define _FUNCTIONCALLEXPRESSION_H

#include "Expression.h"

class FunctionCallExpression : public Expression 
{
public:

	FunctionCallExpression(char* _id, Expression* _expr, int _type);
	virtual ~FunctionCallExpression();
	virtual string print() const;
	
private:
	char* id;
    // Peut etre nullptr si la fonction ne prend pas de parametres
	Expression* expr;
};

#endif
