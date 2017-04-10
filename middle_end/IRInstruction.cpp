#include "IRInstruction.h"

IRInstruction::IRInstruction(IRInstruction::Operation _op)
    : type(_op)
{

}

IRInstruction::Operation IRInstruction::IRInstruction::getOperation() const
{
	return type;
}
