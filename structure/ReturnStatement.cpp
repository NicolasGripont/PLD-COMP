#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Return* _ret)
    : SimpleStatement(RETURN_STATEMENT), ret(_ret)
{

}

string ReturnStatement::print() const
{
	return "ReturnStatement";
}
