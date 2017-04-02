#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printable.h"
#include "IRTranslatable.h"
#include "Enumeration.h"
#include "ExpressionType.h"

const int EXPRESSION_TYPE_UNDEFINED = -1;
const int EXPRESSION_TYPE_CONFLICT = -2;

class Expression : public Printable, public IRTranslatable
{
public:
    Expression();
    virtual ~Expression() = default;

    int getType() const;
    void setType(int _type);

    int getExpressionType();
    void setExpressionType(int _type);

protected:
    int type;
    int expressionType;
};

#endif
