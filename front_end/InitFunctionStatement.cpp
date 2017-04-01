#include "InitFunctionStatement.h"

InitFunctionStatement::InitFunctionStatement(MultipleStatement* _multipleStatement)
    : DeclarationFunctionStatement(false), multipleStatement(_multipleStatement)
{

}

InitFunctionStatement::~InitFunctionStatement()
{
	if(multipleStatement != nullptr)
	{
		delete multipleStatement;
	}
}

std::string InitFunctionStatement::toString() const
{
    return "{" + multipleStatement->toString() + "}";
}

void InitFunctionStatement::buildIR(CFG *cfg) const
{

}

int InitFunctionStatement::countStatements()
{
    return multipleStatement->countStatements();
}

SimpleStatement*& InitFunctionStatement::operator[] (int i)
{
    return (*multipleStatement)[i];
}
