#ifndef IRCALL_H
#define IRCALL_H
#include <iostream>
#include <vector>
#include "BasicBlock.h"
#include "Symbol"

class IRCall
{
public:
    IRCall(BasicBlock* block, std::string name, Symbol *returnSymbol);
    ~IRCall();
    void addParameter(Symbol * symbol);
    std::string toString() const;

protected:
	std::string name;
	Symbol *returnSymbol;
	vector<Symbol *> params;
};

#endif // IRCALL_H
