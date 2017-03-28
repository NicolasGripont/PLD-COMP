#ifndef IRJUMP_H
#define IRJUMP_H

#include "IRInstruction.h"
#include <string>

class IRJump : public IRInstruction
{
public:

    IRJump(std::string lab);
    ~IRJump() = default;

    std::string getLabel() const;

private:
    std::string label;

};

#endif // IRJUMP_H
