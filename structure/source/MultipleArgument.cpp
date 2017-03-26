#include "../header/MultipleArgument.h"
#include <iostream>

MultipleArgument::MultipleArgument()
{
    std::cout<<"MultipleArgument - Constructor"<<std::endl;
}

MultipleArgument::~MultipleArgument()
{
    for(auto arg : listArguments)
    {
        delete arg;
    }
}

void MultipleArgument::addArgument(Argument *arg)
{
    listArguments.push_back(arg);
}
