#ifndef IROPERATIONWITHDESTINATION
#define IROPERATIONWITHDESTINATION

#include "IRInstruction.h"

class IROperationWithDestination : public IRInstruction
{
public:
    IROperationWithDestination(Symbol * dest) : destination(dest) {}
    ~IROperationWithDestination() { delete destination; }

    Symbol * getDestination() const { return destination; }

protected :
    Symbol * destination;
};



#endif // IROPERATIONWITHDESTINATION

