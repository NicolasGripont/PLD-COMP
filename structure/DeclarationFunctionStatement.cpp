#include "DeclarationFunctionStatement.h"

DeclarationFunctionStatement::DeclarationFunctionStatement(bool _declaration)
    : declaration(_declaration)
{

}

bool DeclarationFunctionStatement::isDeclaration()
{
    return declaration;
}