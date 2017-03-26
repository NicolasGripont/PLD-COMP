#include "../header/Declaration.h"
#include <iostream>

Declaration::Declaration()
{
    std::cout<<"Declaration - Constructor"<<std::endl;
}

Declaration::~Declaration()
{
    delete nextNode;
}
