#ifndef SYMBOL_LOCAL_VARIABLE_H
#define SYMBOL_LOCAL_VARIABLE_H

#include "SymbolVariable.h"
#include "DataType.h"

class SymbolLocalVariable : public SymbolVariable
{
public:
    SymbolLocalVariable(std::string _name, DataType _variableType, int _memoryLocation);
private:
    int memoryLocation;
};

#endif
