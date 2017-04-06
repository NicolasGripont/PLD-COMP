/**********/
/* HEADER */
/**********/
%code requires{
    #include <iostream>
    #include <stack>
    #include <libgen.h>
    #include <string.h>
    #include <unordered_map>

    #include "front_end/Enumeration.h"
    #include "front_end/Genesis.h"
    #include "front_end/DeclarationVariable.h"
    #include "front_end/Type.h"
    #include "front_end/MultipleDeclarationVariable.h"
    #include "front_end/Argument.h"
    #include "front_end/ArgumentList.h"
    #include "front_end/Expression.h"
    #include "front_end/DeclarationInitVariable.h"
    #include "front_end/DeclarationArrayVariable.h"
    #include "front_end/GlobalDeclarationVariable.h"
    #include "front_end/FunctionCallExpression.h"
    #include "front_end/BinaryOperatorExpression.h"
    #include "front_end/UnaryOperatorExpression.h"
    #include "front_end/ExpressionInteger.h"
    #include "front_end/CrementVariable.h"

    #include "front_end/DeclarationFunctionStatement.h"
    #include "front_end/DeclarationFunction.h"
    #include "front_end/ExpressionVariable.h"
    #include "front_end/ExpressionArrayVariable.h"
    #include "front_end/AssignmentVariable.h"
    #include "front_end/AssignmentOperationVariable.h"
    #include "front_end/Return.h"
    #include "front_end/SimpleStatement.h"
    #include "front_end/ReturnStatement.h"
    #include "front_end/UselessStatement.h"
    #include "front_end/MultipleStatement.h"
    #include "front_end/Statement.h"
    #include "front_end/InitFunctionStatement.h"
    #include "front_end/BlockDeclarationVariable.h"
    #include "front_end/IterationStatement.h"
    #include "front_end/SelectionStatement.h"
    #include "front_end/ExpressionStatement.h"
    #include "front_end/PureDeclarationFunctionStatement.h"
    #include "front_end/LoopExpression.h"
    #include "front_end/WhileLoop.h"

    #include "front_end/ForLoop.h"

    #include "front_end/Erreur.h"

    Genesis* bison(int argc, char* argv[]);
}
%{
    #include "comp.tab.h"

    char* filename;

    extern int yylex(void);
    extern int yylex_destroy(void);
    void yyerror(Genesis** g, const char* msg);
    void yyerror(const char* msg);
    void yywarning(const char* msg);

    extern FILE* yyin;
    extern int yylineno;
    extern int column;
    // Utilisé pour les déclarations de variables
    int currVariableType;
    extern bool hasSyntaxError;
    extern std::string syntaxError;

    bool variableIsVoid(Genesis** g, Type* type);
    bool tryCallFunction(Genesis** g, char* functionName);
    bool tryDeclareGlobalVariable(Genesis** g,Type* type, MultipleDeclarationVariable* multDecl);
    bool tryDefineFunction(Genesis** g, Type* type, char* name, bool isDeclaration, ArgumentList* args);
    bool checkVariableDuplicationInFunction(Genesis** g, char* functionName, ArgumentList* args, DeclarationFunctionStatement* declFunc);
    bool checkVariableDuplicationInBlock(Genesis** g, MultipleStatement* multStat);

    int getFunctionType(char* name);
    // Si on a plusieurs fois une variable de même nom,
    // renvoi le type de celle du bloc courant
    int getVariableType(char* name);
    void pushVariablesInStack(Type* type, MultipleDeclarationVariable* multDecl);
    void pushVariablesInStack(Argument* arg);
    void popVariablesFromStack(ArgumentList* args, DeclarationFunctionStatement* stat);
    void popStatVariablesFromStack(MultipleStatement* stat);
    void popSimpleStatVariablesFromStack(SimpleStatement* stat);

    std::vector<VariableContainer*> globalVariables;
    std::vector<FunctionContainer*> functions;
    // Une "pile" des variables locales courantes (rempli et vidé au fur et a mesure)
    std::vector<VariableContainer*> currentVars;

    // Donne le type primitif correspondant à un type tableau (ex: INT32[] -> INT32)
    int primitiveToArrayType(int type);
    // Donne le type tableau correspondant à un type primitif (ex: INT32 -> INT32[])
    int arrayToPrimitiveType(int type);

    bool checkConflictError(Genesis** g, Expression* expr1, Expression* expr2);
    void checkAssignmentConstant(int leftExpressionType, Expression* rightExpression);
    bool checkArrayTypeConflitError(Genesis** g, int type1, int type2);
    std::string getNameOfType(int type);
    bool checkVariableExist(Genesis** g, char* name);

    struct FunctionCall
    {
        std::string functionName;
        int line;
        int column;

        FunctionCall(std::string _functionName, int _line, int _column)
            : functionName(_functionName), line(_line), column(_column)
        {
        }
    };
    std::unordered_map<std::string, FunctionCall*> calledFunctions;
    std::unordered_map<std::string, FunctionCall*> undefinedFunctionCall;
    bool checkUndeclaredFunctionErrors();
    bool checkUndefinedFunctionErrors();
%}

