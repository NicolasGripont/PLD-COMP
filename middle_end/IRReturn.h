#ifndef _IRRETURN_H
#define _IRRETURN_H

#include "IRInstruction.h"

class IRReturn : public IRInstruction
{
public:
    IRReturn(Symbol * symbol);
    ~IRReturn() = default;

    std::string toString() const;

    Symbol *getReturnValue() const;

private:
    Symbol * returnValue;
};

#endif // _IRRETURN_H
