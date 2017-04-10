#include "MultipleDeclarationVariable.h"
#include "DeclarationInitVariable.h"
#include "DeclarationArrayVariable.h"

#include "../middle_end/IRRWMemory.h"
#include "../middle_end/CFG.h"
#include "../middle_end/IROperationWithDestination.h"

MultipleDeclarationVariable::MultipleDeclarationVariable() : Printable(){

                                                             };

MultipleDeclarationVariable::~MultipleDeclarationVariable()
{
    if (type != nullptr)
    {
        delete type;
    }
    for (unsigned int i = 0; i < declarationsVariables.size(); ++i)
    {
        if (declarationsVariables[i] != nullptr)
        {
            delete declarationsVariables[i];
        }
    }
}

std::string MultipleDeclarationVariable::toString() const
{
    std::string txt = type->toString();

    if (!declarationsVariables.empty())
    {
        txt += " " + declarationsVariables.at(0)->toString();
    }
    for (unsigned int i = 1; i < declarationsVariables.size(); ++i)
    {
        txt += ", " + declarationsVariables.at(i)->toString();
    }

    return txt;
}

void MultipleDeclarationVariable::buildIR(CFG *cfg) const
{
    for (DeclarationVariable *decl : declarationsVariables)
    {
        Symbol *destination = new Symbol(decl->getId(), this->getType()->getType(), cfg->getOffsetFromCurrentBasicBlock());
        if (decl->isArray())
        {
            DeclarationArrayVariable *arrayDecl = dynamic_cast<DeclarationArrayVariable *>(decl);

            if (arrayDecl != nullptr)
            {
                cfg->incrementOffsetWithArraySize(arrayDecl->getSize());
            }
        }

        cfg->addSymbolToCurrentBasicBlock(destination);

        if (!decl->isDeclaration())
        {
            DeclarationInitVariable *definition = dynamic_cast<DeclarationInitVariable *>(decl);

            if (definition != nullptr)
            {
                definition->getExpr()->buildIR(cfg);

                Symbol *source = cfg->getLastInstructionDestination();

                if (source != nullptr)
                {
                    IRRWMemory *instruction = new IRRWMemory(IRRWMemory::Type::WRITE_MEMORY, destination, source);
                    cfg->addInstructionInCurrentBasicBlock(instruction);
                }
            }
        }
    }
}

void MultipleDeclarationVariable::addDeclarationVariable(DeclarationVariable *dec)
{
    declarationsVariables.push_back(dec);
}

void MultipleDeclarationVariable::setType(Type *t)
{
    type = t;
}

Type *MultipleDeclarationVariable::getType() const
{
    return type;
}

int MultipleDeclarationVariable::countDeclaration()
{
    return declarationsVariables.size();
}

DeclarationVariable *&MultipleDeclarationVariable::operator[](int i)
{
    return declarationsVariables[i];
}
