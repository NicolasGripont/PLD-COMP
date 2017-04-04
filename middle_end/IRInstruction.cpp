#include "IRInstruction.h"

IRInstruction::IRInstruction(IRInstruction::Type _type)
    : type(_type)
{

}

IRInstruction::Type IRInstruction::IRInstruction::getOperation() const
{
	return type;
}
