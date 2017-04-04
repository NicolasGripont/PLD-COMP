#ifndef IROPERATIONWITHDESTINATION
#define IROPERATIONWITHDESTINATION

#include "IRInstruction.h"

class IROperationWithDestination : public IRInstruction
{
public:
    IROperationWithDestination(IRInstruction::Type type, const Symbol * dest) : IRInstruction(type),destination(dest) {}
    ~IROperationWithDestination() { delete destination; }

    const Symbol * getDestination() const { return destination; }

protected :
    const Symbol * destination;
};



#endif // IROPERATIONWITHDESTINATION

