#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(char* _id) : id(_id)
{

}

char* DeclarationVariable::getId()
{
    return id;
}