/**************/
/* STRUCTURES */
/**************/
%union {
    int i;
    char* s;

    Genesis* g;
    Declaration* d;
    MultipleDeclarationVariable* mdv;

    DeclarationFunction* df;
    DeclarationVariable* dv;
    Type* type;
    Expression* expr;
    ExpressionVariable* exprVar;
    AssignmentVariable* assignVar;

    DeclarationFunctionStatement* dfs;
    ArgumentList* al;
    MultipleStatement* ms;
    Argument* arg;
    SimpleStatement* ss;
    IterationStatement* iss;
    SelectionStatement* sss;
    Return* ret;
    Statement* stat;
    LoopExpression* loopexpr;
}

/**********/
/* TOKENS */
/**********/
// Liste des tokens issus de Flex (comp.l)
%token <s> ID
%token <i> INT
%token <ival> ELLIPSE
%token <ival> RIGHT_DEC_ASSIGN
%token <ival> LEFT_DEC_ASSIGN
%token <ival> PLUS_ASSIGN
%token <ival> MINUS_ASSIGN
%token <ival> DIV_ASSIGN
%token <ival> MUL_ASSIGN
%token <ival> MOD_ASSIGN
%token <ival> AND_ASSIGN
%token <ival> OR_ASSIGN
%token <ival> OR_EXCL_ASSIGN
%token <ival> INCREMENT
%token <ival> DECREMENT
%token <ival> RIGHT_DEC
%token <ival> LEFT_DEC
%token <ival> MORE_THAN_OR_EQUAL
%token <ival> LESS_THAN_OR_EQUAL
%token <ival> DIFF
%token <ival> EQUAL_EQUAL
%token <ival> AND_AND
%token <ival> OR_OR
%token <ival> EQUAL
%token <ival> PLUS
%token <ival> MINUS
%token <ival> DIV
%token <ival> MUL
%token <ival> MOD
%token <ival> AND
%token <ival> OR
%token <ival> NOT
%token <ival> NOT_BIT
%token <ival> POW
%token <ival> MORE_THAN
%token <ival> LESS_THAN
%token <ival> SEMICOLON
%token <ival> COMMA
%token <ival> OPEN_BRACE
%token <ival> CLOSE_BRACE
%token <ival> OPEN_PARENTHESIS
%token <ival> CLOSE_PARENTHESIS
%token <ival> OPEN_HOOK
%token <ival> CLOSE_HOOK
%token <ival> VOID
%token <ival> CHAR
%token <ival> INT32
%token <ival> INT64
%token <ival> BREAK
%token <ival> RETURN
%token <ival> CONTINUE
%token <ival> WHILE
%token <ival> FOR
%token <ival> IF
%token <ival> ELSE
%token <ival> CHAR_ARRAY
%token <ival> INT32_ARRAY
%token <ival> INT64_ARRAY

// Type permettant la création de la structure de données
%type <g> genesis
%type <d> declaration
%type <mdv> multiple_declaration_variable
%type <df> declaration_function
%type <dv> declaration_variable
%type <type> type
%type <expr> expression
%type <exprVar> expr_var
%type <assignVar> assignment_variable
%type <dfs> declaration_function_statement
%type <al> arguments_list
%type <ms> multiple_statement
%type <arg> argument
%type <ss> simple_statement
%type <iss> iteration_statement
%type <sss> selection_statement
%type <ret> return
%type <stat> statement
%type <loopexpr> loop_expression

/*********/
/* TYPES */
/*********/


/************/
/* PRIORITY */
/************/
// Pour la priorité des opérateurs qui a été définie
// Voir https://c.developpez.com/cours/bernard-cassagne/node101.php#footmp10620

%left COMMA
%right RIGHT_DEC_ASSIGN LEFT_DEC_ASSIGN AND_ASSIGN OR_EXCL_ASSIGN OR_ASSIGN
%right EQUAL PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR_OR
%left AND_AND
%left OR
%left POW
%left EQUAL_EQUAL DIFF
%left MORE_THAN LESS_THAN_OR_EQUAL LESS_THAN MORE_THAN_OR_EQUAL
%left RIGHT_DEC LEFT_DEC
%left PLUS MINUS
%nonassoc NEG
%right MUL DIV MOD
%right NOT NOT_BIT AND
%left INCREMENT DECREMENT

/**************/
/* PARAMETERS */
/**************/

%parse-param { Genesis** g }

/***********/
/* GRAMMAR */
/***********/
%%

program
    : genesis {*g = $1;}
    ;

genesis
    : genesis declaration {$$ = $1; $$->addDeclaration($2);}
    | declaration {$$ = new Genesis(); $$->addDeclaration($1);}
    ;

declaration
    : type multiple_declaration_variable SEMICOLON
    {
        GlobalDeclarationVariable* dec = new GlobalDeclarationVariable($2);
        $$ = dec;
        $2->setType($1);
        if(variableIsVoid(g,$1)) YYABORT;
        if(!tryDeclareGlobalVariable(g,$1,$2)) YYABORT;
    }
    | declaration_function {$$ = $1;}
    ;

