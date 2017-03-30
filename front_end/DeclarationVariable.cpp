#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(char *_id, bool _array)
    : Printable(), id(_id), array(_array), declaration(true)
{
}

DeclarationVariable::DeclarationVariable(char *_id, bool _array, bool _declaration)
    : Printable(), id(_id), array(_array), declaration(declaration)
{
}

DeclarationVariable::~DeclarationVariable()
{
    if (id != nullptr)
    {
        free(id);
    }
}

char *DeclarationVariable::getId()
{
    return id;
}

bool DeclarationVariable::isArray()
{
    return array;
}

bool DeclarationVariable::isDeclaration()
{
    return declaration;
}

string DeclarationVariable::toString() const
{
    if (!array)
    {
        return string(id);
    }
    return "ERROR_DeclarationVariable";
}
