#ifndef _RETURN_H
#define _RETURN_H

#include "Expression.h"

class Return
{
public:
	Return(Expression* _expr);

private:
	Expression* expr;
};

#endif