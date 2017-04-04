#ifndef _IRBINARYOP_H
#define _IRBINARYOP_H

#include <string>

#include "IROperationWithDestination.h"
#include "Symbol.h"

class IRBinaryOp : public IROperationWithDestination
{
public:
    enum class Type {
        ADD,
        SUB,
        MUL,
        DIV
    };

    IRBinaryOp(IRBinaryOp::Type _type, const Symbol *dest, const Symbol *op_1, const Symbol *op_2);
    ~IRBinaryOp();

    virtual std::string toString() const;

    Type getType() const;

    const Symbol *getOperand_1() const;
    const Symbol *getOperand_2() const;

private:
    Type type;

    const Symbol * operand_1 = nullptr;
    const Symbol * operand_2 = nullptr;
};

#endif // IRBINARYOP_H
