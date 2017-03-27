/**********/
/* HEADER */
/**********/
%{
    #include <iostream>
    #include <libgen.h>
	#include <string.h>

    #include "structure/Genesis.h"
    #include "structure/DeclarationVariable.h"
    #include "structure/Type.h"
    #include "structure/MultipleDeclarationVariable.h"
    #include "structure/Argument.h"
    #include "structure/ArgumentList.h"
    #include "structure/Expression.h"
    #include "structure/DeclarationInitVariable.h"

    #include "structure/Expressions.h"

    char* filename;

    extern int yylex(void);
    void yyerror(Genesis** g, const char* msg);
    void yyerror(const char* msg);

    extern FILE* yyin;
    extern int yylineno;
    extern int column;
    extern bool hasSyntaxError;
    extern std::string syntaxError;

    bool variableIsVoid(Type* type);
    std::vector<VariableContainer*> globalVariables;
    std::vector<FunctionContainer*> functions;
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
    DeclarationFonction* df;
    DeclarationVariable* dv;
    Type* type;
    Expression* expr;
    ExpressionVariable* exprVar;
    AssignmentVariable* assignVar;
    DeclarationFonctionStatement* dfs;
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
%token ELLIPSE VOID
%token LEFT_DEC_ASSIGN RIGHT_DEC_ASSIGN
%token PLUS_ASSIGN MINUS_ASSIGN DIV_ASSIGN MUL_ASSIGN
%token MOD_ASSIGN AND_ASSIGN OR_ASSIGN OR_EXCL_ASSIGN
%token RIGHT_DEC LEFT_DEC
%token MORE_THAN LESS_THAN DIFF EQUAL
%token AND OR INCREMENT DECREMENT
%token CHAR INT32 INT64
%token BREAK RETURN CONTINUE WHILE FOR IF ELSE
%token <s> ID
%token <i> INT

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

%left ','
%right RIGHT_DEC_ASSIGN LEFT_DEC_ASSIGN AND_ASSIGN OR_EXCL_ASSIGN OR_ASSIGN
%right '=' PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%right '?' ':'
%left OR
%left AND
%left '|'
%left '^'
%left EQUAL DIFF
%left '<' LESS_THAN '>' MORE_THAN
%left RIGHT_DEC LEFT_DEC
%left '+' '-'
%nonassoc NEG
%right '*' '/' '%'
%right '!' '~' '&'
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
    : type multiple_declaration_variable ';'
    {
        GlobalDeclarationVariable* dec = new GlobalDeclarationVariable($2);
        $$ = dec;
        $2->setType($1);
        if(variableIsVoid($1))
        {
            yyerror(nullptr, "une variable ne peut pas être de type void.");
            YYABORT;
        }
        for(int i=0;i<$2->countDeclaration();++i)
        {
            DeclarationVariable* decVar = (*$2)[i];
            VariableContainer* var = new VariableContainer(decVar->getId(), $1->getType());

            for(int j=0;j<globalVariables.size();j++)
            {
                if(strcmp(globalVariables[i]->name,var->name)==0)
                {
                    yyerror(g, ("la variable globale "+ std::string(var->name)+" a deja ete declaree.").c_str());
                    YYABORT;
                }
            }

            globalVariables.push_back(var);
        }
    }
    | declaration_function {$$ = $1;}
    ;

type
    : VOID {$$ = new Type(VOID);}
    | CHAR {$$ = new Type(CHAR);}
    | INT32 {$$ = new Type(INT32);}
    | INT64 {$$ = new Type(INT64);}
    ;

multiple_declaration_variable
    : declaration_variable {$$ = new MultipleDeclarationVariable(); $$->addDeclarationVariable($1);}
    | multiple_declaration_variable ',' declaration_variable {$$ = $1; $1->addDeclarationVariable($3);}
    ;

declaration_variable
    : ID {$$ = new DeclarationVariable($1);}
    | ID '[' INT ']' {$$ = new DeclarationArrayVariable($1, $3);}
    | ID '=' expression {$$ = new DeclarationInitVariable($1, $3);}
    ;

assignment_variable // utilisé pour affecter une valeur à une variable en dehors de son initialisation (int a; a = 3;)
    : expr_var '=' expression {$$ = new AssignmentVariable($1,$3);}
    | expr_var MUL_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,MUL_ASSIGN);}
    | expr_var DIV_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,DIV_ASSIGN);}
    | expr_var MOD_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,MOD_ASSIGN);}
    | expr_var PLUS_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,PLUS_ASSIGN);}
    | expr_var MINUS_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,MINUS_ASSIGN);}
    | expr_var LEFT_DEC_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,LEFT_DEC_ASSIGN);}
    | expr_var RIGHT_DEC_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,RIGHT_DEC_ASSIGN);}
    | expr_var AND_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,AND_ASSIGN);}
    | expr_var OR_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,OR_ASSIGN);}
    | expr_var OR_EXCL_ASSIGN expression {$$ = new AssignmentOperationVariable($1,$3,OR_EXCL_ASSIGN);}
    ;

