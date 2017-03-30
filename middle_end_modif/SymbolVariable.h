#ifndef SYMBOL_VARIABLE_H
#define SYMBOL_VARIABLE_H

#include "Symbol.h"
#include "DataType.h"

class SymbolVariable : public Symbol
{
public:
    SymbolVariable(SymbolType _type, std::string _name, DataType _dataType);

    DataType getDataType();
private:
    DataType dataType;
};

#endif
