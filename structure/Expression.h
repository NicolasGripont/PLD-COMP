#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printer.h"
#include "DataType.h"


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
