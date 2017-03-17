/**********/
/* HEADER */
/**********/
%{
    #include <cstdio>
    #include <iostream>

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
%token DEC_GAUCHE_AFFECT DEC_DROITE_AFFECT
%token PLUS_AFFECT MOINS_AFFECT DIV_AFFECT MUL_AFFECT
%token MOD_AFFECT ET_AFFECT OU_AFFECT OU_EXCL_AFFECT
%token DEC_DROITE DEC_GAUCHE
%token SUPERIEUR_EGAL INFERIEUR_EGAL DIFF EGAL
%token ET OU INCREMENT DECREMENT
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
%right DEC_DROITE_AFFECT DEC_GAUCHE_AFFECT ET_AFFECT OU_EXCL_AFFECT OU_AFFECT
%right '=' PLUS_AFFECT MOINS_AFFECT MUL_AFFECT DIV_AFFECT MOD_AFFECT
%right '?' ':'
%left OU
%left ET
%left '|'
%left '^'
%left EGAL DIFF
%left '<' INFERIEUR_EGAL '>' SUPERIEUR_EGAL
%left DEC_DROITE DEC_GAUCHE
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
    | '{' multiple_statement '}'
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
    : expr_var MUL_AFFECT expression
    : expr_var DIV_AFFECT expression
    : expr_var MOD_AFFECT expression
    : expr_var PLUS_AFFECT expression
    : expr_var MOINS_AFFECT expression
    : expr_var DEC_GAUCHE_AFFECT expression
    : expr_var DEC_DROITE_AFFECT expression
    : expr_var ET_AFFECT expression
    : expr_var OU_EXCL_AFFECT expression
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
    | type declaration_variable ';'
    | expression ';'
    | return ';'
    | ';'
    ;

multiple_statement
    : multiple_statement statement
    | statement
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
    | expression EGAL expression
    | expression DIFF expression
    | expression '<' expression
    | expression INFERIEUR_EGAL expression
    | expression '>' expression
    | expression SUPERIEUR_EGAL expression
    | expression ET expression
    | expression OU expression
    | assignment_variable
    | '-' expression %prec NEG
    | '~' expression
    | '!' expression
    | INT
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
    | expression DEC_GAUCHE expression
    | expression DEC_DROITE expression
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