declaration_function
    : type ID '(' ')' declaration_function_statement
    {
        $$ = new DeclarationFonction($1, $2, new ArgumentList(), $5);
        FunctionContainer* func;
        bool isDeclaration = $5->isDeclaration();
        func = new FunctionContainer($2, $1->getType(), isDeclaration);

        for(int i=0;i<functions.size();++i)
        {
            FunctionContainer* currFunc = functions[i];
            if(strcmp(func->name, currFunc->name)==0 && !(func->declaration) && !(currFunc->declaration))
            {
                yyerror(g, ("La fonction "+std::string(func->name)+" a déjà été définie.").c_str());
                YYABORT;
            }
        }
        functions.push_back(func);
    }
    | type ID '(' arguments_list ')' declaration_function_statement
    {
        $$ = new DeclarationFonction($1, $2, $4, $6);
        FunctionContainer* func;
        bool isDeclaration = $6->isDeclaration();
        func = new FunctionContainer($2, $1->getType(), isDeclaration);

        for(int i=0;i<functions.size();++i)
        {
            FunctionContainer* currFunc = functions[i];
            if(strcmp(func->name, currFunc->name)==0 && !(func->declaration) && !(currFunc->declaration))
            {
                yyerror(g, ("La fonction "+std::string(func->name)+" a déjà été définie.").c_str());
                YYABORT;
            }
        }
        functions.push_back(func);
    }
    ;

declaration_function_statement
    : ';'  {  $$ = new PureDeclarationFonctionStatement(); }
    | '{' multiple_statement '}' {$$ = new InitFonctionStatement($2);}
    | '{' '}' {$$ = new InitFonctionStatement(new MultipleStatement());}
    ;

argument
    : type {
        $$=new Argument($1);
        if(variableIsVoid($1)){
            yyerror(nullptr, "une variable ne peut pas être de type void.");
            YYABORT;
        }
    }
    | type ID {
        $$=new Argument($1,$2);
        if(variableIsVoid($1)){
            yyerror(nullptr, "une variable ne peut pas être de type void.");
            YYABORT;
        }
    }
    | type ID '[' ']' {
        $$=new Argument($1,$2,true);
        if(variableIsVoid($1)){
            yyerror(nullptr, "une variable ne peut pas être de type void.");
            YYABORT;
        }
    }
    ;

arguments_list
    : argument {$$ = new ArgumentList(); $$->addArgument($1);}
    | arguments_list ',' argument {$$ = $1; $1->addArgument($3);}
    ;

simple_statement
    : iteration_statement {$$ = $1;}
    | selection_statement {$$ = $1;}
    | type multiple_declaration_variable ';' {
        $$ = new BlockDeclarationVariable($2); $2->setType($1);
        if(variableIsVoid($1)){
            yyerror(nullptr, "Une variable ne peut pas être de type void.");
            YYABORT;
        }
    }
    | expression ';' {$$ = new ExpressionStatement($1);}
    | return ';' {$$ = new ReturnStatement($1);}
    | ';'  {$$ = new UselessStatement();}
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
    : WHILE '(' expression ')' statement {$$ = new WhileLoop($3,$5);}
    | FOR '(' loop_expression ';' loop_expression ';' loop_expression ')' statement {$$ = new ForLoop($3,$5,$7,$9);}
    ;

statement
    : '{' multiple_statement '}' {$$ = new Statement($2);}
    | simple_statement {MultipleStatement* mult = new MultipleStatement(); mult->addStatement($1); $$ = new Statement(mult);}
    ;

loop_expression
    : expression {$$ = new LoopExpression($1);}
    | {$$ = new LoopExpression(nullptr);}
    ;

