#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include "Declaration.h"
#include "FunctionDefinition.h"
#include "TypeDeclaration.h"
#include "MultipleArgument.h"

class FunctionDeclaration : public Declaration
{
public:
    FunctionDeclaration(Type atype , MultipleArgument * args,
                        FunctionDefinition * def);
    ~FunctionDeclaration();

private:
    Type returnType;
    MultipleArgument * arguments;
    FunctionDefinition * definition;

};

#endif // FUNCTIONDECLARATION_H
