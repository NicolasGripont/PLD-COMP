#ifndef SYMBOL_FUNCTION_H
#define SYMBOL_FUNCTION_H

#include <vector>

#include "Symbol.h"
#include "DataType.h"

class SymbolFunction : public Symbol
{
public:
    SymbolFunction(std::string _name, DataType _returnType, std::vector<DataType> _parametersType);
private:
    DataType returnType;
    std::vector<DataType> parametersType;
};

#endif
