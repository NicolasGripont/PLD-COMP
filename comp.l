%{
    #include <string>
    
	using namespace std;
    
    #include "structure/header/Genesis.h"
	#include "comp.tab.h"

	void compterColonne();
	void leverErreurSyntaxe(std::string);
%}
%option noyywrap
%option yylineno

chiffre	   [0-9]
lettre	   [a-zA-Z]
underscore _
quote '

%%

[ \t\v\n\f] 		{ compterColonne(); }
\/\/.*			    { compterColonne(); }
\/\*(.*\n)*.*\*\/	{ compterColonne(); }
^"#"{lettre}+" ".+	{ compterColonne(); }

"..."		{ compterColonne(); return ELLIPSE;}

">>="		{ compterColonne(); return RIGHT_DEC_ASSIGN;}
"<<="		{ compterColonne(); return LEFT_DEC_ASSIGN;}

"+="		{ compterColonne(); return PLUS_ASSIGN;}
"-="		{ compterColonne(); return MINUS_ASSIGN;}
"/="		{ compterColonne(); return DIV_ASSIGN;}
"*="		{ compterColonne(); return MUL_ASSIGN;}
"%="		{ compterColonne(); return MOD_ASSIGN;}
"&="		{ compterColonne(); return AND_ASSIGN;}
"|="		{ compterColonne(); return OR_ASSIGN;}
"^="		{ compterColonne(); return OR_EXCL_ASSIGN;}

"++"        { compterColonne(); return INCREMENT;}
"--"        { compterColonne(); return DECREMENT;}

">>"		{ compterColonne(); return RIGHT_DEC;}
"<<"		{ compterColonne(); return LEFT_DEC;}

">="        { compterColonne(); return MORE_THAN;}
"<="        { compterColonne(); return LESS_THAN;}
"!="        { compterColonne(); return DIFF;}
"=="        { compterColonne(); return EQUAL;}
"&&"        { compterColonne(); return AND;}
"||"        { compterColonne(); return OR;}

"="		    { compterColonne(); return '=';}
"+"         { compterColonne(); return '+';}
"-"         { compterColonne(); return '-';}
"/"         { compterColonne(); return '/';}
"*"         { compterColonne(); return '*';}
"%"         { compterColonne(); return '%';}
"&"         { compterColonne(); return '&';}
"|"         { compterColonne(); return '|';}
"!"         { compterColonne(); return '!';}
"~"         { compterColonne(); return '~';}
"^"         { compterColonne(); return '^';}

">"         { compterColonne(); return '>';}
"<"         { compterColonne(); return '<';}

";"		    { compterColonne(); return ';';}
","		    { compterColonne(); return ',';}

"{"         { compterColonne(); return '{';}
"}"         { compterColonne(); return '}';}
"("         { compterColonne(); return '(';}
")"	        { compterColonne(); return ')';}
"["         { compterColonne(); return '[';}
"]"		    { compterColonne(); return ']';}

"void"		{ compterColonne(); return VOID;}
"char"		{ compterColonne(); return CHAR;}
"int32_t"	{ compterColonne(); return INT32;}
"int64_t"	{ compterColonne(); return INT64;}

"break"		{ compterColonne(); return BREAK;}
"return"	{ compterColonne(); return RETURN;}
"continue"	{ compterColonne(); return CONTINUE;}
"while"		{ compterColonne(); return WHILE;}
"for"		{ compterColonne(); return FOR;}
"if"		{ compterColonne(); return IF;}
"else"		{ compterColonne(); return ELSE;}

{quote}{lettre}{quote} { compterColonne(); yylval.i = yytext[1]; return INT; }
({lettre}|{underscore})({lettre}|{chiffre}|{underscore})* { compterColonne(); return ID;}
{chiffre}+ 	{ compterColonne(); yylval.i = atoi(yytext); return INT; }

"/*"  { compterColonne(); leverErreurSyntaxe("Commentaire '/*' non fermé"); return yytext[0];}

.     { compterColonne(); leverErreurSyntaxe("Symbole non reconnu : "+std::string(yytext)); return yytext[0];}

%%

int column = 0;
int nextColumn = 0;
bool hasSyntaxError = false;
std::string syntaxError;

void leverErreurSyntaxe(std::string err)
{
	hasSyntaxError = true;
	syntaxError = err;
}

void compterColonne()
{
	column = nextColumn;

	int i;

	for (i = 0; yytext[i] != '\0'; ++i, ++nextColumn)
		if (yytext[i] == '\n')
			nextColumn = 0;
}