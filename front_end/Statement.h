#ifndef _STATEMENT_H
#define _STATEMENT_H

#include "MultipleStatement.h"
#include "Printable.h"

class Statement : public Printable
{
public:
    Statement(MultipleStatement* _multipleStatement);
    virtual ~Statement();
    virtual std::string toString() const;

private:
    MultipleStatement* multipleStatement;
};

#endif