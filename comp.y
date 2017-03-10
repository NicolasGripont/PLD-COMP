/**********/
/* HEADER */
/**********/
%{
    #include <stdlib.h>
    #include <stdio.h>

    extern int yylex(void);
    void yyerror(int* res, const char* msg);
%}
/**************/
/* STRUCTURES */
/**************/


/**********/
/* TOKENS */
/**********/
%token ELLIPSE VOID
%token DEC_GAUCHE_AFFECT DEC_DROITE_AFFECT
%token PLUS_AFFECT MOINS_AFFECT DIV_AFFECT MUL_AFFECT
%token MOD_AFFECT ET_AFFECT OU_AFFECT OU_EXCL_AFFECT
%token DEC_DROITE_AFFECT DEC_GAUCHE_AFFECT
%token SUPERIEUR_EGAL INFERIEUR_EGAL DIFF EGAL
%token ET OU INCREMENT DECREMENT
%token CHAR INT32 INT64
%token BREAK CONTINUE DO WHILE IF ELSE

/*********/
/* TYPES */
/*********/


/************/
/* PRIORITY */
/************/
// Pour la priorité des opérateurs qui a été définie
// Voir https://c.developpez.com/cours/bernard-cassagne/node101.php#footmp10620
/*
%left INCREMENT DECREMENT
%right '!' '~' '-' '+' '&'
%right '*' '/' '%'
%left '+' '-'
%left DEC_DROITE DEC_GAUCHE
%left '<' INFERIEUR_EGAL '>' SUPERIEUR_EGAL
%left EGAL DIFF
%left '^'
%left '|'
%left ET
%left OU
%right '?' ':'
%right '=' PLUS_AFFECT MOINS_AFFECT MUL_AFFECT DIV_AFFECT MOD_AFFECT
%right DEC_DROITE_AFFECT DEC_GAUCHE_AFFECT ET_AFFECT OU_EXCL_AFFECT OU_AFFECT
%left ','
*/

/**************/
/* PARAMETERS */
/**************/


/***********/
/* GRAMMAR */
/***********/
%%
program :
    genesis
    ;

genesis
    : genesis declaration
    | declaration
    | '{' multiple_statement '}'
    ;

declaration
    : type_variable multiple_declaration_variable ';'
    | declaration_function
    ;

type_variable
    : 'CHAR'
    | 'INT32'
    | 'INT64'
    ;

multiple_declaration_variable
    : declaration_variable
    | multiple_declaration_variable ',' declaration_variable
    ;

declaration_variable
    : ID
    | ID '[' CONSTANT ']'
    | ID '=' expression
    ;

assignment_variable // utilisé pour affecter une valeur à une variable en dehors de son initialisation (int a; a = 3;)
    : expr_var operator_asignement expression
    ;

operator_assignment
    : '='
    | MUL_AFFECT
    | DIV_AFFECT
    | MOD_AFFECT
    | PLUS_AFFECT
    | MOINS_AFFECT
    | DEC_GAUCHE_AFFECT
    | DEC_DROITE_AFFECT
    | ET_AFFECT
    | OU_EXCL_AFFECT
    ;

declaration_function
    : type_function ID '(' ')' declaration_function_statement
    | type_function ID '(' 'VOID' ')' declaration_function_statement
    | type_function ID '(' arguments_list ')' declaration_function_statement
    ;

declaration_function_statement
    : ';'
    | '{' multiple_statement '}'
    ;


type_function
    : type_variable 
    | 'VOID'
    ;

argument
    : type_variable
    | type_variable ID
    | type_variable ID '[' ']'
    ;

arguments_list
: argument
| arguments_list ',' argument


simple_statement
    : iteration_statement
    | selection_statement
    | type_variable declaration_variable ';'
    | expression ';'
    | return ';'
    | ';'
    ;

multiple_statement
    : multiple_statement statement
    | statement
;


return
    : 'RETURN'
    | 'RETURN' expression
;

iteration_statement
    : 'WHILE' '(' expression ')' statement
    | 'FOR' '(' loop_expression ';' loop_expression ';' loop_expression ')' statement
    ;

statement
    : '{' multiple_statement '}'
    | simple_statement
    ;

loop_expression
    : expression
    | ε
    ; 

operator_comparison
    : EGAL
    | DIFF
    | '<'
    | INFERIEUR_EGAL
    | '>'
    | SUPERIEUR_EGAL
    ;

expression
    : '(' expression ')'
    | expression ',' expression
    | expression operator_comparison expression
    | expression operator_agregation expression
    | assignment_variable
    | unary_operator expression
    | expression binary_operator expression
    | CONSTANT
    | operator_crementation expr_var
    | expr_var operator_crementation 
    | expr_var
    | ID '(' argument_list_call ')'
    | ID '(' ')'
    ;

expr_var
    : ID '[' expression ']'
    | ID
;

selection_statement
    : 'IF' '(' expression ')' statement 'ELSE' statement
    | 'IF' '(' expression ')' statement
    ;

argument_list_call
    : expression
    | argument_list_call ',' expression
    ;

operator_crementation
    : INCREMENT
    | DECREMENT
    ;

binary_operator
    : '+'
    | '-'
    | '*'
    | '/'
    | '%'
    | '&'
    | '|'
    | '^'
    | DEC_GAUCHE
    | DEC_DROITE
    ;

unary_operator
    : '-'
    | '~'
    | '!'
    ;

operator_agregation
    : ET
    | OU
    ;
%%

/***********************/
/* PROGRAMME PRINCIPAL */
/***********************/
void yyerror(int* res, const char* msg)
{
    printf("Syntax error: %s\n", msg);
}

int main(int arg, char* argv[])
{
    int res = 0;
    //yydebug = 1;
    yyparse(&res);

    printf("Result: %d\n", res);

    return 0;
}
