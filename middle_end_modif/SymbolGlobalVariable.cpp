#include "SymbolGlobalVariable.h"

SymbolGlobalVariable::SymbolGlobalVariable(std::string _name, DataType _variableType)
    :SymbolVariable(SymbolType::GLOBAL_VARIABLE, _name, _variableType)
{

}
