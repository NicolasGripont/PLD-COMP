#include "IRCall.h"

IRCall::IRCall(std::string _name, Symbol *_returnSymbol, bool _isVoid)
    : IRInstruction(IRInstruction::Type::CALL), name(_name), returnSymbol(_returnSymbol), isReturnVoid(_isVoid)
{

}

IRCall::~IRCall()
{
	delete returnSymbol;
	for(Symbol* s : params)
	{
		delete s;
	}
}

void IRCall::addParameter(Symbol * symbol)
{
	if(symbol != nullptr)
	{
		params.push_back(symbol);
	}
}

std::string IRCall::toString() const
{
	std::string paramsStr = "";
	for( auto s : params)
	{
		if(s != nullptr)
		{
			paramsStr += s->getName() + ", ";
		}
	}
    std::string res = "CALL " + name + "(" + paramsStr + ")";
	return res;
}

bool IRCall::getIsReturnVoid() const
{
    return isReturnVoid;
}
