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
#include "IterationStatement.h"
#include "LoopExpression.h"
#include "WhileLoop.h"
#include "ForLoop.h"
#include "DeclarationFunction.h"

class GlobalDeclarationVariable;
class ExpressionVariable;
class DeclarationInitVariable;
class DeclarationArrayVariable;
class GlobalDeclarationVariable;
class FunctionCallExpression;
class BinaryOperatorExpression;
class UnaryOperatorExpression;
class ExpressionInteger;
class ExpressionVariable;
class CrementVariable;
class DeclarationVariableStatement;

class ExpressionSimpleVariable : public ExpressionVariable {
private:
	char* id;
public:
	ExpressionSimpleVariable(char* _id)
	:ExpressionVariable(),id(_id){};
};

class ExpressionArrayVariable : public ExpressionVariable {
	char* id;
	Expression* expr;
public:
	ExpressionArrayVariable(char* _id, Expression* _expr)
	:ExpressionVariable(),id(_id),expr(_expr){};
};

class AssignmentVariable : public Expression {
protected:
	ExpressionVariable* exprVar;
	Expression* expr;
public:
	AssignmentVariable(ExpressionVariable* _exprVar, Expression* _expr)
	:Expression(),exprVar(_exprVar),expr(_expr){};
};

class AssignmentOperationVariable : public AssignmentVariable{
private:
	int op;
public:
	AssignmentOperationVariable(ExpressionVariable* _exprVar, Expression* _expr, int _op)
	:AssignmentVariable(_exprVar,_expr),op(_op){};
};


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

// Declaration de variable dans un block
class BlockDeclarationVariable : public SimpleStatement {
private:
	MultipleDeclarationVariable* multipleDeclarationVariable;

public:
	BlockDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	:SimpleStatement(),multipleDeclarationVariable(_multipleDeclarationVariable){};
};

class SelectionStatement : public SimpleStatement {
private:
	// Expression dans le if
	Expression* expr;
	// Si la condition est realisee
	Statement* stat;
	// Sinon (peut etre = nullptr si on a pas de else)
	Statement* elseStat;
public:
	SelectionStatement(Expression* _expr, Statement* _stat, Statement* _elseStat)
	:SimpleStatement(), expr(_expr), stat(_stat), elseStat(_elseStat){};
};

class ExpressionStatement : public SimpleStatement {
private:
	Expression* expr;
public:
	ExpressionStatement(Expression* _expr):SimpleStatement(),expr(_expr){};
};

class DeclarationVariableStatement : public SimpleStatement {
public:
	DeclarationVariableStatement():SimpleStatement(){};
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
