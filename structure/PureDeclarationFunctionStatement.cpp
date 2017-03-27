#include "PureDeclarationFunctionStatement.h"

PureDeclarationFunctionStatement::PureDeclarationFunctionStatement()
    : DeclarationFunctionStatement(true)
{

}

string PureDeclarationFunctionStatement::print() const
{
	return "PureDeclarationFunctionStatement";
}