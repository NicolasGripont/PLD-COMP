#include "DeclarationFunctionStatement.h"

DeclarationFunctionStatement::DeclarationFunctionStatement(bool _declaration)
    : Printable(), declaration(_declaration)
{

}

DeclarationFunctionStatement::~DeclarationFunctionStatement()
{

}

bool DeclarationFunctionStatement::isDeclaration()
{
    return declaration;
}

string DeclarationFunctionStatement::toString() const
{
	return "DeclarationFunctionStatement";
}