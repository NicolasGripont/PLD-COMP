/**********/
/* HEADER */
/**********/
%{
    #include <cstdio>
    #include <iostream>
    
    #include "structure/header/Genesis.h"

    using namespace std;

    extern int yylex(void);
    void yyerror(const char* msg);
    
    extern FILE* yyin;
%}

/**************/
/* STRUCTURES */
/**************/
%union {
    int i;
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
%token ID INT

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

//%parse-param {}

/***********/
/* GRAMMAR */
/***********/
%%

program
    : genesis
    ;

genesis
    : genesis declaration
    | declaration
    ;

declaration
    : type multiple_declaration_variable ';'
    | declaration_function
    ;

type
    : VOID
    | CHAR
    | INT32
    | INT64
    ;

multiple_declaration_variable
    : declaration_variable
    | multiple_declaration_variable ',' declaration_variable
    ;

declaration_variable
    : ID
    | ID '[' INT ']'
    | ID '=' expression
    ;

assignment_variable // utilisé pour affecter une valeur à une variable en dehors de son initialisation (int a; a = 3;)
    : expr_var '=' expression
    : expr_var MUL_ASSIGN expression
    : expr_var DIV_ASSIGN expression
    : expr_var MOD_ASSIGN expression
    : expr_var PLUS_ASSIGN expression
    : expr_var MINUS_ASSIGN expression
    : expr_var LEFT_DEC_ASSIGN expression
    : expr_var RIGHT_DEC_ASSIGN expression
    : expr_var AND_ASSIGN expression
    : expr_var OR_EXCL_ASSIGN expression
    ;

declaration_function
    : type ID '(' ')' declaration_function_statement
    | type ID '(' arguments_list ')' declaration_function_statement
    ;

declaration_function_statement
    : ';'
    | '{' multiple_statement '}'
    ;

argument
    : type
    | type ID
    | type ID '[' ']'
    ;

arguments_list
    : argument
    | arguments_list ',' argument
    ;

simple_statement
    : iteration_statement
    | selection_statement
    | type multiple_declaration_variable ';'
    | expression ';'
    | return ';'
    | ';'
    ;

multiple_statement
    : multiple_statement simple_statement
    | simple_statement
    ;

return
    : RETURN
    | RETURN expression
    ;

iteration_statement
    : WHILE '(' expression ')' statement
    | FOR '(' loop_expression ';' loop_expression ';' loop_expression ')' statement
    ;

statement
    : '{' multiple_statement '}'
    | simple_statement
    ;

loop_expression
    : expression
    |
    ; 

expression
    : '(' expression ')'
    | expression ',' expression
    | expression EQUAL expression
    | expression DIFF expression
    | expression '<' expression
    | expression LESS_THAN expression
    | expression '>' expression
    | expression MORE_THAN expression
    | expression AND expression
    | expression OR expression
    | assignment_variable
    | '-' expression %prec NEG
    | '~' expression
    | '!' expression
    | INT
    | '\'' CHAR '\''
    | INCREMENT expr_var
    | DECREMENT expr_var
    | expr_var INCREMENT 
    | expr_var DECREMENT 
    | expr_var
    | ID '(' expression ')'
    | ID '(' ')'
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | expression '%' expression
    | expression '&' expression
    | expression '|' expression
    | expression '^' expression
    | expression LEFT_DEC expression
    | expression RIGHT_DEC expression
    ;

expr_var
    : ID '[' expression ']'
    | ID
    ;

selection_statement
    : IF '(' expression ')' statement ELSE statement
    | IF '(' expression ')' statement
    ;

%%

/***********************/
/* PROGRAMME PRINCIPAL */
/***********************/
void yyerror(const char* msg)
{
    cout << "Syntax error: " << msg << endl;
}

int main(int argc, char* argv[])
{
    cout << " -=[ Compilator ]=- " << endl;
    
    // Test parameters
    if (argc <= 1)
    {
        cout << "Error: no input filename given." << endl;
        cout << "Example of use: ~$ ./comp codeFile" << endl;
        return 1;
    }
    
    // Compilation
    cout << "Compilation of file '" << argv[1] << "'..." << endl;
    
    //yydebug = 1;
    
    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        printf("Error: unable to open file '%s'.\n", argv[1]);
        return 1;
    }
    
    yyparse();
    
    cout << "Compilation finished." << endl;
    return 0;
}
