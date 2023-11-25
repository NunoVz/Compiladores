/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "uccompiler.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"
    #include "funcoes.h"



    extern int yylex(void);
    extern int yyparse();
    extern void yyerror(char *s);

    extern char *yytext;
    int debug =0;
    bool errorflag=false;
    extern int errFlag;

    extern bool flagTree;                //-t

    no root;
	no aux;
	no aux1;
	no aux2;



#line 100 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CHAR = 258,                    /* CHAR  */
    INT = 259,                     /* INT  */
    VOID = 260,                    /* VOID  */
    SHORT = 261,                   /* SHORT  */
    DOUBLE = 262,                  /* DOUBLE  */
    PLUS = 263,                    /* PLUS  */
    MINUS = 264,                   /* MINUS  */
    MUL = 265,                     /* MUL  */
    DIV = 266,                     /* DIV  */
    MOD = 267,                     /* MOD  */
    OR = 268,                      /* OR  */
    AND = 269,                     /* AND  */
    BITWISEAND = 270,              /* BITWISEAND  */
    BITWISEOR = 271,               /* BITWISEOR  */
    BITWISEXOR = 272,              /* BITWISEXOR  */
    EQ = 273,                      /* EQ  */
    NE = 274,                      /* NE  */
    LE = 275,                      /* LE  */
    GE = 276,                      /* GE  */
    LT = 277,                      /* LT  */
    GT = 278,                      /* GT  */
    ASSIGN = 279,                  /* ASSIGN  */
    COMMA = 280,                   /* COMMA  */
    NOT = 281,                     /* NOT  */
    LPAR = 282,                    /* LPAR  */
    RPAR = 283,                    /* RPAR  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285,                  /* RBRACE  */
    SEMI = 286,                    /* SEMI  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    WHILE = 289,                   /* WHILE  */
    RETURN = 290,                  /* RETURN  */
    CHRLIT = 291,                  /* CHRLIT  */
    DECIMAL = 292,                 /* DECIMAL  */
    NATURAL = 293,                 /* NATURAL  */
    RESERVED = 294,                /* RESERVED  */
    ID = 295,                      /* ID  */
    NO_ELSE = 296,                 /* NO_ELSE  */
    MAX_PREC = 297                 /* MAX_PREC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define INT 259
#define VOID 260
#define SHORT 261
#define DOUBLE 262
#define PLUS 263
#define MINUS 264
#define MUL 265
#define DIV 266
#define MOD 267
#define OR 268
#define AND 269
#define BITWISEAND 270
#define BITWISEOR 271
#define BITWISEXOR 272
#define EQ 273
#define NE 274
#define LE 275
#define GE 276
#define LT 277
#define GT 278
#define ASSIGN 279
#define COMMA 280
#define NOT 281
#define LPAR 282
#define RPAR 283
#define LBRACE 284
#define RBRACE 285
#define SEMI 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define RETURN 290
#define CHRLIT 291
#define DECIMAL 292
#define NATURAL 293
#define RESERVED 294
#define ID 295
#define NO_ELSE 296
#define MAX_PREC 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "uccompiler.y"

    char *value;
   	struct node *no;

#line 242 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_SHORT = 6,                      /* SHORT  */
  YYSYMBOL_DOUBLE = 7,                     /* DOUBLE  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_MINUS = 9,                      /* MINUS  */
  YYSYMBOL_MUL = 10,                       /* MUL  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_MOD = 12,                       /* MOD  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_BITWISEAND = 15,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 16,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 17,                /* BITWISEXOR  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_LPAR = 27,                      /* LPAR  */
  YYSYMBOL_RPAR = 28,                      /* RPAR  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_SEMI = 31,                      /* SEMI  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_CHRLIT = 36,                    /* CHRLIT  */
  YYSYMBOL_DECIMAL = 37,                   /* DECIMAL  */
  YYSYMBOL_NATURAL = 38,                   /* NATURAL  */
  YYSYMBOL_RESERVED = 39,                  /* RESERVED  */
  YYSYMBOL_ID = 40,                        /* ID  */
  YYSYMBOL_NO_ELSE = 41,                   /* NO_ELSE  */
  YYSYMBOL_MAX_PREC = 42,                  /* MAX_PREC  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_Program = 44,                   /* Program  */
  YYSYMBOL_FunctionsAndDeclarations = 45,  /* FunctionsAndDeclarations  */
  YYSYMBOL_FunctionsAndDeclarationsList = 46, /* FunctionsAndDeclarationsList  */
  YYSYMBOL_FunctionDefinition = 47,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 48,              /* FunctionBody  */
  YYSYMBOL_DeclarationsAndStatements = 49, /* DeclarationsAndStatements  */
  YYSYMBOL_FunctionDeclaration = 50,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDeclarator = 51,        /* FunctionDeclarator  */
  YYSYMBOL_ParameterList = 52,             /* ParameterList  */
  YYSYMBOL_ParameterListAux = 53,          /* ParameterListAux  */
  YYSYMBOL_ParameterDeclaration = 54,      /* ParameterDeclaration  */
  YYSYMBOL_Declaration = 55,               /* Declaration  */
  YYSYMBOL_DeclaratorAux = 56,             /* DeclaratorAux  */
  YYSYMBOL_TypeSpec = 57,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 58,                /* Declarator  */
  YYSYMBOL_Statement = 59,                 /* Statement  */
  YYSYMBOL_StatementList = 60,             /* StatementList  */
  YYSYMBOL_StatementAux = 61,              /* StatementAux  */
  YYSYMBOL_Expr = 62,                      /* Expr  */
  YYSYMBOL_ExprAux = 63,                   /* ExprAux  */
  YYSYMBOL_ExprAuxAux = 64,                /* ExprAuxAux  */
  YYSYMBOL_IDToken = 65                    /* IDToken  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   444

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    68,    70,    71,    73,    74,    76,    78,
      79,    81,    82,    83,    84,    86,    87,    89,    91,    93,
      94,    96,    97,    99,   100,   102,   103,   105,   106,   107,
     108,   109,   111,   112,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   126,   127,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   162,   163,   166,
     167,   170
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INT", "VOID",
  "SHORT", "DOUBLE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "OR", "AND",
  "BITWISEAND", "BITWISEOR", "BITWISEXOR", "EQ", "NE", "LE", "GE", "LT",
  "GT", "ASSIGN", "COMMA", "NOT", "LPAR", "RPAR", "LBRACE", "RBRACE",
  "SEMI", "IF", "ELSE", "WHILE", "RETURN", "CHRLIT", "DECIMAL", "NATURAL",
  "RESERVED", "ID", "NO_ELSE", "MAX_PREC", "$accept", "Program",
  "FunctionsAndDeclarations", "FunctionsAndDeclarationsList",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterListAux", "ParameterDeclaration", "Declaration",
  "DeclaratorAux", "TypeSpec", "Declarator", "Statement", "StatementList",
  "StatementAux", "Expr", "ExprAux", "ExprAuxAux", "IDToken", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     132,   -14,  -126,  -126,  -126,  -126,  -126,    22,  -126,    33,
      33,    33,    -5,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
     152,   -13,  -126,    -3,    64,  -126,  -126,  -126,    -5,  -126,
     284,   125,   284,   284,   284,   229,   133,  -126,  -126,    -1,
      37,   278,  -126,  -126,  -126,    39,    44,    80,    -5,   118,
     335,   -12,  -126,    56,  -126,    54,  -126,    67,    57,  -126,
    -126,  -126,    77,     3,   -22,  -126,  -126,    83,   171,   284,
     284,  -126,   -11,   224,  -126,  -126,  -126,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,  -126,  -126,   125,  -126,  -126,
    -126,  -126,  -126,  -126,   109,  -126,    50,    51,  -126,   115,
    -126,   317,   174,   174,  -126,  -126,  -126,   352,   368,   416,
     384,   400,   421,   421,   166,   166,   166,   166,   335,   335,
    -126,   186,   245,  -126,   284,   123,   113,  -126,   317,  -126,
     186,  -126,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    27,    28,    29,    30,    31,     0,     2,     0,
       0,     0,     0,    24,     1,     6,     3,     4,     5,    81,
       0,     0,    26,    32,     0,    15,    16,     8,     0,    23,
       0,     0,     0,     0,     0,     0,     0,    10,    43,     0,
       0,     0,    72,    73,    71,    70,     0,     0,     0,     0,
      78,     0,    25,    32,    33,     0,    18,    20,    22,    65,
      66,    67,     0,     0,     0,    41,    46,     0,     0,     0,
       0,    38,     0,     0,     9,    12,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    17,     0,    21,    75,
      74,    42,    47,    34,     0,    44,     0,     0,    39,     0,
      69,    80,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    48,    77,
      19,     0,     0,    76,     0,     0,    35,    37,    80,    68,
       0,    79,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   157,   178,  -126,  -126,    -6,  -126,  -126,  -126,
      69,  -126,   -17,  -126,   -20,   162,   -24,    93,  -125,   -31,
     -25,    53,   180
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    15,    16,     9,    27,    46,    10,    20,    55,
      56,    57,    11,    21,    12,    22,    66,    67,    68,    50,
      51,   135,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    59,    60,    61,    48,    54,   136,    47,   101,   102,
      63,    58,    28,    94,    94,   142,    72,    13,    29,    95,
     108,    30,    14,    49,    31,    49,    69,    48,    94,    48,
      47,   100,    47,    -7,     1,    19,     2,     3,     4,     5,
       6,    75,   111,    76,   106,   107,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    70,     1,    73,     2,     3,     4,
       5,     6,    32,    33,    74,    94,    94,    58,   131,   132,
      30,     1,    96,     2,     3,     4,     5,     6,    32,    33,
      34,    35,    97,    36,    37,    38,    39,    98,    40,    41,
      42,    43,    44,   138,    45,    99,    34,    35,   137,    36,
     -14,    38,    39,   103,    40,    41,    42,    43,    44,     1,
      45,     2,     3,     4,     5,     6,    32,    33,     2,     3,
       4,     5,     6,     1,    64,     2,     3,     4,     5,     6,
     102,    32,    33,   133,    34,    35,   140,    36,   -13,    38,
      39,   139,    40,    41,    42,    43,    44,     8,    45,    34,
      35,   105,    36,    65,    38,    39,   130,    40,    41,    42,
      43,    44,   104,    45,    77,    78,    79,    80,    81,    32,
      33,    24,    25,    26,    79,    80,    81,   104,    17,    18,
      52,   141,    23,     0,    32,    33,     0,    34,    35,     0,
      36,   -45,    38,    39,     0,    40,    41,    42,    43,    44,
       0,    45,    34,    35,     0,    36,     0,    38,    39,     0,
      40,    41,    42,    43,    44,   109,    45,     0,     0,     0,
      62,     0,    32,    33,     0,     0,     0,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,   110,    32,    33,    34,    35,     0,     0,     0,
      42,    43,    44,     0,    45,    42,    43,    44,     0,    45,
       0,    34,    35,     0,    36,     0,    38,    39,     0,    40,
      41,    42,    43,    44,     0,    45,    32,    33,     0,     0,
       0,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,     0,     0,     0,    71,
      34,    35,     0,     0,    42,    43,    44,     0,    45,     0,
      42,    43,    44,     0,    45,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   134,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      77,    78,    79,    80,    81,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    77,    78,    79,    80,
      81,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    77,    78,    79,    80,    81,     0,     0,    84,
       0,    86,    87,    88,    89,    90,    91,    92,    77,    78,
      79,    80,    81,     0,     0,    84,     0,     0,    87,    88,
      89,    90,    91,    92,    77,    78,    79,    80,    81,    77,
      78,    79,    80,    81,    87,    88,    89,    90,    91,    92,
       0,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      24,    32,    33,    34,    24,    30,   131,    24,    30,    31,
      35,    31,    25,    25,    25,   140,    41,    31,    31,    31,
      31,    24,     0,    47,    27,    49,    27,    47,    25,    49,
      47,    28,    49,     0,     1,    40,     3,     4,     5,     6,
       7,    47,    73,    49,    69,    70,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    27,     1,    27,     3,     4,     5,
       6,     7,     8,     9,    30,    25,    25,    97,    28,    28,
      24,     1,    28,     3,     4,     5,     6,     7,     8,     9,
      26,    27,    25,    29,    30,    31,    32,    40,    34,    35,
      36,    37,    38,   134,    40,    28,    26,    27,   132,    29,
      30,    31,    32,    30,    34,    35,    36,    37,    38,     1,
      40,     3,     4,     5,     6,     7,     8,     9,     3,     4,
       5,     6,     7,     1,     1,     3,     4,     5,     6,     7,
      31,     8,     9,    28,    26,    27,    33,    29,    30,    31,
      32,    28,    34,    35,    36,    37,    38,     0,    40,    26,
      27,    68,    29,    30,    31,    32,    97,    34,    35,    36,
      37,    38,     1,    40,     8,     9,    10,    11,    12,     8,
       9,    29,    30,    31,    10,    11,    12,     1,    10,    11,
      28,   138,    12,    -1,     8,     9,    -1,    26,    27,    -1,
      29,    30,    31,    32,    -1,    34,    35,    36,    37,    38,
      -1,    40,    26,    27,    -1,    29,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,     1,    40,    -1,    -1,    -1,
       1,    -1,     8,     9,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,     8,     9,    26,    27,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    36,    37,    38,    -1,    40,
      -1,    26,    27,    -1,    29,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    -1,    40,     8,     9,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    31,
      26,    27,    -1,    -1,    36,    37,    38,    -1,    40,    -1,
      36,    37,    38,    -1,    40,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     8,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,     8,     9,    10,    11,    12,     8,
       9,    10,    11,    12,    18,    19,    20,    21,    22,    23,
      -1,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    44,    45,    47,
      50,    55,    57,    31,     0,    45,    46,    46,    46,    40,
      51,    56,    58,    65,    29,    30,    31,    48,    25,    31,
      24,    27,     8,     9,    26,    27,    29,    30,    31,    32,
      34,    35,    36,    37,    38,    40,    49,    55,    57,    59,
      62,    63,    58,    65,    63,    52,    53,    54,    57,    62,
      62,    62,     1,    63,     1,    30,    59,    60,    61,    27,
      27,    31,    63,    27,    30,    49,    49,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    31,    28,    25,    40,    28,
      28,    30,    31,    30,     1,    60,    63,    63,    31,     1,
      28,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      53,    28,    28,    28,    25,    64,    61,    59,    62,    28,
      33,    64,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    45,    46,    46,    47,    48,
      48,    49,    49,    49,    49,    50,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     0,     3,     3,
       2,     2,     2,     1,     1,     3,     3,     4,     1,     3,
       1,     2,     1,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     5,     7,     5,     2,     3,
       2,     2,     3,     1,     2,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     5,     3,
       1,     1,     1,     1,     3,     3,     4,     3,     1,     3,
       0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: FunctionsAndDeclarations  */
