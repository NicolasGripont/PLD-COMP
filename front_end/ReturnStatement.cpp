#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Return* _ret)
    : SimpleStatement(RETURN_STATEMENT), ret(_ret)
{

}

ReturnStatement::~ReturnStatement()
{
	if(ret != nullptr) 
	{
		delete ret;
	} 
}

string ReturnStatement::toString() const
{
	return ret->toString() + "; ";
}
