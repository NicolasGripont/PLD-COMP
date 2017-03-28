#include "IRCall.h"

IRCall::IRCall(BasicBlock* _block, std::string _name, Symbol *_returnSymbol) : IRInstruction(_block, IR_Operation.CALL), name(_name), returnSymbol(_returnSymbol)
{

}

IRCall::~IRCall() {
	delete returnSymbol;
	for( auto s : params) {
		delete s;
	}
}
    
void IRCall::addParameter(Symbol * symbol) {
	if(symbol != nullptr) {
		params.push_back(symbol);
	}
}

std::string IRCall::toString() const {
	std::string paramsStr = "";
	for( auto s : params) {
		if(s != nullptr) {
			paramsStr += s->getName() + ", ";
		}
	}
	std::string res = "call " + name + "(" + + ")";
	return res;
}