#line 66 "uccompiler.y"
                                  { if (debug) printf("Program \n"); (yyval.no) = create("Program", "Program"); addChild((yyval.no), (yyvsp[0].no)); if (!errFlag && flagTree) { printTree((yyval.no), 0); } }
#line 1444 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarationsList  */
#line 68 "uccompiler.y"
                                                                          {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no), (yyvsp[0].no));}
#line 1450 "y.tab.c"
    break;

  case 4: /* FunctionsAndDeclarations: FunctionDeclaration FunctionsAndDeclarationsList  */
#line 70 "uccompiler.y"
                                                   {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no), (yyvsp[0].no));}
#line 1456 "y.tab.c"
    break;

  case 5: /* FunctionsAndDeclarations: Declaration FunctionsAndDeclarationsList  */
#line 71 "uccompiler.y"
                                           {if (!(yyvsp[-1].no)) {(yyval.no) = (yyvsp[0].no);} else {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no), (yyvsp[0].no));}}
#line 1462 "y.tab.c"
    break;

  case 6: /* FunctionsAndDeclarationsList: FunctionsAndDeclarations  */
#line 73 "uccompiler.y"
                                                       {(yyval.no) = (yyvsp[0].no);}
#line 1468 "y.tab.c"
    break;

  case 7: /* FunctionsAndDeclarationsList: %empty  */
