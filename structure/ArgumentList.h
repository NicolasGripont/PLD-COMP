#ifndef _ARGUMENTLIST_H
#define _ARGUMENTLIST_H

#include <vector>

#include "Argument.h"
#include "Printer.h"


class ArgumentList : public Printer
{
public:
    ArgumentList();
    virtual string print() const;
    void addArgument(Argument* arg);
    int countArguments();
    Argument*& operator[] (int i);
    
private:
    std::vector<Argument*> arguments;
};

#endif
