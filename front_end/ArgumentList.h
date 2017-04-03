#ifndef _ARGUMENTLIST_H
#define _ARGUMENTLIST_H

#include <vector>

#include "Printable.h"
#include "IRTranslatable.h"
#include "Argument.h"

class ArgumentList : public Printable, public IRTranslatable
{
public:
    ArgumentList();
    virtual ~ArgumentList();

    virtual std::string toString() const;
    virtual void buildIR(CFG * cfg) const;

    void addArgument(Argument* arg);
    int countArguments();
    Argument*& operator[] (int i);

    const std::vector<Argument *>& getArguments() const;

private:
    std::vector<Argument*> arguments;
};

#endif
