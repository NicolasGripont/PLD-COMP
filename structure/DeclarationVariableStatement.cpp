#include "DeclarationVariableStatement.h"

DeclarationVariableStatement::DeclarationVariableStatement()
    : SimpleStatement(DECLARATION_VARIABLE_STATEMENT)
{

}

DeclarationVariableStatement::~DeclarationVariableStatement()
{

}

string DeclarationVariableStatement::print() const
{
	return "DeclarationVariableStatement";
}
