#include "IRJump.h"

IRJump::IRJump(string lab)
	: label(lab)
{

}

std::string IRJump::getLabel() const
{
    return label;
}
