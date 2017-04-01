#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "Printable.h"
#include "IRTranslatable.h"
#include "Enumeration.h"
#include "ExpressionType.h"

const int EXPRESSION_TYPE_UNDEFINED = -1;
const int EXPRESSION_TYPE_CONFLICT = -2;

class Expression : public Printable, IRTranslatable
{
public:
    Expression();
    virtual ~Expression();

    void buildIR(CFG * cfg) const;

    int getType();
    void setType(int _type);

    int getExpressionType();
    void setExpressionType(int _type);

protected:
    int type;
    int expressionType;
};

#endif
