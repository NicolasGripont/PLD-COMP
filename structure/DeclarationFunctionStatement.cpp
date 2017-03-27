#include "DeclarationFunctionStatement.h"

DeclarationFunctionStatement::DeclarationFunctionStatement(bool _declaration)
    : Printer(), declaration(_declaration)
{

}

bool DeclarationFunctionStatement::isDeclaration()
{
    return declaration;
}

string DeclarationFunctionStatement::print() const
{
	return "DeclarationFunctionStatement";
}