type
    : VOID {$$ = new Type(VOID); currVariableType = VOID;}
    | CHAR {$$ = new Type(CHAR); currVariableType = CHAR;}
    | INT32 {$$ = new Type(INT32); currVariableType = INT32;}
    | INT64 {$$ = new Type(INT64); currVariableType = INT64;}
    ;

multiple_declaration_variable
    : declaration_variable {$$ = new MultipleDeclarationVariable(); $$->addDeclarationVariable($1);}
    | multiple_declaration_variable COMMA declaration_variable {$$ = $1; $1->addDeclarationVariable($3);}
    ;

declaration_variable
    : ID {$$ = new DeclarationVariable($1,false);}
    | ID OPEN_HOOK INT CLOSE_HOOK {$$ = new DeclarationArrayVariable($1, $3);}
    | ID EQUAL expression
    {
        $$ = new DeclarationInitVariable($1, $3);
        int type1 = currVariableType;
        int type2 = $3->getType();
        if(checkArrayTypeConflitError(g,type1,type2)) YYABORT;
        // Si on a pas une constante à droite
        checkAssignmentConstant(type1, $3);
    }
    ;

assignment_variable // utilisé pour affecter une valeur à une variable en dehors de son initialisation (int a; a = 3;)
    : expr_var EQUAL expression {$$ = new AssignmentVariable($1,$3);if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var MUL_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,MUL_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var DIV_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,DIV_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var MOD_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,MOD_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var PLUS_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,PLUS_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var MINUS_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,MINUS_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var LEFT_DEC_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,LEFT_DEC_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var RIGHT_DEC_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,RIGHT_DEC_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var AND_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,AND_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var OR_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,OR_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    | expr_var OR_EXCL_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,OR_EXCL_ASSIGN); if(checkArrayTypeConflitError(g,$1->getType(),$3->getType())) YYABORT; checkAssignmentConstant($1->getType(), $3);}
    ;

declaration_function
    : type ID OPEN_PARENTHESIS CLOSE_PARENTHESIS declaration_function_statement
    {
        ArgumentList* args = new ArgumentList();
        $$ = new DeclarationFunction($1, $2, args, $5);
        if(!tryDefineFunction(g,$1,$2,$5->isDeclaration(), args)) YYABORT;
        if(checkVariableDuplicationInFunction(g,$2,args,$5)) YYABORT;
        if(checkUndeclaredFunctionErrors()) YYABORT;
        popVariablesFromStack(nullptr,$5);
    }
    | type ID OPEN_PARENTHESIS arguments_list CLOSE_PARENTHESIS declaration_function_statement
    {
        $$ = new DeclarationFunction($1, $2, $4, $6);
        if(!tryDefineFunction(g,$1,$2,$6->isDeclaration(),$4)) YYABORT;
        if(checkVariableDuplicationInFunction(g,$2,$4,$6)) YYABORT;
        popVariablesFromStack($4,$6);
    }
    ;

declaration_function_statement
    : SEMICOLON {  $$ = new PureDeclarationFunctionStatement(); }
    | OPEN_BRACE multiple_statement CLOSE_BRACE { $$ = new InitFunctionStatement($2); }
    | OPEN_BRACE CLOSE_BRACE {$$ = new InitFunctionStatement(new MultipleStatement());}
    ;

argument
    : type {
        $$=new Argument($1);
        if(variableIsVoid(g, $1)) YYABORT;
    }
    | type ID {
        $$=new Argument($1,$2);
        if(variableIsVoid(g, $1)) YYABORT;
    }
    | type ID OPEN_HOOK CLOSE_HOOK {
        $$=new Argument($1,$2,true);
        if(variableIsVoid(g, $1)) YYABORT;
    }
    ;

arguments_list
    : argument
    {
        $$ = new ArgumentList(); $$->addArgument($1);
        pushVariablesInStack($1);
    }
    | arguments_list COMMA argument
    {
        $$ = $1; $1->addArgument($3);
        pushVariablesInStack($3);
    }
    ;

simple_statement
    : iteration_statement {$$ = $1;}
    | selection_statement {$$ = $1;}

    | type multiple_declaration_variable SEMICOLON
    {
        $$ = new BlockDeclarationVariable($2); $2->setType($1);
        if(variableIsVoid(g, $1)) YYABORT;
        pushVariablesInStack($1,$2);
    }
    | expression SEMICOLON {$$ = new ExpressionStatement($1);}
    | return SEMICOLON {$$ = new ReturnStatement($1);}
    | SEMICOLON  {$$ = new UselessStatement();}
    ;

multiple_statement
    : multiple_statement simple_statement {$$ = $1; $1->addStatement($2);}
    | simple_statement {$$ = new MultipleStatement(); $$->addStatement($1);}
    ;

return
    : RETURN {$$ = new Return(nullptr);}
    | RETURN expression  {$$ = new Return($2);}
    ;

