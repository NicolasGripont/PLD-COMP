#include "DeclarationFunction.h"

DeclarationFunction::DeclarationFunction(Type* _type, char* _id, ArgumentList* _argumentList, DeclarationFunctionStatement* _decFunctionStatement)
    : Declaration(DECLARATION_FUNCTION) ,type(_type), id(_id), decFunctionStatement(_decFunctionStatement), argumentList(_argumentList)
{

}

DeclarationFunction::~DeclarationFunction()
{
    delete type;
    delete decFunctionStatement;
    delete argumentList;
}

string DeclarationFunction::toString() const
{
	return type->toString() + string(" ") + string(id) + string("(") +  argumentList->toString() + string(")") + decFunctionStatement->toString();
}