#line 74 "uccompiler.y"
  {(yyval.no) = NULL;}
#line 1474 "y.tab.c"
    break;

  case 8: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 76 "uccompiler.y"
                                                             { if (debug) printf("Function Definition\n"); (yyval.no) = create("FuncDefinition", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[-1].no)); if ((yyvsp[0].no)) { addChild((yyval.no), (yyvsp[0].no)); } else { addChild((yyval.no), create("FuncBody", "")); } }
#line 1480 "y.tab.c"
    break;

  case 9: /* FunctionBody: LBRACE DeclarationsAndStatements RBRACE  */
#line 78 "uccompiler.y"
                                                      { if (debug) printf("Function Body\n"); (yyval.no) = create("FuncBody", ""); addChild((yyval.no), (yyvsp[-1].no));  }
#line 1486 "y.tab.c"
    break;

  case 10: /* FunctionBody: LBRACE RBRACE  */
#line 79 "uccompiler.y"
                {(yyval.no) = create("FuncBody", "");}
#line 1492 "y.tab.c"
    break;

  case 11: /* DeclarationsAndStatements: Statement DeclarationsAndStatements  */
#line 81 "uccompiler.y"
                                                               {if (!(yyvsp[-1].no)) {(yyval.no) = (yyvsp[0].no);} else {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no), (yyvsp[0].no));}}
