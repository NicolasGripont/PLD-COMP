#ifndef IROPERATIONWITHDESTINATION
#define IROPERATIONWITHDESTINATION

#include "IRInstruction.h"

class IROperationWithDestination : public IRInstruction
{
public:
    IROperationWithDestination(const Symbol * dest) : destination(dest) {}
    ~IROperationWithDestination() { delete destination; }

    const Symbol * getDestination() const { return destination; }

protected :
    const Symbol * destination;
};



#endif // IROPERATIONWITHDESTINATION

