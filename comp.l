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

">>="		return DEC_DROITE_AFFECT;
"<<="		return DEC_GAUCHE_AFFECT;

"+="		return PLUS_AFFECT;
"-="		return MOINS_AFFECT;
"/="		return DIV_AFFECT;
"*="		return MUL_AFFECT;
"%="		return MOD_AFFECT;
"&="		return ET_AFFECT;
"|="		return OU_AFFECT;
"^="		return OU_EXCL_AFFECT;

"++"        return INCREMENT;
"--"        return DECREMENT;

">>"		return DEC_DROITE;
"<<"		return DEC_GAUCHE;

">="        return SUPERIEUR_EGAL;
"<="        return INFERIEUR_EGAL;
"!="        return DIFF;
"=="        return EGAL;
"&&"        return ET;
"||"        return OU;

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

"?"         return '?';
":"         return ':';

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
"do"		return DO;
"while"		return WHILE;
"for"		return FOR;
"if"		return IF;
"else"		return ELSE;

({lettre}|{underscore})({lettre}|{chiffre}|{underscore})* return ID;
{chiffre}+ { yylval.i = atoi(yytext);
             return INT; }

%%
