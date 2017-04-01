#include "PureDeclarationFunctionStatement.h"

PureDeclarationFunctionStatement::PureDeclarationFunctionStatement()
    : DeclarationFunctionStatement(true)
{

}

PureDeclarationFunctionStatement::~PureDeclarationFunctionStatement()
{

}

std::string PureDeclarationFunctionStatement::toString() const
{
    return "; ";
}

void PureDeclarationFunctionStatement::buildIR(CFG *cfg) const
{

}
