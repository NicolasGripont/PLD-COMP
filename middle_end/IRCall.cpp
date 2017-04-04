#include "IRCall.h"

IRCall::IRCall(std::string _name, const Symbol *_returnSymbol, bool _isVoid)
    : IRInstruction(IRInstruction::Type::CALL), name(_name), returnSymbol(_returnSymbol), isReturnVoid(_isVoid)
{

}

IRCall::~IRCall()
{
	delete returnSymbol;
    for(const Symbol* s : params)
	{
		delete s;
	}
}

void IRCall::addParameter(const Symbol * symbol)
{
	if(symbol != nullptr)
	{
		params.push_back(symbol);
	}
}

std::string IRCall::toString() const
{
	std::string paramsStr = "";
    for( const Symbol* symbol : params)
	{
        if(symbol != nullptr)
		{
            paramsStr += symbol->getName() + ", ";
		}
	}

    paramsStr = paramsStr.substr(0, paramsStr.size()-2);

    std::string res = "CALL " + name + "(" + paramsStr + ")";
	return res;
}

bool IRCall::getIsReturnVoid() const
{
    return isReturnVoid;
}

std::vector<const Symbol *> IRCall::getParams() const
{
    return params;
}
