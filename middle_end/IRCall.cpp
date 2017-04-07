#include "IRCall.h"

IRCall::IRCall(std::string _name, Symbol *_returnSymbol, std::vector<Symbol*> _params, bool _isVoid)
    : IRInstruction(IRInstruction::Operation::CALL), name(_name), returnSymbol(_returnSymbol),
      params(_params),isReturnVoid(_isVoid)
{

}

IRCall::~IRCall()
{
    delete returnSymbol;
    for (Symbol* s : params)
    {
        delete s;
    }
}

const std::string IRCall::getName() const
{
    return name;
}

Symbol* IRCall::getReturnSymbol() const
{
    return returnSymbol;
}

std::vector<Symbol *> IRCall::getParams() const
{
    return params;
}

bool IRCall::getIsReturnVoid() const
{
    return isReturnVoid;
}

std::string IRCall::toString() const
{
    std::string paramsStr = "";
    for (Symbol* symbol : params)
    {
        if (symbol != nullptr)
        {
            paramsStr += symbol->getName() + ", ";
        }
    }

    paramsStr = paramsStr.substr(0, paramsStr.size()-2);

    std::string res = "CALL " + name + "(" + paramsStr + ")";
    return res;
}
