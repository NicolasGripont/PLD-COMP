#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Return* _ret)
    : SimpleStatement(), ret(_ret)
{

}

string ReturnStatement::print() {
	return "ReturnStatement";
}