#include "DeclarationFonctionStatement.h"

DeclarationFonctionStatement::DeclarationFonctionStatement(bool _declaration)
    : declaration(_declaration)
{

}

bool DeclarationFonctionStatement::isDeclaration()
{
    return declaration;
}