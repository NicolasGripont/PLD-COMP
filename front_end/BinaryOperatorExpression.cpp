#include "BinaryOperatorExpression.h"
#include "../comp.tab.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IRBinaryOp.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _left, Expression* _right, int _op)
    :Expression(),left(_left),right(_right),op(_op)
{
    int type1 = _left->getType();
    int type2 = _right->getType();

    if (isArrayType(type1) != isArrayType(type2))
    {
        setType(EXPRESSION_TYPE_CONFLICT);
    }
    else if(sizeOfType(type1) > sizeOfType(type2))
    {
        setType(type1);
    }
    else
    {
        setType(type2);
    }
}

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op, int _type)
    :Expression(),left(_expr1),right(_expr2),op(_op)
{
    setType(_type);
}

BinaryOperatorExpression::~BinaryOperatorExpression()
{
    if(left != nullptr)
    {
        delete left;
    }
    if(right != nullptr)
    {
        delete right;
    }
}

std::string BinaryOperatorExpression::toString() const
{
    std::string txt = "(" + left->toString();

    switch(op)
    {
    case COMMA:
        txt += " , ";
        break;
    case EQUAL_EQUAL:
        txt += " == ";
        break;
    case DIFF:
        txt += " != ";
        break;
    case LESS_THAN:
        txt += " < ";
        break;
    case LESS_THAN_OR_EQUAL:
        txt += " <= ";
        break;
    case MORE_THAN:
        txt += " > ";
        break;
    case MORE_THAN_OR_EQUAL:
        txt += " >= ";
        break;
    case AND_AND:
        txt += " && ";
        break;
    case OR_OR:
        txt += " || ";
        break;
    case MUL:
        txt += " * ";
        break;
    case DIV:
        txt += " / ";
        break;
    case MOD:
        txt += " % ";
        break;
    case PLUS:
        txt += " + ";
        break;
    case MINUS:
        txt += " - ";
        break;
    case AND:
        txt += " & ";
        break;
    case OR:
        txt += " | ";
        break;
    case POW:
        txt += " ^ ";
        break;
    case LEFT_DEC:
        txt += " << ";
        break;
    case RIGHT_DEC:
        txt += " >> ";
        break;
    default:
        return "ERROR_BinaryOperatorExpression";
    }
    return txt + right->toString() + ")";
}

void BinaryOperatorExpression::buildIR(CFG *cfg) const
{
    IRBinaryOp * instruction = nullptr;

    left->buildIR(cfg);
    Symbol * expr1Symbol = cfg->getLastInstructionDestination();

    right->buildIR(cfg);
    Symbol * expr2Symbol = cfg->getLastInstructionDestination();

    if(expr1Symbol != nullptr && expr2Symbol != nullptr)
    {
        Symbol * destination = new Symbol(cfg->getTempVariableName(),getType(),cfg->getOffsetFromCurrentBasicBlock());

        switch(op)
        {
        case COMMA:
            break;
        case EQUAL_EQUAL:
            instruction = new IRBinaryOp(IRBinaryOp::Type::EQUAL_EQUAL,destination,expr1Symbol,expr2Symbol);
            break;
        case DIFF:
            instruction = new IRBinaryOp(IRBinaryOp::Type::DIFF,destination,expr1Symbol,expr2Symbol);
            break;
        case LESS_THAN:
            instruction = new IRBinaryOp(IRBinaryOp::Type::LESS_THAN,destination,expr1Symbol,expr2Symbol);
            break;
        case LESS_THAN_OR_EQUAL:
            instruction = new IRBinaryOp(IRBinaryOp::Type::LESS_THAN_OR_EQUAL,destination,expr1Symbol,expr2Symbol);
            break;
        case MORE_THAN:
            instruction = new IRBinaryOp(IRBinaryOp::Type::MORE_THAN,destination,expr1Symbol,expr2Symbol);
            break;
        case MORE_THAN_OR_EQUAL:
            instruction = new IRBinaryOp(IRBinaryOp::Type::MORE_THAN_OR_EQUAL,destination,expr1Symbol,expr2Symbol);
            break;
        case AND_AND:
            instruction = new IRBinaryOp(IRBinaryOp::Type::AND_AND,destination,expr1Symbol,expr2Symbol);
            break;
        case OR_OR:
            instruction = new IRBinaryOp(IRBinaryOp::Type::OR_OR,destination,expr1Symbol,expr2Symbol);
            break;
        case MUL:
            instruction = new IRBinaryOp(IRBinaryOp::Type::MUL,destination,expr1Symbol,expr2Symbol);
            break;
        case DIV:
            instruction = new IRBinaryOp(IRBinaryOp::Type::DIV,destination,expr1Symbol,expr2Symbol);
            break;
        case MOD:
            instruction = new IRBinaryOp(IRBinaryOp::Type::MOD,destination,expr1Symbol,expr2Symbol);
            break;
        case PLUS:
            instruction = new IRBinaryOp(IRBinaryOp::Type::ADD,destination,expr1Symbol,expr2Symbol);
            break;
        case MINUS:
            instruction = new IRBinaryOp(IRBinaryOp::Type::SUB,destination,expr1Symbol,expr2Symbol);
            break;
        case AND:
            instruction = new IRBinaryOp(IRBinaryOp::Type::AND,destination,expr1Symbol,expr2Symbol);
            break;
        case OR:
            instruction = new IRBinaryOp(IRBinaryOp::Type::OR,destination,expr1Symbol,expr2Symbol);
            break;
        case POW:
            instruction = new IRBinaryOp(IRBinaryOp::Type::POW,destination,expr1Symbol,expr2Symbol);
            break;
        case LEFT_DEC:
            instruction = new IRBinaryOp(IRBinaryOp::Type::LEFT_DEC,destination,expr1Symbol,expr2Symbol);
            break;
        case RIGHT_DEC:
            instruction = new IRBinaryOp(IRBinaryOp::Type::RIGHT_DEC,destination,expr1Symbol,expr2Symbol);
            break;
        }

        if(instruction != nullptr)
        {
            cfg->addInstructionInCurrentBasicBlock(instruction);
        }
    }
}

Expression *BinaryOperatorExpression::getLeft() const
{
    return left;
}

Expression *BinaryOperatorExpression::getRight() const
{
    return right;
}

