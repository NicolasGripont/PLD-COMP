#include "IRBinaryOp.h"

IRBinaryOp::IRBinaryOp(IRBinaryOp::Type _type, Symbol *dest, Symbol *op_1, Symbol *op_2)
    : IROperationWithDestination(dest), type(_type), operand_1(op_1), operand_2(op_2)
{}

IRBinaryOp::~IRBinaryOp()
{
    delete operand_1;
    delete operand_2;
}

std::string IRBinaryOp::toString() const
{
    std::string ret;

    switch(type)
    {
    case Type::ADD :
        ret = destination->getName() + " <- " + operand_1->getName() + " + " + operand_2->getName();
        break;

    case Type::SUB :
        ret = destination->getName() + " <- " + operand_1->getName() + " - " + operand_2->getName();
        break;

    case Type::DIV :
        ret = destination->getName() + " <- " + operand_1->getName() + " / " + operand_2->getName();
        break;

    case Type::MUL :
        ret = destination->getName() + " <- " + operand_1->getName() + " * " + operand_2->getName();
        break;
    }

    return ret;
}

IRBinaryOp::Type IRBinaryOp::getType() const
{
    return type;
}

Symbol *IRBinaryOp::getOperand_1() const
{
    return operand_1;
}

Symbol *IRBinaryOp::getOperand_2() const
{
    return operand_2;
}

