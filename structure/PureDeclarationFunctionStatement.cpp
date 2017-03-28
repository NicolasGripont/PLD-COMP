#include "PureDeclarationFunctionStatement.h"

PureDeclarationFunctionStatement::PureDeclarationFunctionStatement()
    : DeclarationFunctionStatement(true)
{

}

PureDeclarationFunctionStatement::~PureDeclarationFunctionStatement()
{

}

string PureDeclarationFunctionStatement::print() const
{
	return "PureDeclarationFunctionStatement";
}