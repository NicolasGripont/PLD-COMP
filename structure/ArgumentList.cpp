#include "ArgumentList.h"

ArgumentList::ArgumentList() : Printer()
{

}

void ArgumentList::addArgument(Argument* arg)
{
    arguments.push_back(arg);
}

string ArgumentList::print() {
	return "ArgumentList";
}