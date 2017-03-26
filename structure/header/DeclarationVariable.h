#ifndef DECLARATIONVARIABLE_H
#define DECLARATIONVARIABLE_H

#include "Variable.h"
#include "Expression.h"

class DeclarationVariable : public Expression
{
public:
    DeclarationVariable();
    ~DeclarationVariable();

private:
    Variable * variable;
};

#endif // DECLARATIONVARIABLE_H
