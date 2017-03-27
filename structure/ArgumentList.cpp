#include "ArgumentList.h"

ArgumentList::ArgumentList()
{

}

void ArgumentList::addArgument(Argument* arg)
{
    arguments.push_back(arg);
}