expression
    : '(' expression ')' {$$ = $2;}
    | expression ',' expression  {$$ = new BinaryOperatorExpression($1,$3,',');}
    | expression EQUAL expression {$$ = new BinaryOperatorExpression($1,$3,EQUAL);}
    | expression DIFF expression {$$ = new BinaryOperatorExpression($1,$3,DIFF);}
    | expression '<' expression {$$ = new BinaryOperatorExpression($1,$3,'<');}
    | expression LESS_THAN expression {$$ = new BinaryOperatorExpression($1,$3,LESS_THAN);}
    | expression '>' expression {$$ = new BinaryOperatorExpression($1,$3,'>');}
    | expression MORE_THAN expression {$$ = new BinaryOperatorExpression($1,$3,MORE_THAN);}
    | expression AND expression {$$ = new BinaryOperatorExpression($1,$3,AND);}
    | expression OR expression {$$ = new BinaryOperatorExpression($1,$3,OR);}
    | assignment_variable {$$ = $1;}
    | '+' expression {$$ = new UnaryOperatorExpression($2,'+');}
    | '-' expression %prec NEG {$$ = new UnaryOperatorExpression($2,'-');}
    | '~' expression {$$ = new UnaryOperatorExpression($2,'~');}
    | '!' expression {$$ = new UnaryOperatorExpression($2,'!');}
    | INT {$$ = new ExpressionInteger($1);}
    | INCREMENT expr_var {$$ = new CrementVariable($2, true, true);}
    | DECREMENT expr_var {$$ = new CrementVariable($2, false, true);}
    | expr_var INCREMENT {$$ = new CrementVariable($1, true, false);}
    | expr_var DECREMENT {$$ = new CrementVariable($1, false, false);}
    | expr_var {$$ = $1;}
    | ID '(' expression ')'
    {
        $$ = new FunctionCallExpression($1, $3);
        int state=0;

        for(int i=0;i<functions.size();++i)
        {
            FunctionContainer* currFunc = functions[i];

            // 0 = fonction n'existe pas. 1 = seulement le prototype. 2 = correct


            if(strcmp($1, currFunc->name)==0)
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
            yyerror(g, ("La fonction "+std::string($1)+" n'est pas définie.").c_str());
            YYABORT;
        }

        if(state == 1)
        {
            yyerror(g, ("La fonction "+std::string($1)+" est déclarée mais jamais définie.").c_str());
            YYABORT;
        }
    }
    | ID '(' ')'
    {
        $$ = new FunctionCallExpression($1, nullptr);
        int state=0;

        for(int i=0;i<functions.size();++i)
        {
            FunctionContainer* currFunc = functions[i];

            // 0 = fonction n'existe pas. 1 = seulement le prototype. 2 = correct


            if(strcmp($1, currFunc->name)==0)
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
            yyerror(g, ("La fonction "+std::string($1)+" n'est pas définie.").c_str());
            YYABORT;
        }

        if(state == 1)
        {
            yyerror(g, ("La fonction "+std::string($1)+" est déclarée mais jamais définie.").c_str());
            YYABORT;
        }
    }
    | expression '+' expression {$$ = new BinaryOperatorExpression($1,$3,'+');}
    | expression '-' expression {$$ = new BinaryOperatorExpression($1,$3,'-');}
    | expression '*' expression {$$ = new BinaryOperatorExpression($1,$3,'*');}
    | expression '/' expression {$$ = new BinaryOperatorExpression($1,$3,'/');}
    | expression '%' expression {$$ = new BinaryOperatorExpression($1,$3,'%');}
    | expression '&' expression {$$ = new BinaryOperatorExpression($1,$3,'&');}
    | expression '|' expression {$$ = new BinaryOperatorExpression($1,$3,'|');}
    | expression '^' expression {$$ = new BinaryOperatorExpression($1,$3,'^');}
    | expression LEFT_DEC expression {$$ = new BinaryOperatorExpression($1,$3,LEFT_DEC);}
    | expression RIGHT_DEC expression {$$ = new BinaryOperatorExpression($1,$3,RIGHT_DEC);}
    ;

expr_var
    : ID '[' expression ']' {$$ = new ExpressionArrayVariable($1, $3);}
    | ID {$$ = new ExpressionSimpleVariable($1);}
    ;

selection_statement
    : IF '(' expression ')' statement ELSE statement {$$ = new SelectionStatement($3,$5,$7);}
    | IF '(' expression ')' statement {$$ = new SelectionStatement($3,$5,nullptr);}
    ;

%%

/***********************/
/* PROGRAMME PRINCIPAL */
/***********************/
bool variableIsVoid(Type* type)
{
    return (type->getType() == VOID);
}

void resoudrePortee(Genesis* g)
{
    int countDeclaration = g->countDeclaration();
    for (int i=0 ; i<countDeclaration ; i++)
    {
        Declaration* dec = (*g)[i];
        std::cout << "cocorico" << std::endl;
    }
}

void yyerror(Genesis** g, const char* msg)
{
    if(hasSyntaxError)
    {
        std::cout << filename << ":" << yylineno << "." << column <<" - erreur de syntaxe : " << syntaxError << std::endl;
        hasSyntaxError = false;
    }
    else
    {
        std::cout << filename << ":" << yylineno << "." << column <<" - erreur : " << msg << std::endl;
    }
}

int main(int argc, char* argv[])
{
    // Test parameters
    if (argc <= 1)
    {
        std::cout << "Erreur : pas de nom de fichier donné en entrée." << std::endl;
        std::cout << "Exemple d'utilisation : ~$ ./comp monFichier" << std::endl;
        return 1;
    }

    //yydebug = 1;

    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier '" << argv[1] << "'." << std::endl;
        return 1;
    }

    // Compilation
    std::cout << "Compilation du fichier '" << argv[1] << "' en cours..." << std::endl;

    filename = basename(argv[1]);
    yylineno = 1;

    Genesis* g = 0;
    int status = yyparse(&g);

    //resoudrePortee(g);

    // Error status
    if (status == 0) // Success
    {
        std::cout << "Le fichier correspond à la grammaire." << std::endl << "Compilation terminée avec succès." << std::endl;
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

    return 0;
}
