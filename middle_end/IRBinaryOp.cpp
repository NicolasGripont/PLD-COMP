#include "IRBinaryOp.h"

IRBinaryOp::IRBinaryOp(IRBinaryOp::Type _type, Symbol *op_1, Symbol *op_2, Symbol *op_3)
    : IRInstruction(), type(_type), operand_1(op_1), operand_2(op_2), operand_3(op_3)
{

}

IRBinaryOp::~IRBinaryOp()
{
    delete operand_1;
    delete operand_2;
    delete operand_3;
}

std::string IRBinaryOp::toString() const
{
    std::string ret;

    switch(type)
    {
    case Type::ADD :
        ret = operand_1->getName() + " <- " + operand_2->getName() + " + " + operand_3->getName();
        break;

    case Type::SUB :
        ret = operand_1->getName() + " <- " + operand_2->getName() + " - " + operand_3->getName();
        break;

    case Type::DIV :
        ret = operand_1->getName() + " <- " + operand_2->getName() + " / " + operand_3->getName();
        break;

    case Type::MUL :
        ret = operand_1->getName() + " <- " + operand_2->getName() + " * " + operand_3->getName();
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

Symbol *IRBinaryOp::getOperand_3() const
{
    return operand_3;
}