#line 1498 "y.tab.c"
    break;

  case 12: /* DeclarationsAndStatements: Declaration DeclarationsAndStatements  */
#line 82 "uccompiler.y"
                                        {if (!(yyvsp[-1].no)) {(yyval.no) = (yyvsp[0].no);} else {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no), (yyvsp[0].no));}}
#line 1504 "y.tab.c"
    break;

  case 13: /* DeclarationsAndStatements: Statement  */
#line 83 "uccompiler.y"
            {(yyval.no) = (yyvsp[0].no);}
#line 1510 "y.tab.c"
    break;

  case 14: /* DeclarationsAndStatements: Declaration  */
#line 84 "uccompiler.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 1516 "y.tab.c"
    break;

  case 15: /* FunctionDeclaration: TypeSpec FunctionDeclarator RBRACE  */
#line 86 "uccompiler.y"
                                                        { if (debug) printf("Function Declaration\n"); (yyval.no) = create("FuncDeclaration", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[-1].no)); }
#line 1522 "y.tab.c"
    break;

  case 16: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 87 "uccompiler.y"
                                   { if (debug) printf("Function Declarationt\n"); (yyval.no) = create("FuncDeclaration", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[-1].no)); }
#line 1528 "y.tab.c"
    break;

  case 17: /* FunctionDeclarator: IDToken LPAR ParameterList RPAR  */
