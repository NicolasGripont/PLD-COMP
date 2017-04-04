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
    IRCall(std::string name, Symbol *returnSymbol, bool _isVoid);
    ~IRCall();

    void addParameter(Symbol* symbol);

    const std::string getName() const;
    std::vector<Symbol *> getParams() const;
    bool getIsReturnVoid() const;

    virtual std::string toString() const;
    
protected:
    std::string name;
    Symbol* returnSymbol;
    std::vector<Symbol*> params;
    bool isReturnVoid;
};

#endif // _IRCALL_H