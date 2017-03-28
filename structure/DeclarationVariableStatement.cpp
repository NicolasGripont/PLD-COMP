#include "DeclarationVariableStatement.h"

DeclarationVariableStatement::DeclarationVariableStatement()
    : SimpleStatement(DECLARATION_VARIABLE_STATEMENT)
{

}

DeclarationVariableStatement::~DeclarationVariableStatement()
{

}

string DeclarationVariableStatement::toString() const
{
	return "DeclarationVariableStatement";
}
