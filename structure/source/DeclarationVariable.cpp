#include "../header/DeclarationVariable.h"
#include <iostream>

DeclarationVariable::DeclarationVariable()
{
    std::cout<<"DeclarationVariable - Constructor"<<std::endl;
}

DeclarationVariable::~DeclarationVariable()
{
    delete variable;
}
