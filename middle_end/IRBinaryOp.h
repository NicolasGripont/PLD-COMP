#ifndef _IRBINARYOP_H
#define _IRBINARYOP_H

#include "IRInstruction.h"

class IRBinaryOp : public IRInstruction
{
public:
    enum class Type {
        ADD,
        SUB,
        MUL,
        DIV
    };

    IRBinaryOp(Type _type, Symbol * op_1,
                           Symbol * op_2,
                           Symbol * op_3);
    ~IRBinaryOp();

    std::string toString() const;

    Type getType() const;

    Symbol *getOperand_1() const;
    Symbol *getOperand_2() const;
    Symbol *getOperand_3() const;

private:
    Type type;

    Symbol * operand_1 = nullptr;
    Symbol * operand_2 = nullptr;
    Symbol * operand_3 = nullptr;
};

#endif // IRBINARYOP_H