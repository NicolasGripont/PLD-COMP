#ifndef _MULTIPLESTATEMENT_H
#define _MULTIPLESTATEMENT_H

#include <vector>

#include "SimpleStatement.h"
#include "Printable.h"

class MultipleStatement : public Printable, IRTranslatable
{
public:
    MultipleStatement();
    virtual ~MultipleStatement();

    std::string toString() const;
    void buildIR(CFG * cfg) const;

    void addStatement(SimpleStatement* statement);
    int countStatements();

    SimpleStatement*& operator[] (int i);

private:
    std::vector<SimpleStatement*> statements;
};

#endif
