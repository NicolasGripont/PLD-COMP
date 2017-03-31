#include "IRInstruction.h"

IRInstruction::IRInstruction()
{
    
}

IRInstruction::IRInstruction(BasicBlock* _bb, IRInstruction::Type _type)
	: block(_bb), type(_type)
{

}

IRInstruction::~IRInstruction()
{
    delete block;
}

IRInstruction::Type IRInstruction::IRInstruction::getOperation() const
{
	return type;
}

BasicBlock* IRInstruction::getBasicBlock() const
{
	return block;
}
