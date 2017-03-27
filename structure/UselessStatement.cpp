#include "UselessStatement.h"

UselessStatement::UselessStatement()
    : SimpleStatement(USELESS_STATEMENT)
{

}

string UselessStatement::print() {
	return "UselessStatement";
}

