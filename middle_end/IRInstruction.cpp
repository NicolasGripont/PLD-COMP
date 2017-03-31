#include "IRInstruction.h"
#include "BasicBlock.h"

IRInstruction::IRInstruction()
{
    
}

IRInstruction::IRInstruction(BasicBlock* _bb, IRInstructionType _type)
	: block(_bb), type(_type)
{

}

IRInstruction::~IRInstruction()
{
    delete block;
}

IRInstruction::IRInstructionType IRInstruction::IRInstruction::getOperation() const
{
	return type;
}

BasicBlock* IRInstruction::getBasicBlock() const
{
	return block;
}
