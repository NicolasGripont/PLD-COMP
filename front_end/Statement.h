#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "MultipleStatement.h"
#include "Printable.h"

class Statement : public Printable, public IRTranslatable
{
public:
    Statement(MultipleStatement* _multipleStatement);
    virtual ~Statement();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;
    MultipleStatement* getMultipleStatement();

private:
    MultipleStatement* multipleStatement;
};

#endif
