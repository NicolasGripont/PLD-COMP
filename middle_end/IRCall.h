#ifndef _IRCALL_H
#define _IRCALL_H

#include <iostream>
#include <vector>

#include "IRInstruction.h"
#include "BasicBlock.h"
#include "Symbol.h"

class IRCall : public IRInstruction
{
public:
    IRCall(BasicBlock* block, std::string name, Symbol *returnSymbol);
    ~IRCall();
    void addParameter(Symbol* symbol);
    std::string toString() const;

protected:
	std::string name;
	Symbol* returnSymbol;
	std::vector<Symbol*> params;
};

#endif // IRCALL_H
