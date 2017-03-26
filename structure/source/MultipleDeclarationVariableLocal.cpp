#include "../header/MultipleDeclarationVariableLocal.h"
#include <iostream>

MultipleDeclarationVariableLocal::MultipleDeclarationVariableLocal()
{
    std::cout<<"MultipleDeclarationVariableLocal - Constructor"<<std::endl;
}

MultipleDeclarationVariableLocal::~MultipleDeclarationVariableLocal()
{
    for(auto node : listSimpleStatements)
    {
        delete node;
    }
}

MultipleDeclarationVariableLocal::addSimpleStatement(const SimpleStatement * simpleStatement)
{
    listSimpleStatements.push_back(simpleStatement);
}
