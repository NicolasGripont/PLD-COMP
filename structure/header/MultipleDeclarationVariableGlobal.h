#ifndef MULTIPLEDECLARATIONVARIABLEGLOBAL_H
#define MULTIPLEDECLARATIONVARIABLEGLOBAL_H

#include "Declaration.h"
#include "MultipleDeclarationVariableLocal.h"
#include "DeclarationVariable.h"
#include "TypeDeclaration.h"

#include <vector>
using namespace std;

class MultipleDeclarationVariableGlobal : public Declaration
{
public:
    MultipleDeclarationVariableGlobal(Type atype);
    ~MultipleDeclarationVariableGlobal();

    void addVariableDeclaration(DeclarationVariable* declaration);

private:
    vector<DeclarationVariable*> variableDeclarations;

    Type type;

};

#endif // MULTIPLEDECLARATIONVARIABLEGLOBAL_H
