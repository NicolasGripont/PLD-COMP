#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printable.h"
#include "Enumeration.h"
#include "ExpressionType.h"

const int EXPRESSION_TYPE_UNDEFINED = -1;
const int EXPRESSION_TYPE_CONFLICT = -2;

class Expression : public Printable
{
protected:
    int type;
    int expressionType;
public:
    Expression();
    virtual ~Expression();
	virtual string toString() const = 0;

    int getType();
    void setType(int _type);

    int getExpressionType();
    void setExpressionType(int _type);
};

#endif
