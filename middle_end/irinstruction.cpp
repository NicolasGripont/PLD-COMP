#include "IRInstruction.h"

IRInstruction::IRInstruction(BasicBlock* _bb, Operation _op, Type _t) : block(_bb), operation(_op), type(_t) {

}

IRInstruction::~IRInstruction() {

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
