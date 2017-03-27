#ifndef _USELESSSTATEMENT_H
#define _USELESSSTATEMENT_H

#include "SimpleStatement.h"

class UselessStatement : public SimpleStatement
{
public:
	UselessStatement();
	virtual string print();
};

#endif