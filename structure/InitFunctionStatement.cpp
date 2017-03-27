#include "InitFunctionStatement.h"

InitFunctionStatement::InitFunctionStatement(MultipleStatement* _multipleStatement)
    : DeclarationFunctionStatement(false), multipleStatement(_multipleStatement)
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
