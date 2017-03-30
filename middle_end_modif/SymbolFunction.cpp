#include "SymbolFunction.h"

SymbolFunction::SymbolFunction(std::string _name, DataType _returnType, std::vector<DataType> _parametersType)
    :Symbol(SymbolType::FUNCTION, _name), returnType(_returnType), parametersType(_parametersType)
{

}
