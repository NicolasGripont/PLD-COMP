#ifndef _IRJUMP_H
#define _IRJUMP_H

#include <string>

#include "IRInstruction.h"

class IRJump : public IRInstruction
{
public:
    IRJump(std::string lab);
    ~IRJump() = default;

    virtual std::string toString() const;

    std::string getLabel() const;

private:
    std::string label;
};

#endif // IRJUMP_H
