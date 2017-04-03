#ifndef _EXPRESSIONVARIABLE_H
#define _EXPRESSIONVARIABLE_H

#include "Expression.h"

class ExpressionVariable : public Expression
{
public:
    ExpressionVariable(char* _id, int _type);
    virtual ~ExpressionVariable();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

    const char *getId() const;

protected:
    char* id;
};

#endif
