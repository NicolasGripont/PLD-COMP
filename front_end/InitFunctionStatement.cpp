#include "InitFunctionStatement.h"

#include "../middle_end/BasicBlock.h"
#include "../middle_end/CFG.h"

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
    BasicBlock * block = cfg->createNewBasicBlock(1,cfg->getUsableBasicBlockName());
    cfg->attachNewBasicBlock(block);

    multipleStatement->buildIR(cfg);
}

int InitFunctionStatement::countStatements()
{
    return multipleStatement->countStatements();
}

SimpleStatement*& InitFunctionStatement::operator[] (int i)
{
    return (*multipleStatement)[i];
}
