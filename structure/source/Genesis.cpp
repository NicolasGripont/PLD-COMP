#include "../header/Genesis.h"
#include <iostream>

Genesis::Genesis()
{
    std::cout<<"Genesis - Constructor"<<std::endl;
}

Genesis::~Genesis()
{
    for(auto decl : declarations)
    {
        delete decl;
    }
}

void Genesis::addDeclaration(const Declaration *dec)
{
    declarations.push_back(dec);
}
