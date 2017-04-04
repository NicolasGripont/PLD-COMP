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
    IRCall(std::string name, const Symbol *returnSymbol, bool _isVoid);
    ~IRCall();
    void addParameter(const Symbol* symbol);
    std::vector<const Symbol *> getParams() const;

    virtual std::string toString() const;

    bool getIsReturnVoid() const;

protected:
    std::string name;
    const Symbol* returnSymbol;
    std::vector<const Symbol*> params;
    bool isReturnVoid;
};

#endif // IRCALL_H
