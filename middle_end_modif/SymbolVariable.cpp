#include "SymbolVariable.h"

SymbolVariable::SymbolVariable(SymbolType _symbolType, std::string _name, DataType _dataType)
    :Symbol(_symbolType, _name), dataType(_dataType)
{

}

DataType SymbolVariable::getDataType()
{
    return dataType;
}