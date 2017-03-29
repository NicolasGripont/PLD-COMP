#include "IRJump.h"

IRJump::IRJump(std::string lab) : label(lab)
{

}

std::string IRJump::getLabel() const
{
    return label;
}
