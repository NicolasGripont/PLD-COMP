#ifndef _ARGUMENTLIST_H
#define _ARGUMENTLIST_H

#include <vector>

#include "Argument.h"

class ArgumentList
{
public:
    ArgumentList();

    void addArgument(Argument* arg);
    int countArguments();

    Argument*& operator[] (int i);
private:
    std::vector<Argument*> arguments;
};

#endif
