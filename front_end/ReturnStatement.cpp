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

std::string ReturnStatement::toString() const
{
    return ret->toString() + "; ";
}

void ReturnStatement::buildIR(CFG *cfg) const
{

}
