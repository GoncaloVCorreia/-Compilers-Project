/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
    FUNC = 258,                    /* FUNC  */
    PACKAGE = 259,                 /* PACKAGE  */
    SEMICOLON = 260,               /* SEMICOLON  */
    COMMA = 261,                   /* COMMA  */
    BLANKID = 262,                 /* BLANKID  */
    ASSIGN = 263,                  /* ASSIGN  */
    STAR = 264,                    /* STAR  */
    DIV = 265,                     /* DIV  */
    MINUS = 266,                   /* MINUS  */
    PLUS = 267,                    /* PLUS  */
    EQ = 268,                      /* EQ  */
    GE = 269,                      /* GE  */
    GT = 270,                      /* GT  */
    LBRACE = 271,                  /* LBRACE  */
    RBRACE = 272,                  /* RBRACE  */
    LE = 273,                      /* LE  */
    RPAR = 274,                    /* RPAR  */
    LPAR = 275,                    /* LPAR  */
    LSQ = 276,                     /* LSQ  */
    LT = 277,                      /* LT  */
    MOD = 278,                     /* MOD  */
    NE = 279,                      /* NE  */
    NOT = 280,                     /* NOT  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    RSQ = 283,                     /* RSQ  */
    RETURN = 284,                  /* RETURN  */
    ELSE = 285,                    /* ELSE  */
    FOR = 286,                     /* FOR  */
    IF = 287,                      /* IF  */
    VAR = 288,                     /* VAR  */
    INT = 289,                     /* INT  */
    FLOAT32 = 290,                 /* FLOAT32  */
    BOOL = 291,                    /* BOOL  */
    STRING = 292,                  /* STRING  */
    PRINT = 293,                   /* PRINT  */
    PARSEINT = 294,                /* PARSEINT  */
    CMDARGS = 295,                 /* CMDARGS  */
    INTLIT = 296,                  /* INTLIT  */
    REALLIT = 297,                 /* REALLIT  */
    RESERVED = 298,                /* RESERVED  */
    STRLIT = 299,                  /* STRLIT  */
    ID = 300,                      /* ID  */
    UNARY = 301                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define FUNC 258
#define PACKAGE 259
#define SEMICOLON 260
#define COMMA 261
#define BLANKID 262
#define ASSIGN 263
#define STAR 264
#define DIV 265
#define MINUS 266
#define PLUS 267
#define EQ 268
#define GE 269
#define GT 270
#define LBRACE 271
#define RBRACE 272
#define LE 273
#define RPAR 274
#define LPAR 275
#define LSQ 276
#define LT 277
#define MOD 278
#define NE 279
#define NOT 280
#define AND 281
#define OR 282
#define RSQ 283
#define RETURN 284
#define ELSE 285
#define FOR 286
#define IF 287
#define VAR 288
#define INT 289
#define FLOAT32 290
#define BOOL 291
#define STRING 292
#define PRINT 293
#define PARSEINT 294
#define CMDARGS 295
#define INTLIT 296
#define REALLIT 297
#define RESERVED 298
#define STRLIT 299
#define ID 300
#define UNARY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "gocompiler.y"

    char *str;
    struct node * node;
    struct idToken *id;

#line 165 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
