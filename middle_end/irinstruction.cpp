#include "IRInstruction.h"

IRInstruction::IRInstruction(BasicBlock* _bb, IR_Operation _op) : block(_bb), operation(_op), type(_t) {

}

IRInstruction::~IRInstruction() {

}

string IRInstruction::toString() const
{

}

Type IRInstruction::getType() const {
	return type;
}

Operation IRInstruction::getOperation() const {
	return operation;
}

BasicBlock* IRInstruction::getBasicBlock() const {
	return block;
}
