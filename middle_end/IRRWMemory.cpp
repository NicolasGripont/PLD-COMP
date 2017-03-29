#include "IRRWMemory.h"

IRRWMemory::IRRWMemory(IRRWMemory::Type _type, Symbol *sour, Symbol *dest)
    : type(_type), source(sour), destination(dest)
{

}

IRRWMemory::~IRRWMemory()
{
    delete source;
    delete destination;
}

string IRRWMemory::toString() const
{
    std::string ret;

    switch(type)
    {
        case Type::LOAD_CST :
            ret = destination->getName() + " <- const";
            break;

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
Symbol *IRRWMemory::getSource() const
{
    return source;
}

Symbol *IRRWMemory::getDestination() const
{
    return destination;
}
