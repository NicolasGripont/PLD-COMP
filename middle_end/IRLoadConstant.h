#ifndef _IRLOADCONSTANT_H
#define _IRLOADCONSTANT_H

#include "IROperationWithDestination.h"
#include "Symbol.h"

class IRLoadConstant : public IROperationWithDestination
{
public:
    IRLoadConstant(Symbol * dest,int val);
    ~IRLoadConstant();

    std::string toString() const;

private:
    int value;
};

#endif // IRLOADCONSTANT_H
