#include "IRRWMemoryArray.h"

IRRWMemoryArray::IRRWMemoryArray(IRRWMemoryArray::Type _type, Symbol *dest, Symbol *sour, Symbol *_targetPosition)
    : IROperationWithDestination(IRInstruction::Operation::RWMEMORYARRAY, dest), type(_type), source(sour), targetPosition(_targetPosition)
{
}

IRRWMemoryArray::~IRRWMemoryArray()
{
    delete source;
}

std::string IRRWMemoryArray::toString() const
{
    std::string ret;

    switch (type)
    {
    case Type::READ_MEMORY:
        ret = destination->getName() + " <- (" + source->getName() + ")[" + targetPosition->getName() + "]";
        break;

    case Type::WRITE_MEMORY:
        ret = "(" + destination->getName() + ")[" + targetPosition->getName() + "] <- " + source->getName();
        break;
    }

    return ret;
}

IRRWMemoryArray::Type IRRWMemoryArray::getType() const
{
    return type;
}

Symbol *IRRWMemoryArray::getTargetPosition() const
{
    return targetPosition;
}

Symbol *IRRWMemoryArray::getSource() const
{
    return source;
}