iteration_statement
    : WHILE OPEN_PARENTHESIS expression CLOSE_PARENTHESIS statement {$$ = new WhileLoop($3,$5);}
    | WHILE OPEN_PARENTHESIS expression CLOSE_PARENTHESIS OPEN_BRACE CLOSE_BRACE {$$ = new WhileLoop($3,nullptr);}
    | FOR OPEN_PARENTHESIS loop_expression SEMICOLON loop_expression SEMICOLON loop_expression CLOSE_PARENTHESIS statement {$$ = new ForLoop($3,$5,$7,$9);}
    | FOR OPEN_PARENTHESIS loop_expression SEMICOLON loop_expression SEMICOLON loop_expression CLOSE_PARENTHESIS OPEN_BRACE CLOSE_BRACE {$$ = new ForLoop($3,$5,$7,nullptr);}
    ;

statement
    : OPEN_BRACE multiple_statement CLOSE_BRACE
    {
        $$ = new Statement($2);
        if(checkVariableDuplicationInBlock(g,$2)) YYABORT;
        popStatVariablesFromStack($2);
    }
    | simple_statement
    {
        MultipleStatement* mult = new MultipleStatement();
        mult->addStatement($1);
        $$ = new Statement(mult);
        popSimpleStatVariablesFromStack($1);
    }
    ;

loop_expression
    : expression {$$ = new LoopExpression($1);}
    | {$$ = new LoopExpression(nullptr);}
    ;

