#include "../header/FunctionDeclaration.h"
#include <iostream>

FunctionDeclaration::FunctionDeclaration(Type atype, MultipleArgument *args,
                                         FunctionDefinition *def)
    : returnType(atype), arguments(args), definition(def)
{
    std::cout<<"FunctionDeclaration - Constructor"<<std::endl;
}

FunctionDeclaration::~FunctionDeclaration()
{
    delete arguments;
    delete definition;
}
