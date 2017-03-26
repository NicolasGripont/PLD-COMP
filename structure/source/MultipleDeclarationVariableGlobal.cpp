#include "../header/MultipleDeclarationVariableGlobal.h"
#include <iostream>

MultipleDeclarationVariableGlobal::MultipleDeclarationVariableGlobal(Type atype) : type(atype)
{
    std::cout<<"MultipleDeclarationVariableGlobal - Constructor"<<std::endl;
}

MultipleDeclarationVariableGlobal::~MultipleDeclarationVariableGlobal()
{
    delete nextNode;
    for(auto dec : variableDeclarations)
    {
        delete dec;
    }
}

void MultipleDeclarationVariableGlobal::addVariableDeclaration(DeclarationVariable *declaration)
{
    variableDeclarations.push_back(declaration);
}