expression
    : OPEN_PARENTHESIS expression CLOSE_PARENTHESIS {$$ = $2;}
    | expression COMMA expression  {$$ = new BinaryOperatorExpression($1,$3,COMMA); }
    | expression EQUAL_EQUAL expression {$$ = new BinaryOperatorExpression($1,$3,EQUAL_EQUAL,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression DIFF expression {$$ = new BinaryOperatorExpression($1,$3,DIFF,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression LESS_THAN expression {$$ = new BinaryOperatorExpression($1,$3,LESS_THAN,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression LESS_THAN_OR_EQUAL expression {$$ = new BinaryOperatorExpression($1,$3,LESS_THAN_OR_EQUAL,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression MORE_THAN expression {$$ = new BinaryOperatorExpression($1,$3,MORE_THAN,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression MORE_THAN_OR_EQUAL expression {$$ = new BinaryOperatorExpression($1,$3,MORE_THAN_OR_EQUAL,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression AND_AND expression {$$ = new BinaryOperatorExpression($1,$3,AND_AND,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression OR_OR expression {$$ = new BinaryOperatorExpression($1,$3,OR_OR,INT32); if(checkConflictError(g,$1,$3)) YYABORT;}
    | assignment_variable {$$ = $1;}
    | PLUS expression {$$ = new UnaryOperatorExpression($2,PLUS);}
    | MINUS expression %prec NEG {$$ = new UnaryOperatorExpression($2,MINUS);}
    | NOT_BIT expression {$$ = new UnaryOperatorExpression($2,NOT_BIT);}
    | NOT expression {$$ = new UnaryOperatorExpression($2,NOT);}
    | INT {$$ = new ExpressionInteger($1,INT32);}
    | INCREMENT expr_var {$$ = new CrementVariable($2, true, true);}
    | DECREMENT expr_var {$$ = new CrementVariable($2, false, true);}
    | expr_var INCREMENT {$$ = new CrementVariable($1, true, false);}
    | expr_var DECREMENT {$$ = new CrementVariable($1, false, false);}
    | expr_var {$$ = $1;}
    | ID OPEN_PARENTHESIS expression CLOSE_PARENTHESIS
    {
        if(!tryCallFunction(g, $1)) YYABORT;
        $$ = new FunctionCallExpression($1, $3, getFunctionType($1));
    }
    | ID OPEN_PARENTHESIS CLOSE_PARENTHESIS
    {
        if(!tryCallFunction(g, $1)) YYABORT;
        $$ = new FunctionCallExpression($1, nullptr, getFunctionType($1));
    }
    | expression PLUS expression {$$ = new BinaryOperatorExpression($1,$3,PLUS); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression MINUS expression {$$ = new BinaryOperatorExpression($1,$3,MINUS); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression MUL expression {$$ = new BinaryOperatorExpression($1,$3,MUL); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression DIV expression {$$ = new BinaryOperatorExpression($1,$3,DIV); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression MOD expression {$$ = new BinaryOperatorExpression($1,$3,MOD); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression AND expression {$$ = new BinaryOperatorExpression($1,$3,AND); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression OR expression {$$ = new BinaryOperatorExpression($1,$3,OR); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression POW expression {$$ = new BinaryOperatorExpression($1,$3,POW); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression LEFT_DEC expression {$$ = new BinaryOperatorExpression($1,$3,LEFT_DEC); if(checkConflictError(g,$1,$3)) YYABORT;}
    | expression RIGHT_DEC expression {$$ = new BinaryOperatorExpression($1,$3,RIGHT_DEC); if(checkConflictError(g,$1,$3)) YYABORT;}
    ;

expr_var
    : ID OPEN_HOOK expression CLOSE_HOOK
    {
        if(!checkVariableExist(g,$1)) YYABORT;
        if(!isArrayType(getVariableType($1)))
        {
            yyerror(g, ("tentative d'utilisation de l'opérateur indice de tableau sur la variable non-tableau "+std::string($1)+".").c_str());
            YYABORT;
        }
        $$ = new ExpressionArrayVariable($1, $3, arrayToPrimitiveType(getVariableType($1)));
    }
    | ID
    {
        if(!checkVariableExist(g,$1)) YYABORT;
	$$ = new ExpressionVariable($1, getVariableType($1));
    }
    ;

selection_statement
    : IF OPEN_PARENTHESIS expression CLOSE_PARENTHESIS statement ELSE statement {$$ = new SelectionStatement($3,$5,$7);}
    | IF OPEN_PARENTHESIS expression CLOSE_PARENTHESIS statement {$$ = new SelectionStatement($3,$5,nullptr);}
    | IF OPEN_PARENTHESIS expression CLOSE_PARENTHESIS OPEN_BRACE CLOSE_BRACE {$$ = new SelectionStatement($3,nullptr,nullptr);}
    ;

%%

/***********************/
/* PROGRAMME PRINCIPAL */
/***********************/
bool variableIsVoid(Genesis** g, Type* type)
{
    if (type->getType() == VOID)
    {
        yyerror(g, "Une variable ne peut pas être de type void.");
        return true;
    }
    return false;
}

bool checkUndeclaredFunctionErrors()
{
    // On retire chaque fonction définie du set des fonctions appellées
    for(int i=0;i<functions.size();++i)
    {
        FunctionContainer* currFunc = functions[i];

        auto it = undefinedFunctionCall.find(std::string(currFunc->name));
        if (it != undefinedFunctionCall.end())
        {
            undefinedFunctionCall.erase(std::string(currFunc->name));

            if(currFunc->declaration)
            {
                calledFunctions.insert(std::make_pair(std::string(currFunc->name),it->second));
            }
            else
            {
                delete(it->second);
            }
        }
    }

    int error = false;
    for (auto& pair: undefinedFunctionCall)
    {
        FunctionCall* func = pair.second;
        std::cout << filename << ":" << func->line << ":" << func->column <<" - erreur : "
        << "La fonction " << std::string(func->functionName) << " n'a pas été déclarée." << std::endl;

        delete(func);
        error = true;
    }

    return error;
}

bool checkUndefinedFunctionErrors()
{
    // On retire chaque fonction définie du set des fonctions appellées
    for(int i=0;i<functions.size();++i)
    {
        FunctionContainer* currFunc = functions[i];

        if(!currFunc->declaration)
        {
            auto it = calledFunctions.find(std::string(currFunc->name));
            if (it != calledFunctions.end())
            {
                delete(it->second);
                calledFunctions.erase(std::string(currFunc->name));
            }
        }
    }

    int error = false;
    for (auto& pair: calledFunctions)
    {
        FunctionCall* func = pair.second;
        std::cout << filename << ":" << func->line << ":" << func->column <<" - erreur : "
        << "Référence indéfinie vers la fonction " << std::string(func->functionName) << "." << std::endl;

        delete(func);
        error = true;
    }

    return error;
}

bool tryCallFunction(Genesis** g, char* functionName)
{
    int state=0;

    if(strcmp(functionName, "putchar")==0
    || strcmp(functionName, "getchar")==0)
    {
        return true;
    }

    for(int i=0;i<functions.size();++i)
    {
        FunctionContainer* currFunc = functions[i];

        // 0 = fonction n'existe pas. 1 = seulement le prototype. 2 = correct
        if(strcmp(functionName, currFunc->name)==0)
        {
            if(currFunc->declaration)
            {
                state = 1;
            }
            else
            {
                state = 2;
                break;
            }
        }
    }

    if(state == 0)
    {
        // Ajouter à la liste des fonctions non-définies
        // (à checker dès qu'on sort de la fonction)
        FunctionCall* call = new FunctionCall(functionName, yylineno, column);
        undefinedFunctionCall.insert(std::make_pair(std::string(functionName),call));
    }

    if(state == 1)
    {
        // Ajouter à la liste des fonctions appellées, mais pas définies
        // (à checker à la fin si on a bien défini le corps de la fonction)
        FunctionCall* call = new FunctionCall(functionName, yylineno, column);
        calledFunctions.insert(std::make_pair(std::string(functionName),call));
    }

    return true;
}

bool tryDeclareGlobalVariable(Genesis** g, Type* type, MultipleDeclarationVariable* multDecl)
{
    for(int i=0;i<multDecl->countDeclaration();++i)
    {
        DeclarationVariable* decVar = (*multDecl)[i];
        VariableContainer* var = new VariableContainer(decVar->getId(), type->getType());

        for(int j=0;j<globalVariables.size();j++)
        {
            if(strcmp(globalVariables[i]->name,var->name)==0)
            {
                yyerror(g, ("la variable globale "+ std::string(var->name)+" a deja ete declaree.").c_str());
                delete var;
                return false;
            }
        }

        if(!decVar->isDeclaration())
        {
            DeclarationInitVariable* initVar = (DeclarationInitVariable*)decVar;
            if(initVar->getExpr()->getExpressionType() != EXPRESSION_INTEGER)
            {
                yyerror(g, "Impossible d'assigner une expression non-constante à une variable globale.");
                delete var;
                return false;
            }
        }

        globalVariables.push_back(var);
    }
    return true;
}


bool tryDefineFunction(Genesis** g, Type* type, char* name, bool isDeclaration, ArgumentList* args)
{
    FunctionContainer* func;

    func = new FunctionContainer(name, type->getType(), isDeclaration, args);

    for(int i=0;i<functions.size();++i)
    {
        FunctionContainer* currFunc = functions[i];

        if(strcmp(func->name, currFunc->name)==0)
        {
            // Check si le type de retour est identique
            if(func->type != currFunc->type)
            {
                yyerror(g, ("La fonction "+std::string(func->name)+" a déjà été déclarée avec un type de retour différent.").c_str());
                delete func;
                return false;
            }

            // Check si les paramètres d'appel sont identiques
            if(func->args->countArguments() != currFunc->args->countArguments())
            {
                yyerror(g, ("La fonction "+std::string(func->name)+" a déjà été déclarée avec un nombre de paramètres différent.").c_str());
                delete func;
                return false;
            }

            for(int j=0;j<func->args->countArguments();++j)
            {
                int type1 = (*(func->args))[j]->getType()->getType();
                int type2 = (*(currFunc->args))[j]->getType()->getType();

                if(type1 != type2)
                {
                    yyerror(g, ("La fonction "+std::string(func->name)+" a déjà été déclarée avec des paramètres différents.").c_str());
                    yyerror(g, (std::string("(Argument n°")+std::to_string(j)+", type "+getNameOfType(type1)+" au lieu de "+getNameOfType(type2)+".").c_str());
                    delete func;
                    return false;
                }
            }
        }

        if(strcmp(func->name, currFunc->name)==0 && !(func->declaration) && !(currFunc->declaration))
        {
            yyerror(g, ("La fonction "+std::string(func->name)+" a déjà été définie.").c_str());
            delete func;
            return false;
        }
    }
    functions.push_back(func);
    return true;
}

bool checkVariableDuplicationInFunction(Genesis** g, char* functionName, ArgumentList* args, DeclarationFunctionStatement* declFunc)
{
    std::vector<VariableContainer*> variables;

    // Test doublons au sein des paramètres de la fonction
    for(int i=0;i<args->countArguments();++i)
    {
        Argument* arg = (*args)[i];

        if(arg->getName() == nullptr)
        {
            continue;
        }

        VariableContainer* var = new VariableContainer(arg->getName(), arg->getType()->getType());

        for(int j=0;j<variables.size();++j)
        {
            VariableContainer* currVar = variables[j];
            if(strcmp(var->name, currVar->name) == 0)
            {
                yyerror(g, ("La fonction "+std::string(functionName)+" contient plusieurs paramètres nommés "+std::string(var->name)).c_str());
                delete var;
                return true;
            }
        }
        variables.push_back(var);
    }

    // Si on dispose du corps de la fonction
    if(!declFunc->isDeclaration())
    {
        InitFunctionStatement* funcBody = (InitFunctionStatement*)declFunc;
        for(int i=0;i<funcBody->countStatements();++i)
        {
            SimpleStatement* stat = (*funcBody)[i];
            if(stat->getType() == BLOCK_DECLARATION_VARIABLE)
            {
                BlockDeclarationVariable* blockDeclVar = (BlockDeclarationVariable*) stat;
                MultipleDeclarationVariable* multDecl = blockDeclVar->getMultipleDeclarationVariable();
                for(int j=0;j<multDecl->countDeclaration();++j)
                {
                    DeclarationVariable* decVar = (*multDecl)[j];
                    VariableContainer* var = new VariableContainer(decVar->getId(), multDecl->getType()->getType());
                    // Regarder si la variable existe déjà
                    for(int k=0;k<variables.size();++k)
                    {
                        VariableContainer* currVar = variables[k];
                        if(strcmp(var->name, currVar->name) == 0)
                        {
                            yyerror(g, ("La fonction "+std::string(functionName)+" contient plusieurs variables nommé "+std::string(var->name)+" dans la même portée.").c_str());
                            delete var;
                            return true;
                        }
                    }

                    variables.push_back(var);
                }
            }
        }
    }

    return false;
}

bool checkVariableDuplicationInBlock(Genesis** g, MultipleStatement* multStat)
{
    std::vector<VariableContainer*> variables;

    for(int i=0;i<multStat->countStatements();++i)
    {
        SimpleStatement* stat = (*multStat)[i];
        if(stat->getType() == BLOCK_DECLARATION_VARIABLE)
        {
            BlockDeclarationVariable* blockDeclVar = (BlockDeclarationVariable*) stat;
            MultipleDeclarationVariable* multDecl = blockDeclVar->getMultipleDeclarationVariable();
            for(int j=0;j<multDecl->countDeclaration();++j)
            {
                DeclarationVariable* decVar = (*multDecl)[j];
                VariableContainer* var = new VariableContainer(decVar->getId(), multDecl->getType()->getType());

                // Regarder si la variable existe déjà
                for(int k=0;k<variables.size();++k)
                {

                    VariableContainer* currVar = variables[k];
                    if(strcmp(var->name, currVar->name) == 0)
                    {
                        yyerror(g, ("Plusieurs variables nommé "+std::string(var->name)+" dans la même portée.").c_str());
                        delete var;
                        return true;
                    }
                }
                variables.push_back(var);
            }
        }
    }

    return false;
}

int getFunctionType(char* name)
{
    if(strcmp(name,"putchar")==0)
    {
        return INT32;
    }
    if(strcmp(name,"getchar")==0)
    {
        return INT32;
    }

    for(int i=0;i<functions.size();++i)
    {
        FunctionContainer* func = functions[i];
        if(strcmp(name,func->name)==0)
        {
            return func->type;
        }
    }
    return INT32;
}

int getVariableType(char* name)
{
    // Recherche dans les variables locales
    for(int i=currentVars.size()-1;i>=0;--i)
    {
        VariableContainer* var = currentVars[i];
        if(strcmp(name,var->name)==0)
        {
            return var->type;
        }
    }

    // Recherche dans les variables globales
    for(int i=0;i<globalVariables.size();++i)
    {
        VariableContainer* var = globalVariables[i];
        if(strcmp(name,var->name)==0)
        {
            return var->type;
        }
    }

    return INT32;
}

void pushVariablesInStack(Type* type, MultipleDeclarationVariable* multDecl)
{
    int typeVar = type->getType();
    for(int i=0;i<multDecl->countDeclaration();++i)
    {
        DeclarationVariable* decVar = (*multDecl)[i];

        if(decVar->isArray())
        {
            typeVar = primitiveToArrayType(typeVar);
        }

        VariableContainer* var = new VariableContainer(decVar->getId(), typeVar);
        currentVars.push_back(var);
    }
}

bool checkVariableExist(Genesis** g, char* name)
{
    for(int i=0;i<currentVars.size();++i)
    {
        if(strcmp(name,currentVars[i]->name)==0)
        {
            return true;
        }
    }

    for(int i=0;i<globalVariables.size();++i)
    {
        if(strcmp(name,globalVariables[i]->name)==0)
        {
            return true;
        }
    }
    yyerror(g, ("La variable "+std::string(name)+" est utilisée mais jamais définie.").c_str());
    return false;
}

void pushVariablesInStack(Argument* arg)
{
    int typeVar = arg->getType()->getType();
    if(arg->isArray())
    {
        typeVar = primitiveToArrayType(typeVar);
    }
    VariableContainer* var = new VariableContainer(arg->getName(), typeVar);
    currentVars.push_back(var);
}

void popVariablesFromStack(ArgumentList* args, DeclarationFunctionStatement* stat)
{
    int countVars = 0;
    if(args != nullptr)
    {
        countVars += args->countArguments();
    }

    // Si on dispose du corps de la fonction
    if(!stat->isDeclaration())
    {
        InitFunctionStatement* funcBody = (InitFunctionStatement*)stat;
        for(int i=0;i<funcBody->countStatements();++i)
        {
            SimpleStatement* stat = (*funcBody)[i];
            if(stat->getType() == BLOCK_DECLARATION_VARIABLE)
            {
                BlockDeclarationVariable* blockDeclVar = (BlockDeclarationVariable*) stat;
                MultipleDeclarationVariable* multDecl = blockDeclVar->getMultipleDeclarationVariable();
                countVars += multDecl->countDeclaration();
            }
        }
    }

    for(int i=0;i<countVars;++i)
    {
        VariableContainer* var = currentVars.back();
        currentVars.pop_back();
        delete var;
    }
}

void popSimpleStatVariablesFromStack(SimpleStatement* stat)
{
    if(stat->getType() == BLOCK_DECLARATION_VARIABLE)
    {
        BlockDeclarationVariable* blockDeclVar = (BlockDeclarationVariable*) stat;
        MultipleDeclarationVariable* multDecl = blockDeclVar->getMultipleDeclarationVariable();
        int countVars = multDecl->countDeclaration();

        for(int i=0;i<countVars;++i)
        {
            VariableContainer* var = currentVars.back();
            currentVars.pop_back();
            delete var;
        }
    }
}

void popStatVariablesFromStack(MultipleStatement* stats)
{
    int countVars = 0;
    for(int i=0;i<stats->countStatements();++i)
    {
        SimpleStatement* stat = (*stats)[i];
        if(stat->getType() == BLOCK_DECLARATION_VARIABLE)
        {
            BlockDeclarationVariable* blockDeclVar = (BlockDeclarationVariable*) stat;
            MultipleDeclarationVariable* multDecl = blockDeclVar->getMultipleDeclarationVariable();
            countVars += multDecl->countDeclaration();
        }
    }

    for(int i=0;i<countVars;++i)
    {
        VariableContainer* var = currentVars.back();
        currentVars.pop_back();
        delete var;
    }
}

int primitiveToArrayType(int type)
{
    switch(type)
    {
        case INT64:
            return INT64_ARRAY;
        case CHAR:
            return CHAR_ARRAY;
        case INT32:
        default:
            return INT32_ARRAY;
    }
}

int arrayToPrimitiveType(int type)
{
    switch(type)
    {
        case INT64_ARRAY:
            return INT64;
        case CHAR_ARRAY:
            return CHAR;
        case INT32_ARRAY:
        default:
            return INT32;
    }
}

void yyerror(Genesis** g, const char* msg)
{
    if(hasSyntaxError)
    {
        std::cout << filename << ":" << yylineno << ":" << column <<" - erreur de syntaxe : " << syntaxError << std::endl;
        hasSyntaxError = false;
    }
    else
    {
        std::cout << filename << ":" << yylineno << ":" << column <<" - erreur : " << msg << std::endl;
    }
}

void yywarning(const char* msg)
{
    std::cout << filename << ":" << yylineno << ":" << column <<" - warning : " << msg << std::endl;
}

bool checkConflictError(Genesis** g, Expression* expr1, Expression* expr2)
{
    int type1 = expr1->getType();
    int type2 = expr2->getType();

    // Si un est un tableau et l'autre non -> erreur
    // Si elles sont tableau mais de type different
    if((isArrayType(type1) != isArrayType(type2))
    || (isArrayType(type1) && isArrayType(type2) && (type1 != type2)))
    {
        yyerror(g, ("Expression de type "+getNameOfType(type1)+
        " incompatible avec une expression de type "+getNameOfType(type2)).c_str());
        return true;
    }

    // Si elle sont simple variable de type different -> warning
    if(type1 != type2)
    {
        yywarning(("Expression de type "+getNameOfType(type1)+
        " associée à une expression de type "+getNameOfType(type2)+". Conversion.").c_str());
        return false;
    }
    return false;
}

void checkAssignmentConstant(int leftExpressionType, Expression* rightExpression)
{
    int type1 = leftExpressionType;
    int type2 = rightExpression->getType();
    if(rightExpression->getExpressionType() != EXPRESSION_INTEGER)
    {
        // Et que les type de variable et le type de l'expression de droite
        // sont differents, warning (cast)
        if(type1 != type2)
        {
            yywarning(("Expression de type "+getNameOfType(type1)+
            " associée à une expression de type "+getNameOfType(type2)+". Conversion.").c_str());
        }
    }
    else
    {
        // Le type de la constante de droite prend le type de la variable
        rightExpression->setType(type1);
    }
}

bool checkArrayTypeConflitError(Genesis** g, int type1, int type2)
{
    if(type1 == VOID)
    {
        yyerror(g, "Variable de type void !");
        return true;
    }

    if(type2 == VOID)
    {
        yyerror(g, "Impossible d'affecter une expression de type void.");
        return true;
    }

    // Si un est un tableau et l'autre non -> erreur
    // Si elles sont tableau mais de type different
    if((isArrayType(type1) != isArrayType(type2))
    || (isArrayType(type1) && isArrayType(type2) && (type1 != type2)))
    {
        yyerror(g, ("Expression de type "+getNameOfType(type1)+
        " incompatible avec une expression de type "+getNameOfType(type2)).c_str());
        return true;
    }

    return false;
}

std::string getNameOfType(int type)
{
    switch(type)
    {
    case INT64_ARRAY:
        return "int64_t[]";
    case CHAR_ARRAY:
        return "char[]";
    case INT32_ARRAY:
        return "int32_t[]";
    case INT64:
        return "int64_t";
    case CHAR:
        return "char";
    case INT32:
    default:
        return "int32_t";
    }
}

Genesis* bison(int argc, char* argv[])
{
    int result = 0;
    currVariableType = INT32;

    // Test parameters
    if (argc <= 1)
    {
        std::cout << "Erreur : pas de nom de fichier donné en entrée." << std::endl;
        std::cout << "Exemple d'utilisation : ~$ ./comp monFichier" << std::endl;
        return nullptr;
    }

    //yydebug = 1;

    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier '" << argv[1] << "'." << std::endl;
        return nullptr;
    }

    // Compilation
    std::cout << "Compilation du fichier '" << argv[1] << "' en cours..." << std::endl;

    filename = basename(argv[1]);
    yylineno = 1;

    Genesis* g = 0;
    int status = yyparse(&g);
    fclose(yyin);
    yylex_destroy();

    if(checkUndefinedFunctionErrors())
    {
        status = 3;
    }

    // Error status
    if (status == 0) // Success
    {
        std::cout << "Le fichier correspond à la grammaire." << std::endl << "Compilation terminée avec succès." << std::endl;
        std::cout << g << std::endl;
    }
    else if (status == 1) // Syntax error
    {
        std::cout << "Compilation abandonnée (erreur de syntaxe)." << std::endl;
    }
    else if (status == 2) // Out of memory
    {
        std::cout << "Compilation abandonnée (mémoire insuffisante)." << std::endl;
    }
    else
    {
        std::cout << "Compilation abandonnée." << std::endl;
    }

    if(status != 0)
    {
        if(g != nullptr)
        {
            delete g;
            g = nullptr;
        }
    }

    for(int i=0; i < globalVariables.size(); i++)
    {
        delete globalVariables[i];
    }
    for(int i=0; i < functions.size(); i++)
    {
        delete functions[i];
    }
    for(int i=0; i < currentVars.size(); i++)
    {
        delete currentVars[i];
    }

    return g;
}
