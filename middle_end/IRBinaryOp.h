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
        DIV,
        MOD,
        EQUAL_EQUAL,
        DIFF,
        LESS_THAN,
        LESS_THAN_OR_EQUAL,
        MORE_THAN,
        MORE_THAN_OR_EQUAL,
        AND_AND,
        OR_OR,
        OR,
        AND,
        LEFT_DEC,
        RIGHT_DEC,
        POW
    };

    IRBinaryOp(IRBinaryOp::Type _type, Symbol *dest, Symbol *op_1, Symbol *op_2);
    ~IRBinaryOp();

    virtual std::string toString() const;

    Type getType() const;

    Symbol *getOperand_1() const;
    Symbol *getOperand_2() const;

private:
    Type type;

    Symbol * operand_1 = nullptr;
    Symbol * operand_2 = nullptr;
};

#endif // IRBINARYOP_H
