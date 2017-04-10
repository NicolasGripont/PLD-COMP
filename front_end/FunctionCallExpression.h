#ifndef _FUNCTIONCALLEXPRESSION_H
#define _FUNCTIONCALLEXPRESSION_H

#include "Expression.h"
#include "../middle_end/Symbol.h"

class FunctionCallExpression : public Expression 
{
public:
    FunctionCallExpression(char* _id, Expression* _expr, int _type);
	virtual ~FunctionCallExpression();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;
	
private:
	char* id;
    // Peut etre nullptr si la fonction ne prend pas de parametres
	Expression* expr;

    Symbol * computeParameters(CFG * cfg, Expression* binaryExpr) const;
};

#endif
