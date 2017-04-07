#include "DeclarationFunction.h"
#include "InitFunctionStatement.h"
#include "../middle_end/BasicBlock.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IRRWMemory.h"

DeclarationFunction::DeclarationFunction(Type* _type, char* _id, ArgumentList* _argumentList, DeclarationFunctionStatement* _decFunctionStatement)
    : Declaration(DECLARATION_FUNCTION), type(_type), id(_id), decFunctionStatement(_decFunctionStatement), argumentList(_argumentList)
{
}

DeclarationFunction::~DeclarationFunction()
{
    if(id != nullptr)
    {
        free(id);
    }
    if(type != nullptr)
    {
        delete type;
    }
    if(decFunctionStatement != nullptr)
    {
        delete decFunctionStatement;
    }
    if(argumentList != nullptr)
    {
        delete argumentList;
    }
}

std::string DeclarationFunction::toString() const
{
    return type->toString() + " " + std::string(id) + "(" +  argumentList->toString() + ")" + decFunctionStatement->toString();
}

void DeclarationFunction::buildIR(CFG * cfg) const
{
    InitFunctionStatement * state = dynamic_cast<InitFunctionStatement*>(decFunctionStatement);
    if(state != nullptr)
    {
        // Creation prolog
        BasicBlock * basicProlog = cfg->createNewBasicBlock(0, getId());
        cfg->setCurrentBasicBlock(basicProlog);
        cfg->setRootBasicBlock(basicProlog);

        for(Argument *  arg : argumentList->getArguments())
        {
            Symbol * symbol = new Symbol(arg->getName(),
                                         arg->getType()->getType(),
                                         cfg->getOffsetFromCurrentBasicBlock()
                                         );

            cfg->addSymbolToCurrentBasicBlock(symbol);
        }

        // Build IR de l'AST
        state->buildIR(cfg);

        // CReation epilog
        BasicBlock * basicEpilog = cfg->createNewBasicBlock(0, "epilog_" + getId());
        cfg->attachNewBasicBlock(basicEpilog);
    }
}


ArgumentList *DeclarationFunction::getArgumentList() const
{
    return argumentList;
}


DeclarationFunctionStatement *DeclarationFunction::getFunctionStatement() const
{
    return decFunctionStatement;
}


std::string DeclarationFunction::getId() const
{
    return id;
}
