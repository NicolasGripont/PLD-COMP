#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <vector>

#include "Declaration.h"
#include "DeclarationVariable.h"
#include "Type.h"
#include "MultipleDeclarationVariable.h"
#include "Argument.h"
#include "ArgumentList.h"
#include "Expression.h"
#include "DeclarationInitVariable.h"
#include "DeclarationArrayVariable.h"
#include "GlobalDeclarationVariable.h"
#include "FunctionCallExpression.h"
#include "BinaryOperatorExpression.h"
#include "UnaryOperatorExpression.h"
#include "ExpressionInteger.h"
#include "CrementVariable.h"
#include "DeclarationFunctionStatement.h"

#include "Return.h"
#include "SimpleStatement.h"
#include "ReturnStatement.h"
#include "MultipleStatement.h"
#include "Statement.h"
#include "BlockDeclarationVariable.h"
#include "IterationStatement.h"
#include "SelectionStatement.h"
#include "ExpressionStatement.h"
#include "DeclarationVariableStatement.h"
#include "LoopExpression.h"
#include "WhileLoop.h"
#include "ForLoop.h"
#include "DeclarationFunction.h"
#include "ExpressionSimpleVariable.h"
#include "ExpressionArrayVariable.h"
#include "AssignmentOperationVariable.h"

class ExpressionVariable;
class ExpressionSimpleVariable;
class ExpressionArrayVariable;
class AssignmentVariable;
class AssignmentOperationVariable;

// Declaration sans initialisation de la fonction
class PureDeclarationFunctionStatement : public DeclarationFunctionStatement {
public:
	PureDeclarationFunctionStatement()
    :DeclarationFunctionStatement(true){};
};

// Initialisation du corps de la fonction
class InitFunctionStatement : public DeclarationFunctionStatement {
private:
	MultipleStatement* multipleStatement;
public:
	InitFunctionStatement(MultipleStatement* _multipleStatement)
	:DeclarationFunctionStatement(false),multipleStatement(_multipleStatement){};
};

// Struct qui n'est pas utilisee dans la structure de donnees
// mais qui sert a la detection des Erreur
struct VariableContainer
{
	char* name;
	int type;

	VariableContainer(char* _name, int _type):
	name(_name),type(_type){};
};

struct FunctionContainer
{
    char* name;
	int type;
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;

	FunctionContainer(char* _name, int _type, bool _declaration):
	name(_name),type(_type),declaration(_declaration){};
};

#endif
