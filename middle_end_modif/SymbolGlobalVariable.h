#ifndef SYMBOL_GLOBAL_VARIABLE_H
#define SYMBOL_GLOBAL_VARIABLE_H

#include "Symbol.h"
#include "DataType.h"

class SymbolGlobalVariable : public Symbol
{
public:
    SymbolGlobalVariable(std::string _name, DataType _variableType);
private:
    DataType variableType;
};

#endif
