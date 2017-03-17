/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ELLIPSE = 258,
     VOID = 259,
     DEC_GAUCHE_AFFECT = 260,
     DEC_DROITE_AFFECT = 261,
     PLUS_AFFECT = 262,
     MOINS_AFFECT = 263,
     DIV_AFFECT = 264,
     MUL_AFFECT = 265,
     MOD_AFFECT = 266,
     ET_AFFECT = 267,
     OU_AFFECT = 268,
     OU_EXCL_AFFECT = 269,
     DEC_DROITE = 270,
     DEC_GAUCHE = 271,
     SUPERIEUR_EGAL = 272,
     INFERIEUR_EGAL = 273,
     DIFF = 274,
     EGAL = 275,
     ET = 276,
     OU = 277,
     INCREMENT = 278,
     DECREMENT = 279,
     CHAR = 280,
     INT32 = 281,
     INT64 = 282,
     BREAK = 283,
     RETURN = 284,
     CONTINUE = 285,
     WHILE = 286,
     FOR = 287,
     IF = 288,
     ELSE = 289,
     ID = 290,
     INT = 291,
     NEG = 292
   };
#endif
/* Tokens.  */
#define ELLIPSE 258
#define VOID 259
#define DEC_GAUCHE_AFFECT 260
#define DEC_DROITE_AFFECT 261
#define PLUS_AFFECT 262
#define MOINS_AFFECT 263
#define DIV_AFFECT 264
#define MUL_AFFECT 265
#define MOD_AFFECT 266
#define ET_AFFECT 267
#define OU_AFFECT 268
#define OU_EXCL_AFFECT 269
#define DEC_DROITE 270
#define DEC_GAUCHE 271
#define SUPERIEUR_EGAL 272
#define INFERIEUR_EGAL 273
#define DIFF 274
#define EGAL 275
#define ET 276
#define OU 277
#define INCREMENT 278
#define DECREMENT 279
#define CHAR 280
#define INT32 281
#define INT64 282
#define BREAK 283
#define RETURN 284
#define CONTINUE 285
#define WHILE 286
#define FOR 287
#define IF 288
#define ELSE 289
#define ID 290
#define INT 291
#define NEG 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "comp.y"
{
    int i;
}
/* Line 1529 of yacc.c.  */
#line 127 "comp.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

