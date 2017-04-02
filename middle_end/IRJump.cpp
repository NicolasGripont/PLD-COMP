#include "IRJump.h"

IRJump::IRJump(std::string lab) : label(lab)
{

}

std::string IRJump::toString() const
{
    return "JUMP " + label;
}

std::string IRJump::getLabel() const
{
    return label;
}
