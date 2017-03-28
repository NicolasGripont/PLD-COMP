#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printer.h"

const int EXPRESSION_TYPE_UNDEFINED = -1;
const int EXPRESSION_TYPE_CONFLICT = -2;
const int CHAR_ARRAY = -3;
const int INT32_ARRAY = -4;
const int INT64_ARRAY = -5;

class Expression : public Printer
{
protected:
    int type;
public:
    Expression();
    virtual ~Expression();
	virtual string print() const;
    int getType();
    void setType(int _type);
};

#endif
