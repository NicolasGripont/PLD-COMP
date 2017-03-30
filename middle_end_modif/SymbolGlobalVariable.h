#ifndef SYMBOL_GLOBAL_VARIABLE_H
#define SYMBOL_GLOBAL_VARIABLE_H

#include "SymbolVariable.h"
#include "DataType.h"

class SymbolGlobalVariable : public SymbolVariable
{
public:
    SymbolGlobalVariable(std::string _name, DataType _variableType);
private:
};

#endif
