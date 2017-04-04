#include "IRLoadConstant.h"

IRLoadConstant::IRLoadConstant(Symbol *dest, int val) :
    IROperationWithDestination(IRInstruction::Type::LOAD_CONSTANT, dest), value(val)
{}

IRLoadConstant::~IRLoadConstant()
{
    delete destination;
}

std::string IRLoadConstant::toString() const
{
    return destination->getName() + " <- " + std::to_string(value);
}

