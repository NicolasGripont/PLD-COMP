#ifndef MULTIPLESTATEMENT_H
#define MULTIPLESTATEMENT_H

#include "Statement.h"
#include <vector>

using namespace std;

class MultipleStatement : public Statement
{
public:
    MultipleStatement();
    ~MultipleStatement();

    void addStatement(Statement *state);

private:
    vector<Statement*> listStatements;
};

#endif // MULTIPLESTATEMENT_H
