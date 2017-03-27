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

#include "LoopExpression.h"

class DeclarationFonction;
class DeclarationFonctionStatement;
class MultipleStatement;
class GlobalDeclarationVariable;
class SimpleStatement;
class Return;
class ExpressionVariable;
class Statement;
class DeclarationInitVariable;
class DeclarationArrayVariable;
class GlobalDeclarationVariable;
class FunctionCallExpression;
class BinaryOperatorExpression;
class UnaryOperatorExpression;
class ExpressionInteger;
class ExpressionVariable;
class CrementVariable;

class DeclarationFonction : public Declaration {
private:
	Type* type;
	char* id;
	DeclarationFonctionStatement* decFunctionStatement;
	ArgumentList* argumentList;
public:
	DeclarationFonction(Type* _type, char* _id, ArgumentList* _argumentList, DeclarationFonctionStatement* _decFunctionStatement)
	:Declaration(),type(_type),id(_id),argumentList(_argumentList),decFunctionStatement(_decFunctionStatement){};
};


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

class DeclarationFonctionStatement {
private:
    // Si vrai : Declaration, si faux : initialisation
    bool declaration;
public:
	DeclarationFonctionStatement(bool _declaration)
    :declaration(_declaration){};

    bool isDeclaration()
    {
        return declaration;
    }
};

// Declaration sans initialisation de la fonction
class PureDeclarationFonctionStatement : public DeclarationFonctionStatement {
public:
	PureDeclarationFonctionStatement()
    :DeclarationFonctionStatement(true){};
};

// Initialisation du corps de la fonction
class InitFonctionStatement : public DeclarationFonctionStatement {
private:
	MultipleStatement* multipleStatement;
public:
	InitFonctionStatement(MultipleStatement* _multipleStatement)
	:DeclarationFonctionStatement(false),multipleStatement(_multipleStatement){};
};

class MultipleStatement {
private:
	std::vector<SimpleStatement*> statements;
public:
	MultipleStatement(){};

	void addStatement(SimpleStatement* statement){
		statements.push_back(statement);
	}
};

class SimpleStatement{
public:
	SimpleStatement(){};
};

// Declaration de variable dans un block
class BlockDeclarationVariable : public SimpleStatement {
private:
	MultipleDeclarationVariable* multipleDeclarationVariable;

public:
	BlockDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	:SimpleStatement(),multipleDeclarationVariable(_multipleDeclarationVariable){};
};

class IterationStatement : public SimpleStatement {
protected:
	Statement* statement;
public:
	IterationStatement(Statement* _statement)
	:SimpleStatement(), statement(_statement){};
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

class UselessStatement : public SimpleStatement {
public:
	UselessStatement():SimpleStatement(){};
};

class ReturnStatement : public SimpleStatement {
private:
	Return* ret;
public:
	ReturnStatement(Return* _ret):SimpleStatement(),ret(_ret){};
};

class DeclarationVariableStatement : public SimpleStatement {
public:
	DeclarationVariableStatement():SimpleStatement(){};
};

class Return {
private:
	Expression* expr;
public:
	Return(Expression* _expr):expr(_expr){};
};

class Statement {
private:
	MultipleStatement* multipleStatement;
public:
	Statement(MultipleStatement* _multipleStatement):multipleStatement(_multipleStatement){};
};

class WhileLoop : public IterationStatement{
private:
	Expression* expr;
public:
	WhileLoop(Expression* _expr, Statement* _statement)
	:expr(_expr)
	,IterationStatement(_statement){};
};

class ForLoop : public IterationStatement {
private:
	LoopExpression* expr1;
	LoopExpression* expr2;
	LoopExpression* expr3;
public:
	ForLoop(LoopExpression* _expr1, LoopExpression* _expr2, LoopExpression* _expr3, Statement* _statement)
	:expr1(_expr1),expr2(_expr2),expr3(_expr3)
	,IterationStatement(_statement){};
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
