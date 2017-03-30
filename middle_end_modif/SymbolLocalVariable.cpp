#include "SymbolLocalVariable.h"

SymbolLocalVariable::SymbolLocalVariable(std::string _name, int _memoryLocation, DataType _variableType)
    :Symbol(SymbolType::LOCAL_VARIABLE, _name), memoryLocation(_memoryLocation), variableType(_variableType)
{

}
