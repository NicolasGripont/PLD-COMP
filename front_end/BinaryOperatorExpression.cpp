#include "BinaryOperatorExpression.h"
#include "../comp.tab.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IRBinaryOp.h"

BinaryOperatorExpression::BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op)
    :Expression(),expr1(_expr1),expr2(_expr2),op(_op)
{
    int type1 = _expr1->getType();
    int type2 = _expr2->getType();

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
    :Expression(),expr1(_expr1),expr2(_expr2),op(_op)
{
    setType(_type);
}

BinaryOperatorExpression::~BinaryOperatorExpression()
{
    if(expr1 != nullptr)
    {
        delete expr1;
    }
    if(expr2 != nullptr)
    {
        delete expr2;
    }
}

std::string BinaryOperatorExpression::toString() const
{
    std::string txt = "(" + expr1->toString();

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
    return txt + expr2->toString() + ")";
}

void BinaryOperatorExpression::buildIR(CFG *cfg) const
{
    const Symbol * expr1Symbol;
    const Symbol * expr2Symbol;
    const Symbol * destination;
    IRBinaryOp * instruction;

    switch(op)
    {
    case COMMA:
        expr1->buildIR(cfg);
        expr2->buildIR(cfg);
        break;
    case EQUAL_EQUAL:
        // " == ";
        break;
    case DIFF:
        // " != ";
        break;
    case LESS_THAN:
        // " < ";
        break;
    case LESS_THAN_OR_EQUAL:
        // " <= ";
        break;
    case MORE_THAN:
        // " > ";
        break;
    case MORE_THAN_OR_EQUAL:
        // " >= ";
        break;
    case AND_AND:
        // " && ";
        break;
    case OR_OR:
        // " || ";
        break;
    case MUL:
        // " * ";
        break;
    case DIV:
        // " / ";
        break;
    case MOD:
        // " % ";
        break;
    case PLUS:
        expr1->buildIR(cfg);
        expr1Symbol = cfg->getLastInstructionDestination();

        expr2->buildIR(cfg);
        expr2Symbol = cfg->getLastInstructionDestination();

        if(expr1Symbol != nullptr && expr2Symbol != nullptr)
        {
            Symbol * destination = new Symbol(cfg->getTempVariableName(),getType(),cfg->getOffsetFromCurrentBasicBlock());
            IRBinaryOp * instruction = new IRBinaryOp(IRBinaryOp::Type::ADD,destination,expr1Symbol,expr2Symbol);

            cfg->addInstructionInCurrentBasicBlock(instruction);
        }
        break;
    case MINUS:
        expr1->buildIR(cfg);
        expr1Symbol = cfg->getLastInstructionDestination();

        expr2->buildIR(cfg);
        expr2Symbol = cfg->getLastInstructionDestination();

        if(expr1Symbol != nullptr && expr2Symbol != nullptr)
        {
            destination = new Symbol(cfg->getTempVariableName(),getType(),cfg->getOffsetFromCurrentBasicBlock());
            instruction = new IRBinaryOp(IRBinaryOp::Type::SUB,destination,expr1Symbol,expr2Symbol);

            cfg->addInstructionInCurrentBasicBlock(instruction);
        }
        break;
    case AND:
        // " & ";
        break;
    case OR:
        // " | ";
        break;
    case POW:
        // " ^ ";
        break;
    case LEFT_DEC:
        // " << ";
        break;
    case RIGHT_DEC:
        // " >> ";
        break;
    }
}


