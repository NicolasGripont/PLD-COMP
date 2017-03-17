%{
    #include <string>
    
	using namespace std;
    
	#include "comp.tab.h"
%}
%option noyywrap

chiffre	   [0-9]
lettre	   [a-zA-Z]
underscore _

%%

[ \n\t]      		{ /* ignore */ }
\/\/.*			    { /* ignore */ }
\/\*(.*\n)*.*\*\/	{ /* ignore */ }
^"#"{lettre}+" ".+	{ /* ignore */ }

"..."		return ELLIPSE;

">>="		return RIGHT_DEC_ASSIGN;
"<<="		return LEFT_DEC_ASSIGN;

"+="		return PLUS_ASSIGN;
"-="		return MINUS_ASSIGN;
"/="		return DIV_ASSIGN;
"*="		return MUL_ASSIGN;
"%="		return MOD_ASSIGN;
"&="		return AND_ASSIGN;
"|="		return OR_ASSIGN;
"^="		return OR_EXCL_ASSIGN;

"++"        return INCREMENT;
"--"        return DECREMENT;

">>"		return RIGHT_DEC;
"<<"		return LEFT_DEC;

">="        return MORE_THAN;
"<="        return LESS_THAN;
"!="        return DIFF;
"=="        return EQUAL;
"&&"        return AND;
"||"        return OR;

"="		    return '=';
"+"         return '+';
"-"         return '-';
"/"         return '/';
"*"         return '*';
"%"         return '%';
"&"         return '&';
"|"         return '|';
"!"         return '!';
"~"         return '~';
"^"         return '^';

">"         return '>';
"<"         return '<';

";"		    return ';';
","		    return ',';

"{"         return '{';
"}"         return '}';
"("         return '(';
")"	        return ')';
"["         return '[';
"]"		    return ']';

"void"		return VOID;
"char"		return CHAR;
"int32_t"	return INT32;
"int64_t"	return INT64;

"break"		return BREAK;
"return"	return RETURN;
"continue"	return CONTINUE;
"while"		return WHILE;
"for"		return FOR;
"if"		return IF;
"else"		return ELSE;

({lettre}|{underscore})({lettre}|{chiffre}|{underscore})* return ID;
{chiffre}+ { yylval.i = atoi(yytext);
             return INT; }

%%
