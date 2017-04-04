#ifndef IROPERATIONWITHDESTINATION
#define IROPERATIONWITHDESTINATION

#include "IRInstruction.h"

class IROperationWithDestination : public IRInstruction
{
public:
    IROperationWithDestination(IRInstruction::Type type, Symbol * dest) : IRInstruction(type),destination(dest) {}
    ~IROperationWithDestination() { delete destination; }

    Symbol * getDestination() const { return destination; }

protected :
    Symbol * destination;
};



#endif // IROPERATIONWITHDESTINATION

