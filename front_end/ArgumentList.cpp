#include "ArgumentList.h"

ArgumentList::ArgumentList() : Printable()
{

}

ArgumentList::~ArgumentList()
{
    for (unsigned int i = 0; i < arguments.size(); ++i)
    {
        if(arguments[i] != nullptr)
        {
            delete arguments[i];
        }
    }
}

void ArgumentList::addArgument(Argument* arg)
{
    arguments.push_back(arg);
}

std::string ArgumentList::toString() const
{
    std::string txt = "";

    if (!arguments.empty())
    {
        txt = arguments.at(0)->toString();
    }
    for (unsigned int i = 1; i < arguments.size(); ++i)
    {
        txt += ", " + arguments.at(i)->toString();
    }

    return txt;
}

int ArgumentList::countArguments()
{
    return arguments.size();
}

Argument*& ArgumentList::operator[] (int i)
{
    return arguments[i];
}
