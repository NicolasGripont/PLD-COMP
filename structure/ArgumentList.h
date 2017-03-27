#ifndef _ARGUMENTLIST_H
#define _ARGUMENTLIST_H

#include <vector>

#include "Argument.h"
#include "Printer.h"


class ArgumentList : public Printer
{
public:
    ArgumentList();
    void addArgument(Argument* arg);
    virtual string print();
    
private:
    std::vector<Argument*> arguments;
};

#endif