#include "SymbolGlobalVariable.h"

SymbolGlobalVariable::SymbolGlobalVariable(std::string _name, DataType _variableType)
    :Symbol(SymbolType::GLOBAL_VARIABLE, _name), variableType(_variableType)
{

}
