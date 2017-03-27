#include "DeclarationVariableStatement.h"

DeclarationVariableStatement::DeclarationVariableStatement()
    : SimpleStatement(DECLARATION_VARIABLE_STATEMENT)
{

}


string DeclarationVariableStatement::print() {
	return "DeclarationVariableStatement";
}