#line 89 "uccompiler.y"
                                                    { if (debug) printf("Function Declarator\n"); addBrother((yyval.no), (yyvsp[-1].no)); }
#line 1534 "y.tab.c"
    break;

  case 18: /* ParameterList: ParameterListAux  */
#line 91 "uccompiler.y"
                                { if (debug) printf("Parameter List\n"); (yyval.no) = create("ParamList", ""); addChild((yyval.no), (yyvsp[0].no)); }
#line 1540 "y.tab.c"
    break;

  case 19: /* ParameterListAux: ParameterDeclaration COMMA ParameterListAux  */
#line 93 "uccompiler.y"
                                                              { if (debug) printf("Parameter List\n"); (yyval.no) = create("X", ""); addBrother((yyval.no), (yyvsp[-2].no)); addBrother((yyval.no), (yyvsp[0].no)); }
#line 1546 "y.tab.c"
    break;

  case 20: /* ParameterListAux: ParameterDeclaration  */
#line 94 "uccompiler.y"
                       { if (debug) printf("Empty Parameter List\n"); (yyval.no) = (yyvsp[0].no); }
#line 1552 "y.tab.c"
    break;

  case 21: /* ParameterDeclaration: TypeSpec ID  */
#line 96 "uccompiler.y"
                                  { if (debug) printf("Parameter Declaration ID:%s\n",(yyvsp[0].value)); (yyval.no) = create("ParamDeclaration", ""); addChild((yyval.no), (yyvsp[-1].no)); addChild((yyval.no), create("Identifier", (yyvsp[0].value))); }
#line 1558 "y.tab.c"
    break;

  case 22: /* ParameterDeclaration: TypeSpec  */
#line 97 "uccompiler.y"
           { if (debug) printf("Empty Parameter Declaration\n"); (yyval.no) = create("ParamDeclaration", ""); addChild((yyval.no), (yyvsp[0].no)); }
#line 1564 "y.tab.c"
    break;

  case 23: /* Declaration: TypeSpec DeclaratorAux SEMI  */
#line 99 "uccompiler.y"
                                         { if (debug) printf("Declaration4\n"); if((yyvsp[-1].no)) { aux = (yyvsp[-1].no); while(aux) { aux1 = create((yyvsp[-2].no)->type,""); aux2 = aux->child; aux->child = aux1; aux1->brother = aux2; aux = aux->brother; } } (yyval.no) = (yyvsp[-1].no); }
#line 1570 "y.tab.c"
    break;

  case 24: /* Declaration: error SEMI  */
#line 100 "uccompiler.y"
             { (yyval.no) = NULL; errorflag = 1; }
#line 1576 "y.tab.c"
    break;

  case 25: /* DeclaratorAux: DeclaratorAux COMMA Declarator  */
#line 102 "uccompiler.y"
                                             { if((yyvsp[-2].no)) { aux = (yyvsp[-2].no); while(aux->brother) aux = aux->brother; if((yyvsp[0].no)) aux->brother = addChild(create("Declaration",""), (yyvsp[0].no)); (yyval.no) = (yyvsp[-2].no); } else if((yyvsp[0].no)) {(yyval.no) = (yyvsp[0].no);} else {(yyval.no) = NULL;} }
#line 1582 "y.tab.c"
    break;

  case 26: /* DeclaratorAux: Declarator  */
#line 103 "uccompiler.y"
             { if((yyvsp[0].no)) { aux = create("Declaration",""); (yyval.no) = addChild(aux, (yyvsp[0].no)); } else {(yyval.no) = NULL;} }
#line 1588 "y.tab.c"
    break;

  case 27: /* TypeSpec: CHAR  */
#line 105 "uccompiler.y"
               { if (debug) printf("Type: char\n"); (yyval.no) = create("Char", ""); }
#line 1594 "y.tab.c"
    break;

  case 28: /* TypeSpec: INT  */
#line 106 "uccompiler.y"
      { if (debug) printf("Type: int\n"); (yyval.no) = create("Int", ""); }
#line 1600 "y.tab.c"
    break;

  case 29: /* TypeSpec: VOID  */
#line 107 "uccompiler.y"
       { if (debug) printf("Type: void\n"); (yyval.no) = create("Void", ""); }
#line 1606 "y.tab.c"
    break;

  case 30: /* TypeSpec: SHORT  */
