#include "IRReturn.h"

IRReturn::IRReturn(Symbol * symbol) :
    IRInstruction(IRInstruction::Operation::RETURN), returnValue(symbol)
{

}

std::string IRReturn::toString() const
{
    if(returnValue != nullptr)
    {
        return "RETURN " + returnValue->getName();
    }
    else
    {
        return "RETURN ";
    }
}

Symbol *IRReturn::getReturnValue() const
{
    return returnValue;
}

