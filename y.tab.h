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
    RESERVED = 258,                /* RESERVED  */
    IF = 259,                      /* IF  */
    INT = 260,                     /* INT  */
    SHORT = 261,                   /* SHORT  */
    DOUBLE = 262,                  /* DOUBLE  */
    CHAR = 263,                    /* CHAR  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    RETURN = 266,                  /* RETURN  */
    VOID = 267,                    /* VOID  */
    BITWISEAND = 268,              /* BITWISEAND  */
    BITWISEOR = 269,               /* BITWISEOR  */
    BITWISEXOR = 270,              /* BITWISEXOR  */
    AND = 271,                     /* AND  */
    ASSIGN = 272,                  /* ASSIGN  */
    MUL = 273,                     /* MUL  */
    COMMA = 274,                   /* COMMA  */
    DIV = 275,                     /* DIV  */
    EQ = 276,                      /* EQ  */
    GE = 277,                      /* GE  */
    GT = 278,                      /* GT  */
    LBRACE = 279,                  /* LBRACE  */
    LE = 280,                      /* LE  */
    LPAR = 281,                    /* LPAR  */
    LT = 282,                      /* LT  */
    MINUS = 283,                   /* MINUS  */
    MOD = 284,                     /* MOD  */
    NE = 285,                      /* NE  */
    NOT = 286,                     /* NOT  */
    OR = 287,                      /* OR  */
    PLUS = 288,                    /* PLUS  */
    RBRACE = 289,                  /* RBRACE  */
    RPAR = 290,                    /* RPAR  */
    SEMI = 291,                    /* SEMI  */
    NATURAL = 292,                 /* NATURAL  */
    DECIMAL = 293,                 /* DECIMAL  */
    ID = 294,                      /* ID  */
    CHRLIT = 295                   /* CHRLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define RESERVED 258
#define IF 259
#define INT 260
#define SHORT 261
#define DOUBLE 262
#define CHAR 263
#define ELSE 264
#define WHILE 265
#define RETURN 266
#define VOID 267
#define BITWISEAND 268
#define BITWISEOR 269
#define BITWISEXOR 270
#define AND 271
#define ASSIGN 272
#define MUL 273
#define COMMA 274
#define DIV 275
#define EQ 276
#define GE 277
#define GT 278
#define LBRACE 279
#define LE 280
#define LPAR 281
#define LT 282
#define MINUS 283
#define MOD 284
#define NE 285
#define NOT 286
#define OR 287
#define PLUS 288
#define RBRACE 289
#define RPAR 290
#define SEMI 291
#define NATURAL 292
#define DECIMAL 293
#define ID 294
#define CHRLIT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
