#include "DeclarationFunction.h"

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
