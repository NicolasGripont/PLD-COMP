#include "IRRWMemory.h"

IRRWMemory::IRRWMemory(IRRWMemory::Type _type, const Symbol *dest, const Symbol *sour)
    : IROperationWithDestination(dest), type(_type), source(sour)
{}

IRRWMemory::~IRRWMemory()
{
    delete source;
}

std::string IRRWMemory::toString() const
{
    std::string ret;

    switch(type)
    {
        case Type::READ_MEMORY :
            ret = destination->getName() + " <- (" + source->getName() + ")";
            break;

        case Type::WRITE_MEMORY :
            ret = "(" + destination->getName() + ") <- " + source->getName();
            break;
    }

    return ret;
}

IRRWMemory::Type IRRWMemory::getType() const
{
    return type;
}

const Symbol *IRRWMemory::getSource() const
{
    return source;
}
