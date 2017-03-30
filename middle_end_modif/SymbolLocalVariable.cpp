#include "SymbolLocalVariable.h"

SymbolLocalVariable::SymbolLocalVariable(std::string _name, DataType _variableType, int _memoryLocation)
    :SymbolVariable(SymbolType::LOCAL_VARIABLE, _name, _variableType), memoryLocation(_memoryLocation)
{

}
