#include "ArgumentList.h"

ArgumentList::ArgumentList()
{

}

void ArgumentList::addArgument(Argument* arg)
{
    arguments.push_back(arg);
}

int ArgumentList::countArguments()
{
    return arguments.size();
}

Argument*& ArgumentList::operator[] (int i)
{
    return arguments[i];
}
