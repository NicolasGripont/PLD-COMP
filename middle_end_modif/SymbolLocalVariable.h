#ifndef SYMBOL_LOCAL_VARIABLE_H
#define SYMBOL_LOCAL_VARIABLE_H

#include "Symbol.h"
#include "DataType.h"

class SymbolLocalVariable : public Symbol
{
public:
    SymbolLocalVariable(std::string _name, int _memoryLocation, DataType _variableType);
private:
    DataType variableType;
    int memoryLocation;
};

#endif
