#ifndef _RETURN_H
#define _RETURN_H

#include "Expression.h"
#include "Printable.h"

class Return : public Printable
{
public:
	Return(Expression* _expr);
	virtual ~Return();
	virtual std::string toString() const;

private:
	Expression* expr;
};

#endif