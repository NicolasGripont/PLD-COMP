#include "AssignmentVariable.h"

#include "../middle_end/CFG.h"

AssignmentVariable::AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr)
	:Expression(),exprVar(_exprVar),expr(_expr)
{
    int type1 = _exprVar->getType();
    int type2 = _expr->getType();

    if(type1 == type2)
    {
        setType(type1);
    }
    else if (isArrayType(type1) != isArrayType(type2))
    {
        setType(EXPRESSION_TYPE_CONFLICT);
    }
    else
    {
        setType(type1);
    }
}

AssignmentVariable::~AssignmentVariable()
{
    if(exprVar != nullptr) 
    {
        delete exprVar;
    }
    if(expr != nullptr) 
    {
        delete expr;
    }
}

std::string AssignmentVariable::toString() const
{
    return exprVar->toString() + " = " + expr->toString();
}

void AssignmentVariable::buildIR(CFG *cfg) const
{

}

