#ifndef _EXPRESSIONARRAYVARIABLE_H
#define _EXPRESSIONARRAYVARIABLE_H

#include "ExpressionVariable.h"
#include "Expression.h"

class ExpressionArrayVariable : public ExpressionVariable 
{
public:

	ExpressionArrayVariable(char* _id, Expression* _expr, int _type);
	virtual ~ExpressionArrayVariable();

    virtual std::string toString() const;
	
    Expression *getExpr() const;

private:
    Expression* expr;
};

#endif
