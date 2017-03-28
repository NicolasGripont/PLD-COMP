#ifndef _MULTIPLEDECLARATIONVARIABLE_H
#define _MULTIPLEDECLARATIONVARIABLE_H

#include <vector>

#include "DeclarationVariable.h"
#include "Type.h"
#include "Printable.h"

class MultipleDeclarationVariable : public Printable
{
public:
    MultipleDeclarationVariable();
    virtual ~MultipleDeclarationVariable();
    virtual string toString() const;
    void addDeclarationVariable(DeclarationVariable* dec);
    void setType(Type* t);
    int countDeclaration();
    Type* getType();

    DeclarationVariable*& operator[] (int i);

private:
    Type* type;
    std::vector<DeclarationVariable*> declarationsVariables;
};

#endif
