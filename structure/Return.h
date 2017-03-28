#ifndef _RETURN_H
#define _RETURN_H

#include "Expression.h"
#include "Printer.h"

class Return : public Printer
{
public:
	Return(Expression* _expr);
	virtual ~Return();
	virtual string print() const;

private:
	Expression* expr;
};

#endif