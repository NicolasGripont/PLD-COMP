#ifndef _DECLARATIONFUNCTION_H
#define _DECLARATIONFUNCTION_H

#include "Declaration.h"
#include "DeclarationFunctionStatement.h"
#include "ArgumentList.h"
#include "Type.h"

class DeclarationFunction : public Declaration
{
public:
	DeclarationFunction(Type* _type, char* _id, ArgumentList* _argumentList, DeclarationFunctionStatement* _decFunctionStatement);
	virtual ~DeclarationFunction();
	virtual std::string toString() const;
	ArgumentList* getArgumentList() const;
	DeclarationFunctionStatement* getFunctionStatement() const;

private:
	Type* type;
	char* id;
	DeclarationFunctionStatement* decFunctionStatement;
	ArgumentList* argumentList;
};

#endif