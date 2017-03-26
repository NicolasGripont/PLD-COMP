#ifndef MULTIPLEDECLARATIONVARIABLELOCAL_H
#define MULTIPLEDECLARATIONVARIABLELOCAL_H

#include "SimpleStatement.h"
#include <vector>

using namespace std;

class MultipleDeclarationVariableLocal : public SimpleStatement
{
public:
    MultipleDeclarationVariableLocal();
    ~MultipleDeclarationVariableLocal();

    void addSimpleStatement(const SimpleStatement * simpleStatement);

private:
    vector<SimpleStatement*> listSimpleStatements;
};

#endif // MULTIPLEDECLARATIONVARIABLELOCAL_H
