%{
    #include <string>

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

[ \t\v\r\n\f] 		{ compterColonne(); }
\/\/.*			    { compterColonne(); }
\/\*(.*\n)*.*\*\/	{ compterColonne(); }
^"#"{lettre}+" ".+	{ compterColonne(); }

"..."		{ yylval.i = ELLIPSE; compterColonne(); return ELLIPSE; }

">>="		{ yylval.i = RIGHT_DEC_ASSIGN; compterColonne(); return RIGHT_DEC_ASSIGN; }
"<<="		{ yylval.i = LEFT_DEC_ASSIGN; compterColonne(); return LEFT_DEC_ASSIGN; }

"+="		{ yylval.i = PLUS_ASSIGN; compterColonne(); return PLUS_ASSIGN; }
"-="		{ yylval.i = MINUS_ASSIGN; compterColonne(); return MINUS_ASSIGN; }
"/="		{ yylval.i = DIV_ASSIGN; compterColonne(); return DIV_ASSIGN; }
"*="		{ yylval.i = MUL_ASSIGN; compterColonne(); return MUL_ASSIGN; }
"%="		{ yylval.i = MOD_ASSIGN; compterColonne(); return MOD_ASSIGN; }
"&="		{ yylval.i = AND_ASSIGN; compterColonne(); return AND_ASSIGN; }
"|="		{ yylval.i = OR_ASSIGN; compterColonne(); return OR_ASSIGN; }
"^="		{ yylval.i = OR_EXCL_ASSIGN; compterColonne(); return OR_EXCL_ASSIGN; }

"++"        { yylval.i = INCREMENT; compterColonne(); return INCREMENT; }
"--"        { yylval.i = DECREMENT; compterColonne(); return DECREMENT; }

">>"		{ yylval.i = RIGHT_DEC; compterColonne(); return RIGHT_DEC; }
"<<"		{ yylval.i = LEFT_DEC; compterColonne(); return LEFT_DEC; }

">="        { yylval.i = MORE_THAN_OR_EQUAL; compterColonne(); return MORE_THAN_OR_EQUAL; }/*ATTENTION RENAME MORE_THAN to LESS_THAN_OR_EQUAL*/
"<="        { yylval.i = LESS_THAN_OR_EQUAL; compterColonne(); return LESS_THAN_OR_EQUAL; }/*ATTENTION RENAME LESS_THAN to LESS_THAN_OR_EQUAL*/
"!="        { yylval.i = DIFF; compterColonne(); return DIFF; }
"=="        { yylval.i = EQUAL_EQUAL; compterColonne(); return EQUAL_EQUAL; }/*ATTENTION RENAME EQUAL to EQUAL_EQUAL*/
"&&"        { yylval.i = AND_AND; compterColonne(); return AND_AND; }/*ATTENTION RENAME EQUAL to AND_AND*/
"||"        { yylval.i = OR_OR; compterColonne(); return OR_OR; }/*ATTENTION RENAME EQUAL to OR_OR*/

"="		    { yylval.i = EQUAL; compterColonne(); return EQUAL; }/*ATTENTION RENAME '=' to EQUAL*/
"+"         { yylval.i = PLUS; compterColonne(); return PLUS; }/*ATTENTION RENAME '+' to PLUS*/
"-"         { yylval.i = MINUS; compterColonne(); return MINUS; }/*ATTENTION RENAME '-' to MINUS*/
"/"         { yylval.i = DIV; compterColonne(); return DIV; }/*ATTENTION RENAME '/' to DIV*/
"*"         { yylval.i = MUL; compterColonne(); return MUL; }/*ATTENTION RENAME '*' to MUL*/
"%"         { yylval.i = MOD; compterColonne(); return MOD; }/*ATTENTION RENAME '%' to MOD*/
"&"         { yylval.i = AND; compterColonne(); return AND; }/*ATTENTION RENAME '&' to AND*/
"|"         { yylval.i = OR; compterColonne(); return OR; }/*ATTENTION RENAME '|' to OR*/
"!"         { yylval.i = NOT; compterColonne(); return NOT; }/*ATTENTION RENAME '!' to NOT*/
"~"         { yylval.i = NOT_BIT; compterColonne(); return NOT_BIT; }/*ATTENTION RENAME '~' to NOT_BIT*/
"^"         { yylval.i = POW; compterColonne(); return POW; }/*ATTENTION RENAME '^' to POW*/

">"         { yylval.i = MORE_THAN; compterColonne(); return MORE_THAN; }/*ATTENTION RENAME '>' to MORE_THAN*/
"<"         { yylval.i = LESS_THAN; compterColonne(); return LESS_THAN; }/*ATTENTION RENAME '<' to LESS_THAN*/

";"		    { yylval.i = SEMICOLON; compterColonne(); return SEMICOLON; }/*ATTENTION RENAME ';' to SEMICOLON*/
","		    { yylval.i = COMMA; compterColonne(); return COMMA; }/*ATTENTION RENAME ',' to COMMA*/

"{"         { yylval.i = OPEN_BRACE; compterColonne(); return OPEN_BRACE; }/*ATTENTION RENAME '{' to OPEN_BRACE*/
"}"         { yylval.i = CLOSE_BRACE; compterColonne(); return CLOSE_BRACE; }/*ATTENTION RENAME '}' to CLOSE_BRACE*/
"("         { yylval.i = OPEN_PARENTHESIS; compterColonne(); return OPEN_PARENTHESIS; }/*ATTENTION RENAME '(' to OPEN_PARENTHESIS*/
")"	        { yylval.i = CLOSE_PARENTHESIS; compterColonne(); return CLOSE_PARENTHESIS; }/*ATTENTION RENAME ')' to CLOSE_PARENTHESIS*/
"["         { yylval.i = OPEN_HOOK; compterColonne(); return OPEN_HOOK; }/*ATTENTION RENAME '[' to OPEN_HOOK*/
"]"		    { yylval.i = CLOSE_HOOK; compterColonne(); return CLOSE_HOOK; }/*ATTENTION RENAME ']' to CLOSE_HOOK*/

"void"		{ yylval.i = VOID; compterColonne(); return VOID; }
"char"		{ yylval.i = CHAR; compterColonne(); return CHAR; }
"int32_t"	{ yylval.i = INT32; compterColonne(); return INT32; }
"int64_t"	{ yylval.i = INT64; compterColonne(); return INT64; }

"break"		{ yylval.i = BREAK; compterColonne(); return BREAK; }
"return"	{ yylval.i = RETURN; compterColonne(); return RETURN; }
"continue"	{ yylval.i = CONTINUE; compterColonne(); return CONTINUE; }
"while"		{ yylval.i = WHILE; compterColonne(); return WHILE; }
"for"		{ yylval.i = FOR; compterColonne(); return FOR; }
"if"		{ yylval.i = IF; compterColonne(); return IF; }
"else"		{ yylval.i = ELSE; compterColonne(); return ELSE; }

{quote}{lettre}{quote} { compterColonne(); yylval.i = yytext[1]; return INT; }

{quote}\\b{quote} { compterColonne(); yylval.i = '\b'; return INT; }
{quote}\\f{quote} { compterColonne(); yylval.i = '\f'; return INT; }
{quote}\\n{quote} { compterColonne(); yylval.i = '\n'; return INT; }
{quote}\\r{quote} { compterColonne(); yylval.i = '\r'; return INT; }
{quote}\\t{quote} { compterColonne(); yylval.i = '\t'; return INT; }
{quote}\\v{quote} { compterColonne(); yylval.i = '\v'; return INT; }
{quote}\\\\{quote} { compterColonne(); yylval.i = '\\'; return INT; }
{quote}\\'{quote} { compterColonne(); yylval.i = '\''; return INT; }
{quote}\\\"{quote} { compterColonne(); yylval.i = '\"'; return INT; }
{quote}\\\?{quote} { compterColonne(); yylval.i = '\?'; return INT; }
{quote}\\e{quote} { compterColonne(); yylval.i = '\e'; return INT; }

({lettre}|{underscore})({lettre}|{chiffre}|{underscore})* { compterColonne(); yylval.s = strdup(yytext); return ID; }
{chiffre}+ { compterColonne(); yylval.i = atoi(yytext); return INT; }

"/*" { compterColonne(); leverErreurSyntaxe("commentaire '/*' non fermé."); return yytext[0]; }
"int "|"float "|"double "|"signed "|"unsigned "|"long " { compterColonne(); leverErreurSyntaxe("type invalide. '" + std::string(yytext) + "' n'est pas reconnu. Essayez int32_t."); return yytext[0]; }

. { compterColonne(); leverErreurSyntaxe("symbole '" + std::string(yytext) + "' non reconnu."); return yytext[0]; }

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
