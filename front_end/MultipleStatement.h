#ifndef _MULTIPLESTATEMENT_H
#define _MULTIPLESTATEMENT_H

#include <vector>

#include "SimpleStatement.h"
#include "IRTranslatable.h"
#include "Printable.h"

class MultipleStatement : public Printable, public IRTranslatable
{
public:
    MultipleStatement();
    virtual ~MultipleStatement();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

    void addStatement(SimpleStatement* statement);
    int countStatements();

    SimpleStatement*& operator[] (int i);

    const std::vector<SimpleStatement*> & getStatements();

private:
    std::vector<SimpleStatement*> statements;
};

#endif
