#include "IRReturn.h"

IRReturn::IRReturn(Symbol * symbol) :
    IRInstruction(IRInstruction::Type::RETURN), returnValue(symbol)
{

}

std::string IRReturn::toString() const
{
    return "RETURN " + returnValue->getName();
}

Symbol *IRReturn::getReturnValue() const
{
    return returnValue;
}

