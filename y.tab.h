/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEC_OP = 258,                  /* DEC_OP  */
    INC_OP = 259,                  /* INC_OP  */
    OR_OP = 260,                   /* OR_OP  */
    AND_OP = 261,                  /* AND_OP  */
    ELSE = 262,                    /* ELSE  */
    IF = 263,                      /* IF  */
    INT = 264,                     /* INT  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    WHILE = 267,                   /* WHILE  */
    DOUBLE = 268,                  /* DOUBLE  */
    TRUE = 269,                    /* TRUE  */
    FALSE = 270,                   /* FALSE  */
    BREAK = 271,                   /* BREAK  */
    CHAR = 272,                    /* CHAR  */
    BOOL = 273,                    /* BOOL  */
    ID = 274,                      /* ID  */
    CONST_INT = 275,               /* CONST_INT  */
    CONST_DOUBLE = 276,            /* CONST_DOUBLE  */
    STRING = 277,                  /* STRING  */
    EQUAL = 278,                   /* EQUAL  */
    LESS_EQUAL = 279,              /* LESS_EQUAL  */
    GREATER_EQUAL = 280,           /* GREATER_EQUAL  */
    NOT_EQUAL = 281,               /* NOT_EQUAL  */
    ADD_OP = 282,                  /* ADD_OP  */
    SUB_OP = 283,                  /* SUB_OP  */
    MUL_OP = 284,                  /* MUL_OP  */
    DIV_OP = 285,                  /* DIV_OP  */
    LESS = 286,                    /* LESS  */
    GREATER = 287,                 /* GREATER  */
    MOD_OP = 288,                  /* MOD_OP  */
    SEMICOLON = 289,               /* SEMICOLON  */
    COMMA = 290,                   /* COMMA  */
    LEFT_PARE = 291,               /* LEFT_PARE  */
    RIGHT_PARE = 292,              /* RIGHT_PARE  */
    LEFT_BRA = 293,                /* LEFT_BRA  */
    RIGHT_BRA = 294,               /* RIGHT_BRA  */
    LEFT_BRACE = 295,              /* LEFT_BRACE  */
    RIGHT_BRACE = 296,             /* RIGHT_BRACE  */
    ASSIGN = 297,                  /* ASSIGN  */
    LOWER_THAN_ELSE = 298          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DEC_OP 258
#define INC_OP 259
#define OR_OP 260
#define AND_OP 261
#define ELSE 262
#define IF 263
#define INT 264
#define RETURN 265
#define VOID 266
#define WHILE 267
#define DOUBLE 268
#define TRUE 269
#define FALSE 270
#define BREAK 271
#define CHAR 272
#define BOOL 273
#define ID 274
#define CONST_INT 275
#define CONST_DOUBLE 276
#define STRING 277
#define EQUAL 278
#define LESS_EQUAL 279
#define GREATER_EQUAL 280
#define NOT_EQUAL 281
#define ADD_OP 282
#define SUB_OP 283
#define MUL_OP 284
#define DIV_OP 285
#define LESS 286
#define GREATER 287
#define MOD_OP 288
#define SEMICOLON 289
#define COMMA 290
#define LEFT_PARE 291
#define RIGHT_PARE 292
#define LEFT_BRA 293
#define RIGHT_BRA 294
#define LEFT_BRACE 295
#define RIGHT_BRACE 296
#define ASSIGN 297
#define LOWER_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "project.y"

    class SyntaxTree* syntaxtree;

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
