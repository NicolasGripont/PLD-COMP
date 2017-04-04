#include "IRJump.h"

IRJump::IRJump(std::string lab) : IRInstruction(IRInstruction::Type::JUMP), label(lab)
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
