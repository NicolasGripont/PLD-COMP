#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <vector>

class Genesis;
class Declaration;
class MultipleDeclarationVariable;
class DeclarationFonction;
class Type;
class Expression;
class DeclarationFonctionStatement;
class ArgumentList;
class MultipleStatement;
class Argument;
class GlobalDeclarationVariable;
class SimpleStatement;
class Return;
class ExpressionVariable;
class Statement;

class Genesis {
public:
	Genesis(){};

	void addDeclaration(Declaration* declaration){
		declarations.push_back(declaration);
	}

	int countDeclaration() {
		return declarations.size();
	}

	Declaration*& operator[] (int i) {
		return declarations[i];
	}
private:
	std::vector<Declaration*> declarations;
};

class Declaration {
public:
	Declaration(){};
};

class DeclarationVariable {
protected:
	char* id;
public:
	DeclarationVariable(char* _id):id(_id){};

	char* getId(){
		return id;
	}
};

class DeclarationInitVariable : public DeclarationVariable {
private:
	Expression* expr;
public:
	DeclarationInitVariable(char* _id, Expression* _expr):DeclarationVariable(_id),expr(_expr){};
};

class DeclarationArrayVariable : public DeclarationVariable {
private:
	int size;
public:
	DeclarationArrayVariable(char* _id, int _size):DeclarationVariable(_id),size(_size){};
};

// Declaration de variable globale
class GlobalDeclarationVariable : public Declaration {
private:
	MultipleDeclarationVariable* multipleDeclarationVariable;

public:
	GlobalDeclarationVariable(MultipleDeclarationVariable* _multipleDeclarationVariable)
	:multipleDeclarationVariable(_multipleDeclarationVariable){};
};

class MultipleDeclarationVariable {
private:
	Type* type;
	std::vector<DeclarationVariable*> declarationsVariables;
public:
	MultipleDeclarationVariable(){};

	void addDeclarationVariable(DeclarationVariable* dec) {
		declarationsVariables.push_back(dec);
	}

	void setType(Type* t){
		type = t;
	}

	int countDeclaration() {
		return declarationsVariables.size();
	}

	DeclarationVariable*& operator[] (int i) {
		return declarationsVariables[i];
	}
};

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

class Type {
public:
	Type(int _type):type(_type){}

	int getType(){
		return type;
	}
private:
	int type;
};

class Expression {
public:
	Expression(){};
};

class FunctionCallExpression : public Expression {
private:
	char* id;
	Expression* expr;
public:
	FunctionCallExpression(char* _id, Expression* _expr)
	:id(_id),expr(_expr),Expression(){};
};

class BinaryOperatorExpression : public Expression {
private:
	Expression* expr1;
	Expression* expr2;
	int op;
public:
	BinaryOperatorExpression(Expression* _expr1, Expression* _expr2, int _op)
	:expr1(_expr1),expr2(_expr1),op(_op),Expression(){};
};

class UnaryOperatorExpression : public Expression {
private:
	Expression* expr;
	int op;
public:
	UnaryOperatorExpression(Expression* _expr, int _op)
	:expr(_expr),op(_op),Expression(){};
};

class ExpressionInteger : public Expression {
private:
	int value;
public:
	ExpressionInteger(int _value):value(_value),Expression(){};
};

class CrementVariable : public Expression {
private:
	ExpressionVariable* exprVar;
	// Si faux, decrement
	bool increment;
	// Si faux, post-crement
	bool preCrement;
public:
	CrementVariable(ExpressionVariable* _exprVar, bool _increment, bool _preCrement)
	:Expression(),exprVar(_exprVar),increment(_increment),preCrement(_preCrement){};
};

class ExpressionVariable : public Expression {
public:
	ExpressionVariable():Expression(){};
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
public:
	DeclarationFonctionStatement(){};
};

// Declaration sans initialisation de la fonction
class PureDeclarationFonctionStatement : public DeclarationFonctionStatement {
public:
	PureDeclarationFonctionStatement():DeclarationFonctionStatement(){};
};

// Initialisation du corps de la fonction
class InitFonctionStatement : public DeclarationFonctionStatement {
private:
	MultipleStatement* multipleStatement;
public:
	InitFonctionStatement(MultipleStatement* _multipleStatement)
	:DeclarationFonctionStatement(),multipleStatement(_multipleStatement){};
};

class ArgumentList {
private:
	std::vector<Argument*> arguments;
public:
	ArgumentList(){};

	void addArgument(Argument* arg){
		arguments.push_back(arg);
	}
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

class Argument {
private:
	Type* type;
	char* id;
	bool isArray;
public:
	Argument(Type* _type, char* _id=nullptr, bool _isArray = false)
	:type(_type),id(_id),isArray(_isArray){};
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

class LoopExpression {
private:
	Expression* expr;
public:
	LoopExpression(Expression* _expr):expr(_expr){};
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
struct VariableContainer {
	char* name;
	int type;

	VariableContainer(char* _name, int _type):
	name(_name),type(_type){};
};

#endif
