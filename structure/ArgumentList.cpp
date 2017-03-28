#include "ArgumentList.h"

ArgumentList::ArgumentList() : Printer()
{

}

ArgumentList::~ArgumentList()
{

}

void ArgumentList::addArgument(Argument* arg)
{
    arguments.push_back(arg);
}

string ArgumentList::print() const
{
	return "ArgumentList";
}

int ArgumentList::countArguments()
{
    return arguments.size();
}

Argument*& ArgumentList::operator[] (int i)
{
    return arguments[i];
}