#line 108 "uccompiler.y"
        { if (debug) printf("Type: short\n"); (yyval.no) = create("Short", ""); }
#line 1612 "y.tab.c"
    break;

  case 31: /* TypeSpec: DOUBLE  */
#line 109 "uccompiler.y"
         { if (debug) printf("Type: double\n"); (yyval.no) = create("Double", ""); }
#line 1618 "y.tab.c"
    break;

  case 32: /* Declarator: IDToken  */
#line 111 "uccompiler.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1624 "y.tab.c"
    break;

  case 33: /* Declarator: IDToken ASSIGN ExprAux  */
#line 112 "uccompiler.y"
                         {(yyvsp[-2].no)->brother = (yyvsp[0].no); (yyval.no) = (yyvsp[-2].no);}
#line 1630 "y.tab.c"
    break;

  case 34: /* Statement: LBRACE StatementList RBRACE  */
#line 114 "uccompiler.y"
                                       { (yyval.no) = (yyvsp[-1].no); if (debug && (yyvsp[-1].no)) printf("Statlist\n"); else if (debug) printf("Compound Stat\n"); if ((yyvsp[-1].no) && (yyvsp[-1].no)->brother) { (yyval.no) = create("StatList", ""); (yyval.no) = addChild((yyval.no), (yyvsp[-1].no)); } else if ((yyvsp[-1].no)) { (yyval.no) = (yyvsp[-1].no); } }
#line 1636 "y.tab.c"
    break;

  case 35: /* Statement: IF LPAR ExprAux RPAR StatementAux  */
#line 115 "uccompiler.y"
                                                  { if (debug) printf("If Statement\n"); (yyval.no) = create("If", ""); addChild((yyval.no), (yyvsp[-2].no)); if ((yyvsp[0].no) != NULL) addChild((yyval.no), (yyvsp[0].no)); else addChild((yyval.no), create("Null","")); addChild((yyval.no), create("Null","")); }
#line 1642 "y.tab.c"
    break;

  case 36: /* Statement: IF LPAR ExprAux RPAR StatementAux ELSE StatementAux  */
#line 116 "uccompiler.y"
                                                      { if (debug) printf("If-Else Statement\n"); (yyval.no) = create("If", ""); addChild((yyval.no), (yyvsp[-4].no)); if ((yyvsp[-2].no) != NULL) addChild((yyval.no), (yyvsp[-2].no)); else addChild((yyval.no), create("Null","")); if ((yyvsp[0].no) != NULL) addChild((yyval.no), (yyvsp[0].no)); else addChild((yyval.no), create("Null","")); }
#line 1648 "y.tab.c"
    break;

  case 37: /* Statement: WHILE LPAR ExprAux RPAR Statement  */
#line 117 "uccompiler.y"
                                    { if (debug) printf("While Loop\n"); (yyval.no) = create("While", ""); addChild((yyval.no), (yyvsp[-2].no)); if ((yyvsp[0].no) != NULL) addChild((yyval.no), (yyvsp[0].no)); else addChild((yyval.no), create("Null",""));}
#line 1654 "y.tab.c"
    break;

  case 38: /* Statement: RETURN SEMI  */
#line 118 "uccompiler.y"
              { if (debug) printf("Return Statement\n"); (yyval.no) = create("Return", ""); addChild((yyval.no), create("Null","")); }
#line 1660 "y.tab.c"
    break;

  case 39: /* Statement: RETURN ExprAux SEMI  */
#line 119 "uccompiler.y"
                      { if (debug) printf("Return Statement with Value\n"); (yyval.no) = create("Return", ""); addChild((yyval.no), (yyvsp[-1].no)); }
#line 1666 "y.tab.c"
    break;

  case 40: /* Statement: ExprAux SEMI  */
#line 120 "uccompiler.y"
               { if (debug) printf("Expression Statement\n"); (yyval.no) = (yyvsp[-1].no); }
#line 1672 "y.tab.c"
    break;

  case 41: /* Statement: LBRACE RBRACE  */
#line 121 "uccompiler.y"
                { (yyval.no) = NULL; }
#line 1678 "y.tab.c"
    break;

  case 42: /* Statement: LBRACE error RBRACE  */
#line 122 "uccompiler.y"
                      { (yyval.no) = create("Null1", ""); }
#line 1684 "y.tab.c"
    break;

  case 43: /* Statement: SEMI  */
#line 123 "uccompiler.y"
       { (yyval.no) = NULL; errorflag = 1; }
#line 1690 "y.tab.c"
    break;

  case 44: /* StatementList: StatementAux StatementList  */
