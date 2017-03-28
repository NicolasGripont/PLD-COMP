#include "PureDeclarationFunctionStatement.h"

PureDeclarationFunctionStatement::PureDeclarationFunctionStatement()
    : DeclarationFunctionStatement(true)
{

}

PureDeclarationFunctionStatement::~PureDeclarationFunctionStatement()
{

}

string PureDeclarationFunctionStatement::toString() const
{
	return ";";
}