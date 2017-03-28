#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printer.h"
#include "DataType.h"
#include "ExpressionType.h"

class Expression : public Printer
{
protected:
    int type;
    int expressionType;
public:
    Expression();
    virtual ~Expression();
	virtual string print() const;

    int getType();
    void setType(int _type);

    int getExpressionType();
    void setExpressionType(int _type);
};

#endif