#line 126 "uccompiler.y"
                                          { if (debug) printf("Stat + StatList\n"); if ((yyvsp[-1].no)) { (yyval.no) = (yyvsp[-1].no); if ((yyvsp[0].no)) { aux = (yyval.no); while (aux->brother) aux = aux->brother; aux->brother = (yyvsp[0].no); } } else { (yyval.no) = (yyvsp[0].no); } }
#line 1696 "y.tab.c"
    break;

  case 45: /* StatementList: StatementAux  */
#line 127 "uccompiler.y"
               {(yyval.no) = (yyvsp[0].no);}
#line 1702 "y.tab.c"
    break;

  case 46: /* StatementAux: Statement  */
#line 129 "uccompiler.y"
                        { (yyval.no) = (yyvsp[0].no); }
#line 1708 "y.tab.c"
    break;

  case 47: /* StatementAux: error SEMI  */
#line 130 "uccompiler.y"
             { (yyval.no) = NULL; errorflag = 1; }
#line 1714 "y.tab.c"
    break;

  case 48: /* Expr: Expr ASSIGN Expr  */
#line 131 "uccompiler.y"
                       { if (debug) printf("Store\n"); (yyval.no) = create("Store", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1720 "y.tab.c"
    break;

  case 49: /* Expr: Expr PLUS Expr  */
#line 132 "uccompiler.y"
                 { if (debug) printf("Addition\n"); (yyval.no) = create("Add", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1726 "y.tab.c"
    break;

  case 50: /* Expr: Expr MINUS Expr  */
#line 133 "uccompiler.y"
                  { if (debug) printf("Subtraction\n"); (yyval.no) = create("Sub", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1732 "y.tab.c"
    break;

  case 51: /* Expr: Expr MUL Expr  */
#line 134 "uccompiler.y"
                { if (debug) printf("Multiplication\n"); (yyval.no) = create("Mul", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1738 "y.tab.c"
    break;

  case 52: /* Expr: Expr DIV Expr  */
#line 135 "uccompiler.y"
                { if (debug) printf("Division\n"); (yyval.no) = create("Div", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1744 "y.tab.c"
    break;

  case 53: /* Expr: Expr MOD Expr  */
#line 136 "uccompiler.y"
                { if (debug) printf("Modulo\n"); (yyval.no) = create("Mod", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1750 "y.tab.c"
    break;

  case 54: /* Expr: Expr OR Expr  */
#line 137 "uccompiler.y"
               { if (debug) printf("Logical OR\n"); (yyval.no) = create("Or", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1756 "y.tab.c"
    break;

  case 55: /* Expr: Expr AND Expr  */
#line 138 "uccompiler.y"
                { if (debug) printf("Logical AND\n"); (yyval.no) = create("And", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1762 "y.tab.c"
    break;

  case 56: /* Expr: Expr BITWISEAND Expr  */
#line 139 "uccompiler.y"
                       { if (debug) printf("Bitwise AND\n"); (yyval.no) = create("BitWiseAnd", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1768 "y.tab.c"
    break;

  case 57: /* Expr: Expr BITWISEOR Expr  */
#line 140 "uccompiler.y"
                      { if (debug) printf("Bitwise OR\n"); (yyval.no) = create("BitWiseOr", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1774 "y.tab.c"
    break;

  case 58: /* Expr: Expr BITWISEXOR Expr  */
#line 141 "uccompiler.y"
                       { if (debug) printf("Bitwise XOR\n"); (yyval.no) = create("BitWiseXor", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1780 "y.tab.c"
    break;

  case 59: /* Expr: Expr EQ Expr  */
#line 142 "uccompiler.y"
               { if (debug) printf("Equal\n"); (yyval.no) = create("Eq", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1786 "y.tab.c"
    break;

  case 60: /* Expr: Expr NE Expr  */
#line 143 "uccompiler.y"
               { if (debug) printf("Not Equal\n"); (yyval.no) = create("Ne", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1792 "y.tab.c"
    break;

  case 61: /* Expr: Expr LE Expr  */
#line 144 "uccompiler.y"
               { if (debug) printf("Less Than or Equal\n"); (yyval.no) = create("Le", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1798 "y.tab.c"
    break;

  case 62: /* Expr: Expr GE Expr  */
#line 145 "uccompiler.y"
               { if (debug) printf("Greater Than or Equal\n"); (yyval.no) = create("Ge", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1804 "y.tab.c"
    break;

  case 63: /* Expr: Expr LT Expr  */
#line 146 "uccompiler.y"
               { if (debug) printf("Less Than\n"); (yyval.no) = create("Lt", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1810 "y.tab.c"
    break;

  case 64: /* Expr: Expr GT Expr  */
#line 147 "uccompiler.y"
               { if (debug) printf("Greater Than\n"); (yyval.no) = create("Gt", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1816 "y.tab.c"
    break;

  case 65: /* Expr: PLUS Expr  */
#line 148 "uccompiler.y"
                           { if (debug) printf("Unary Plus\n"); (yyval.no) = create("Plus", ""); addChild((yyval.no), (yyvsp[0].no)); }
#line 1822 "y.tab.c"
    break;

  case 66: /* Expr: MINUS Expr  */
#line 149 "uccompiler.y"
                            { if (debug) printf("Unary Minus\n"); (yyval.no) = create("Minus", ""); addChild((yyval.no), (yyvsp[0].no)); }
#line 1828 "y.tab.c"
    break;

  case 67: /* Expr: NOT Expr  */
#line 150 "uccompiler.y"
                          { if (debug) printf("Logical NOT\n"); (yyval.no) = create("Not", ""); addChild((yyval.no), (yyvsp[0].no)); }
#line 1834 "y.tab.c"
    break;

  case 68: /* Expr: ID LPAR Expr ExprAuxAux RPAR  */
#line 151 "uccompiler.y"
                               { if (debug) printf("CALL w stuff\n"); (yyval.no) = create("Call", ""); addChild((yyval.no), create("Identifier", (yyvsp[-4].value))); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[-1].no)); }
#line 1840 "y.tab.c"
    break;

  case 69: /* Expr: ID LPAR RPAR  */
#line 152 "uccompiler.y"
               { if (debug) printf("Call wo stuff\n"); (yyval.no) = create("Call", ""); aux = create("Identifier", (yyvsp[-2].value)); addChild((yyval.no), aux); }
#line 1846 "y.tab.c"
    break;

  case 70: /* Expr: ID  */
#line 153 "uccompiler.y"
     { if (debug) printf("Identifier (%s)\n", (yyvsp[0].value)); (yyval.no) = create("Identifier", (yyvsp[0].value)); }
#line 1852 "y.tab.c"
    break;

  case 71: /* Expr: NATURAL  */
#line 154 "uccompiler.y"
          { if (debug) printf("Natural: %s\n", (yyvsp[0].value)); (yyval.no) = create("Natural", (yyvsp[0].value)); }
#line 1858 "y.tab.c"
    break;

  case 72: /* Expr: CHRLIT  */
#line 155 "uccompiler.y"
         { if (debug) printf("Char Literal: %s\n", (yyvsp[0].value)); (yyval.no) = create("ChrLit", (yyvsp[0].value)); }
#line 1864 "y.tab.c"
    break;

  case 73: /* Expr: DECIMAL  */
#line 156 "uccompiler.y"
          { if (debug) printf("Decimal: %s\n", (yyvsp[0].value)); (yyval.no) = create("Decimal", (yyvsp[0].value)); }
#line 1870 "y.tab.c"
    break;

  case 74: /* Expr: LPAR ExprAux RPAR  */
#line 157 "uccompiler.y"
                    { (yyval.no) = (yyvsp[-1].no); }
#line 1876 "y.tab.c"
    break;

  case 75: /* Expr: LPAR error RPAR  */
#line 158 "uccompiler.y"
                  { (yyval.no) = NULL; errorflag = 1; }
#line 1882 "y.tab.c"
    break;

  case 76: /* Expr: ID LPAR error RPAR  */
#line 159 "uccompiler.y"
                     {(yyval.no) = NULL;}
#line 1888 "y.tab.c"
    break;

  case 77: /* ExprAux: ExprAux COMMA Expr  */
#line 162 "uccompiler.y"
                            { if (debug) printf("Comma\n"); (yyval.no) = create("Comma", ""); addChild((yyval.no), (yyvsp[-2].no)); addChild((yyval.no), (yyvsp[0].no)); }
#line 1894 "y.tab.c"
    break;

  case 78: /* ExprAux: Expr  */
#line 163 "uccompiler.y"
       { if (debug) printf("Expr from ExprAux\n"); (yyval.no) = (yyvsp[0].no); }
#line 1900 "y.tab.c"
    break;

  case 79: /* ExprAuxAux: COMMA Expr ExprAuxAux  */
#line 166 "uccompiler.y"
                                  {(yyval.no) = (yyvsp[-1].no); addBrother((yyval.no), (yyvsp[0].no));}
#line 1906 "y.tab.c"
    break;

  case 80: /* ExprAuxAux: %empty  */
#line 167 "uccompiler.y"
  {(yyval.no) = NULL;}
#line 1912 "y.tab.c"
    break;

  case 81: /* IDToken: ID  */
#line 170 "uccompiler.y"
            { if(debug) printf("Identifier (%s)\n", (yyvsp[0].value)); (yyval.no) = create("Identifier", (yyvsp[0].value)); }
#line 1918 "y.tab.c"
    break;


#line 1922 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 172 "uccompiler.y"



