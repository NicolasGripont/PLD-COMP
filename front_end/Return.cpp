#include "Return.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IRReturn.h"

Return::Return(Expression* _expr)
    : Printable(), expr(_expr)
{

}

Return::~Return()
{
    if(expr != nullptr)
    {
        delete expr;
    }
}

std::string Return::toString() const
{
    std::string txt = "return";

    if(expr != nullptr)
    {
        txt += " " + expr->toString();
    }
    return txt;
}

void Return::buildIR(CFG *cfg) const
{
    Symbol * result = nullptr;

    if(expr != nullptr)
    {
        expr->buildIR(cfg);
        result = cfg->getLastInstructionDestination();
    }

    IRReturn * instruction = new IRReturn(result);
    cfg->addInstructionInCurrentBasicBlock(instruction);
}
