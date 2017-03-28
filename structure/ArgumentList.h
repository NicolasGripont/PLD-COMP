#ifndef _ARGUMENTLIST_H
#define _ARGUMENTLIST_H

#include <vector>

#include "Argument.h"
#include "Printable.h"


class ArgumentList : public Printable
{
public:
    ArgumentList();
    virtual ~ArgumentList();
    virtual string toString() const;
    void addArgument(Argument* arg);
    int countArguments();
    Argument*& operator[] (int i);
    
private:
    std::vector<Argument*> arguments;
};

#endif
