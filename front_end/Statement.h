#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "MultipleStatement.h"
#include "Printable.h"

class Statement : public Printable, public IRTranslatable
{
public:
    Statement(MultipleStatement* _multipleStatement);
    virtual ~Statement();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

private:
    MultipleStatement* multipleStatement;
};

#endif
