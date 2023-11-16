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
	void yyerror (const char *s);
    extern char *yytext;
    int debug =0;
    bool errorflag=false;

    bool flagTree=false;                //-t

    no root;
	no aux;
	no aux1;
	no aux2;
    extern int l , c;



#line 98 "y.tab.c"

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
    ID = 292,                      /* ID  */
    NATURAL = 293,                 /* NATURAL  */
    DECIMAL = 294,                 /* DECIMAL  */
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
#define ID 292
#define NATURAL 293
#define DECIMAL 294
#define CHRLIT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "uccompiler.y"

    char *value;
   	struct node *no;

#line 236 "y.tab.c"

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
  YYSYMBOL_RESERVED = 3,                   /* RESERVED  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_SHORT = 6,                      /* SHORT  */
  YYSYMBOL_DOUBLE = 7,                     /* DOUBLE  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_BITWISEAND = 13,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 14,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 15,                /* BITWISEXOR  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_MUL = 18,                       /* MUL  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_LPAR = 26,                      /* LPAR  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_MOD = 29,                       /* MOD  */
  YYSYMBOL_NE = 30,                        /* NE  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_RPAR = 35,                      /* RPAR  */
  YYSYMBOL_SEMI = 36,                      /* SEMI  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_NATURAL = 38,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 39,                   /* DECIMAL  */
  YYSYMBOL_CHRLIT = 40,                    /* CHRLIT  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_FunctionsAndDeclarations = 43,  /* FunctionsAndDeclarations  */
  YYSYMBOL_FunctionDefinition = 44,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 45,              /* FunctionBody  */
  YYSYMBOL_DeclarationsAndStatements = 46, /* DeclarationsAndStatements  */
  YYSYMBOL_StatementOrDeclaration = 47,    /* StatementOrDeclaration  */
  YYSYMBOL_FunctionDeclaration = 48,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDeclarator = 49,        /* FunctionDeclarator  */
  YYSYMBOL_ParameterList = 50,             /* ParameterList  */
  YYSYMBOL_ParameterDeclaration = 51,      /* ParameterDeclaration  */
  YYSYMBOL_Declaration = 52,               /* Declaration  */
  YYSYMBOL_TypeSpec = 53,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 54,                /* Declarator  */
  YYSYMBOL_Statement = 55,                 /* Statement  */
  YYSYMBOL_Expr = 56                       /* Expr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    73,    76,    82,    88,    91,   100,   106,
     108,   111,   112,   115,   118,   121,   122,   123,   126,   127,
     130,   131,   135,   136,   137,   138,   139,   140,   143,   144,
     147,   148,   149,   150,   151,   152,   153,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183
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
  "\"end of file\"", "error", "\"invalid token\"", "RESERVED", "IF",
  "INT", "SHORT", "DOUBLE", "CHAR", "ELSE", "WHILE", "RETURN", "VOID",
  "BITWISEAND", "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA",
  "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD",
  "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "ID", "NATURAL",
  "DECIMAL", "CHRLIT", "$accept", "Program", "FunctionsAndDeclarations",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "StatementOrDeclaration", "FunctionDeclaration", "FunctionDeclarator",
  "ParameterList", "ParameterDeclaration", "Declaration", "TypeSpec",
  "Declarator", "Statement", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,   -88,   -88,   -88,   -88,   -88,   -88,    11,   -88,    69,
      69,    69,    15,   -88,   -88,   -88,   -88,   -18,   -12,   -23,
     -17,   -88,   398,   111,    56,   -88,   -88,   -88,    71,   398,
     398,   398,   -11,   -88,   -88,   -88,   251,    -7,    10,    21,
      33,    39,   383,    56,    44,    56,   -88,    16,   -88,   134,
      48,   182,    -8,   -88,    -8,    60,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   -88,   111,   -88,   398,   398,   -88,
     158,    51,   -88,   -88,    74,   -88,   -88,   -88,    53,   365,
     333,   351,   314,   272,   -88,   272,   -88,   379,   110,   110,
     110,   110,    -8,   -88,   379,   293,    -8,   -88,   205,   228,
     -88,   -88,   -88,    96,    96,    77,   -88,    96,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    27,    23,    25,    26,    22,    24,     0,     2,     0,
       0,     0,     0,     1,     3,     4,     5,     0,    28,     0,
       0,    21,     0,     0,     0,    13,     7,    20,     0,     0,
       0,     0,    59,    60,    62,    61,    29,     0,    16,    19,
       0,     0,     0,     0,     0,     0,    12,     0,    11,     0,
       0,     0,    56,    57,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,    18,     0,     0,    34,
       0,     0,     8,     9,    28,    36,    64,    63,     0,    46,
      47,    48,    45,    37,    41,    38,    42,    49,    52,    54,
      51,    53,    40,    43,    50,    44,    39,    15,     0,     0,
      35,    30,    58,     0,     0,    31,    33,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    22,   -88,   -88,    28,   -88,   -88,   -88,    17,
     -88,   -20,   -21,   -88,   -87,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    26,    44,    45,    10,    19,    37,
      38,    11,    12,    20,    48,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    24,    39,    47,    46,    22,    51,    52,    53,    54,
      61,    13,    63,    25,    23,    55,    17,    17,    21,    27,
      80,    70,    47,    46,    47,    46,   115,   116,    74,    75,
     118,    14,    15,    16,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    18,    84,    39,   108,   109,     1,    76,    77,
      40,     2,     3,     4,     5,    78,    41,    42,     6,    -6,
       1,    81,    50,    83,     2,     3,     4,     5,    82,    88,
      43,     6,    28,    86,    29,   111,   117,    30,   112,    31,
     -10,    22,   107,    32,    33,    34,    35,    28,     0,    29,
      40,     0,    30,     0,    31,     0,    41,    42,    32,    33,
      34,    35,     1,     0,     0,     0,     2,     3,     4,     5,
      43,     0,    28,     6,    29,     0,     0,    30,    61,    31,
      63,     0,     0,    32,    33,    34,    35,     0,    69,    70,
       0,     0,     0,    73,     0,     0,   -17,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
       0,    68,    69,    70,    71,     0,    72,    73,     0,     0,
      85,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,     0,    68,    69,    70,    71,     0,
      72,    73,     0,     0,   110,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,     0,    68,
      69,    70,    71,     0,    72,    73,     0,    87,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,     0,    68,    69,    70,    71,     0,    72,    73,     0,
     113,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,     0,    68,    69,    70,    71,     0,
      72,    73,     0,   114,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    67,     0,    68,    69,
      70,    71,     0,    72,    73,    56,    57,    58,    59,    60,
      61,     0,    63,    64,    65,    66,     0,    67,     0,    68,
      69,    70,    71,     0,    72,    73,    56,    57,    58,    59,
       0,    61,     0,    63,    64,    65,    66,     0,    67,     0,
      68,    69,    70,    71,     0,     0,    73,    56,    57,    58,
       0,     0,    61,     0,    63,    64,    65,    66,     0,    67,
       0,    68,    69,    70,    71,     0,    56,    73,    58,     0,
       0,    61,     0,    63,    64,    65,    66,     0,    67,     0,
      68,    69,    70,    71,    56,     0,    73,     0,     0,    61,
       0,    63,    64,    65,    66,     0,    67,     0,    68,    69,
      70,    71,     0,    61,    73,    63,    64,    65,    66,     0,
      67,     0,    68,    69,    70,    71,     0,    61,    73,    63,
       0,    65,    66,     0,    67,     0,    68,    69,    70,    28,
       0,    29,    73,     0,    30,     0,    31,     0,     0,    79,
      32,    33,    34,    35,    28,     0,    29,     0,     0,    30,
       0,    31,     0,     0,     0,    32,    33,    34,    35
};

static const yytype_int8 yycheck[] =
{
      22,    24,    23,    24,    24,    17,    28,    29,    30,    31,
      18,     0,    20,    36,    26,    26,     1,     1,    36,    36,
      42,    29,    43,    43,    45,    45,   113,   114,    35,    19,
     117,     9,    10,    11,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    37,    37,    75,    77,    78,     1,    37,    26,
       4,     5,     6,     7,     8,    26,    10,    11,    12,     0,
       1,    43,     1,    45,     5,     6,     7,     8,    34,    19,
      24,    12,    26,    35,    28,    34,     9,    31,    35,    33,
      34,    17,    75,    37,    38,    39,    40,    26,    -1,    28,
       4,    -1,    31,    -1,    33,    -1,    10,    11,    37,    38,
      39,    40,     1,    -1,    -1,    -1,     5,     6,     7,     8,
      24,    -1,    26,    12,    28,    -1,    -1,    31,    18,    33,
      20,    -1,    -1,    37,    38,    39,    40,    -1,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    35,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    -1,    32,    33,    -1,    -1,
      36,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    -1,
      32,    33,    -1,    -1,    36,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,    -1,    35,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    32,    33,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    33,    13,    14,    15,
      -1,    -1,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    -1,    13,    33,    15,    -1,
      -1,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    13,    -1,    33,    -1,    -1,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    18,    33,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    18,    33,    20,
      -1,    22,    23,    -1,    25,    -1,    27,    28,    29,    26,
      -1,    28,    33,    -1,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    26,    -1,    28,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,     6,     7,     8,    12,    42,    43,    44,
      48,    52,    53,     0,    43,    43,    43,     1,    37,    49,
      54,    36,    17,    26,    24,    36,    45,    36,    26,    28,
      31,    33,    37,    38,    39,    40,    56,    50,    51,    53,
       4,    10,    11,    24,    46,    47,    52,    53,    55,    56,
       1,    56,    56,    56,    56,    26,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    25,    27,    28,
      29,    30,    32,    33,    35,    19,    37,    26,    26,    36,
      56,    46,    34,    46,    37,    36,    35,    35,    19,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    50,    56,    56,
      36,    34,    35,    35,    35,    55,    55,     9,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    44,    45,    46,
      46,    47,    47,    48,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     3,     3,     2,
       0,     1,     1,     3,     4,     3,     1,     0,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     7,     5,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     4,     1,
       1,     1,     1,     3,     3
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
#line 60 "uccompiler.y"
                                  {
    if (debug) printf("Program\n");

    if ((yyvsp[0].no)) {
        root = create("Program", "");
        addChild(root, (yyvsp[0].no));  
        (yyval.no) = root;
    } else {
        (yyval.no) = NULL;
    }
}
#line 1418 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarations  */
#line 73 "uccompiler.y"
                                                                      {
    (yyval.no) = (yyvsp[-1].no);
    }
#line 1426 "y.tab.c"
    break;

  case 4: /* FunctionsAndDeclarations: FunctionDeclaration FunctionsAndDeclarations  */
#line 76 "uccompiler.y"
                                                   {
        if (debug) printf("Function Declaration\n");
        (yyval.no) = create("FuncDeclaration", "");
        addChild((yyval.no), (yyvsp[-1].no));  
        addBrother((yyval.no), (yyvsp[0].no));  
    }
#line 1437 "y.tab.c"
    break;

  case 5: /* FunctionsAndDeclarations: Declaration FunctionsAndDeclarations  */
#line 82 "uccompiler.y"
                                           {
        if (debug) printf("Declaration\n");
        (yyval.no) = create("Declaration", "");
        addChild((yyval.no), (yyvsp[-1].no));  
        addBrother((yyval.no), (yyvsp[0].no)); 
    }
#line 1448 "y.tab.c"
    break;

  case 6: /* FunctionsAndDeclarations: %empty  */
#line 88 "uccompiler.y"
      { if (debug) printf("Empty\n"); (yyval.no) = NULL; }
#line 1454 "y.tab.c"
    break;

  case 7: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 91 "uccompiler.y"
                                                             {
    if (debug) printf("Function Definition\n");
    (yyval.no) = create("FuncDefinition", "");
    addChild((yyval.no), (yyvsp[-2].no));  
    addChild((yyval.no), (yyvsp[-1].no));  
    addChild((yyval.no), (yyvsp[0].no));  
}
#line 1466 "y.tab.c"
    break;

  case 8: /* FunctionBody: LBRACE DeclarationsAndStatements RBRACE  */
#line 100 "uccompiler.y"
                                                      {
    if (debug) printf("Function Body\n");
    (yyval.no) = create("FuncBody", "");
    addChild((yyval.no), (yyvsp[-1].no));  
}
#line 1476 "y.tab.c"
    break;

  case 9: /* DeclarationsAndStatements: StatementOrDeclaration DeclarationsAndStatements  */
#line 107 "uccompiler.y"
                        {if (debug) printf("Declarations and Statements\n"); }
#line 1482 "y.tab.c"
    break;

  case 10: /* DeclarationsAndStatements: %empty  */
#line 108 "uccompiler.y"
                        {if (debug) printf("Empty\n");}
#line 1488 "y.tab.c"
    break;

  case 11: /* StatementOrDeclaration: Statement  */
#line 111 "uccompiler.y"
                                  { if (debug) printf("Statement\n"); }
#line 1494 "y.tab.c"
    break;

  case 12: /* StatementOrDeclaration: Declaration  */
#line 112 "uccompiler.y"
                                  { if (debug) printf("Declaration\n"); }
#line 1500 "y.tab.c"
    break;

  case 13: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 115 "uccompiler.y"
                                                      { if (debug) printf("Function Declaration\n"); }
#line 1506 "y.tab.c"
    break;

  case 14: /* FunctionDeclarator: ID LPAR ParameterList RPAR  */
#line 118 "uccompiler.y"
                                              { if (debug) printf("Function Declarator\n"); }
#line 1512 "y.tab.c"
    break;

  case 15: /* ParameterList: ParameterDeclaration COMMA ParameterList  */
#line 121 "uccompiler.y"
                                                        { if (debug) printf("Parameter List\n"); }
#line 1518 "y.tab.c"
    break;

  case 16: /* ParameterList: ParameterDeclaration  */
#line 122 "uccompiler.y"
                                    { if (debug) printf("Parameter List\n"); }
#line 1524 "y.tab.c"
    break;

  case 17: /* ParameterList: %empty  */
#line 123 "uccompiler.y"
               { if (debug) printf("Empty\n"); }
#line 1530 "y.tab.c"
    break;

  case 18: /* ParameterDeclaration: TypeSpec ID  */
#line 126 "uccompiler.y"
                                  { if (debug) printf("Parameter Declaration\n"); }
#line 1536 "y.tab.c"
    break;

  case 19: /* ParameterDeclaration: TypeSpec  */
#line 127 "uccompiler.y"
                              { if (debug) printf("Parameter Declaration\n"); }
#line 1542 "y.tab.c"
    break;

  case 20: /* Declaration: TypeSpec Declarator SEMI  */
#line 130 "uccompiler.y"
                                      { if (debug) printf("Declaration\n"); }
#line 1548 "y.tab.c"
    break;

  case 21: /* Declaration: TypeSpec error SEMI  */
#line 131 "uccompiler.y"
                                 {  (yyval.no) = NULL; errorflag = true; }
#line 1554 "y.tab.c"
    break;

  case 22: /* TypeSpec: CHAR  */
#line 135 "uccompiler.y"
               { if (debug) printf("Type: char\n"); }
#line 1560 "y.tab.c"
    break;

  case 23: /* TypeSpec: INT  */
#line 136 "uccompiler.y"
              { if (debug) printf("Type: int\n"); }
#line 1566 "y.tab.c"
    break;

  case 24: /* TypeSpec: VOID  */
#line 137 "uccompiler.y"
               { if (debug) printf("Type: void\n"); }
#line 1572 "y.tab.c"
    break;

  case 25: /* TypeSpec: SHORT  */
#line 138 "uccompiler.y"
                { if (debug) printf("Type: short\n"); }
#line 1578 "y.tab.c"
    break;

  case 26: /* TypeSpec: DOUBLE  */
#line 139 "uccompiler.y"
                 { if (debug) printf("Type: double\n"); }
#line 1584 "y.tab.c"
    break;

  case 27: /* TypeSpec: error  */
#line 140 "uccompiler.y"
                { (yyval.no) = NULL; errorflag = true;  }
#line 1590 "y.tab.c"
    break;

  case 28: /* Declarator: ID  */
#line 143 "uccompiler.y"
               { if (debug) printf("Declarator\n"); }
#line 1596 "y.tab.c"
    break;

  case 29: /* Declarator: ID ASSIGN Expr  */
#line 144 "uccompiler.y"
                           { if (debug) printf("Declarator\n"); }
#line 1602 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE DeclarationsAndStatements RBRACE  */
#line 147 "uccompiler.y"
                                                   { if (debug) printf("Compound Statement\n"); }
#line 1608 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 148 "uccompiler.y"
                                      { if (debug) printf("If Statement\n"); }
#line 1614 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 149 "uccompiler.y"
                                                     { if (debug) printf("If-Else Statement\n"); }
#line 1620 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 150 "uccompiler.y"
                                         { if (debug) printf("While Loop\n"); }
#line 1626 "y.tab.c"
    break;

  case 34: /* Statement: RETURN SEMI  */
#line 151 "uccompiler.y"
                      { if (debug) printf("Return Statement\n"); }
#line 1632 "y.tab.c"
    break;

  case 35: /* Statement: RETURN Expr SEMI  */
#line 152 "uccompiler.y"
                           { if (debug) printf("Return Statement with Value\n"); }
#line 1638 "y.tab.c"
    break;

  case 36: /* Statement: Expr SEMI  */
#line 153 "uccompiler.y"
                    { if (debug) printf("Expression Statement\n"); }
#line 1644 "y.tab.c"
    break;

  case 37: /* Expr: Expr ASSIGN Expr  */
#line 156 "uccompiler.y"
                       { if (debug) printf("Assign\n"); }
#line 1650 "y.tab.c"
    break;

  case 38: /* Expr: Expr COMMA Expr  */
#line 157 "uccompiler.y"
                      { if (debug) printf("Comma\n"); }
#line 1656 "y.tab.c"
    break;

  case 39: /* Expr: Expr PLUS Expr  */
#line 158 "uccompiler.y"
                     { if (debug) printf("Addition\n"); }
#line 1662 "y.tab.c"
    break;

  case 40: /* Expr: Expr MINUS Expr  */
#line 159 "uccompiler.y"
                      { if (debug) printf("Subtraction\n"); }
#line 1668 "y.tab.c"
    break;

  case 41: /* Expr: Expr MUL Expr  */
#line 160 "uccompiler.y"
                    { if (debug) printf("Multiplication\n"); }
#line 1674 "y.tab.c"
    break;

  case 42: /* Expr: Expr DIV Expr  */
#line 161 "uccompiler.y"
                    { if (debug) printf("Division\n"); }
#line 1680 "y.tab.c"
    break;

  case 43: /* Expr: Expr MOD Expr  */
#line 162 "uccompiler.y"
                    { if (debug) printf("Mod\n"); }
#line 1686 "y.tab.c"
    break;

  case 44: /* Expr: Expr OR Expr  */
#line 163 "uccompiler.y"
                   { if (debug) printf("Logical OR\n"); }
#line 1692 "y.tab.c"
    break;

  case 45: /* Expr: Expr AND Expr  */
#line 164 "uccompiler.y"
                    { if (debug) printf("Logical AND\n"); }
#line 1698 "y.tab.c"
    break;

  case 46: /* Expr: Expr BITWISEAND Expr  */
#line 165 "uccompiler.y"
                           { if (debug) printf("Bitwise AND\n"); }
#line 1704 "y.tab.c"
    break;

  case 47: /* Expr: Expr BITWISEOR Expr  */
#line 166 "uccompiler.y"
                          { if (debug) printf("Bitwise OR\n"); }
#line 1710 "y.tab.c"
    break;

  case 48: /* Expr: Expr BITWISEXOR Expr  */
#line 167 "uccompiler.y"
                           { if (debug) printf("Bitwise XOR\n"); }
#line 1716 "y.tab.c"
    break;

  case 49: /* Expr: Expr EQ Expr  */
#line 168 "uccompiler.y"
                   { if (debug) printf("Equal\n"); }
#line 1722 "y.tab.c"
    break;

  case 50: /* Expr: Expr NE Expr  */
#line 169 "uccompiler.y"
                   { if (debug) printf("Not Equal\n"); }
#line 1728 "y.tab.c"
    break;

  case 51: /* Expr: Expr LE Expr  */
#line 170 "uccompiler.y"
                   { if (debug) printf("Less Than or Equal\n"); }
#line 1734 "y.tab.c"
    break;

  case 52: /* Expr: Expr GE Expr  */
#line 171 "uccompiler.y"
                   { if (debug) printf("Greater Than or Equal\n"); }
#line 1740 "y.tab.c"
    break;

  case 53: /* Expr: Expr LT Expr  */
#line 172 "uccompiler.y"
                   { if (debug) printf("Less Than\n"); }
#line 1746 "y.tab.c"
    break;

  case 54: /* Expr: Expr GT Expr  */
#line 173 "uccompiler.y"
                   { if (debug) printf("Greater Than\n"); }
#line 1752 "y.tab.c"
    break;

  case 55: /* Expr: PLUS Expr  */
#line 174 "uccompiler.y"
                { if (debug) printf("Unary Plus\n"); }
#line 1758 "y.tab.c"
    break;

  case 56: /* Expr: MINUS Expr  */
#line 175 "uccompiler.y"
                 { if (debug) printf("Unary Minus\n"); }
#line 1764 "y.tab.c"
    break;

  case 57: /* Expr: NOT Expr  */
#line 176 "uccompiler.y"
               { if (debug) printf("Logical NOT\n"); }
#line 1770 "y.tab.c"
    break;

  case 58: /* Expr: ID LPAR COMMA RPAR  */
#line 177 "uccompiler.y"
                         { if (debug) printf("Function Call\n"); }
#line 1776 "y.tab.c"
    break;

  case 59: /* Expr: ID  */
#line 178 "uccompiler.y"
         { if (debug) printf("Identifier\n" ); }
#line 1782 "y.tab.c"
    break;

  case 60: /* Expr: NATURAL  */
#line 179 "uccompiler.y"
              { if (debug) printf("Natural: \n" ); }
#line 1788 "y.tab.c"
    break;

  case 61: /* Expr: CHRLIT  */
#line 180 "uccompiler.y"
             { if (debug) printf("Char Literal: \n" ); }
#line 1794 "y.tab.c"
    break;

  case 62: /* Expr: DECIMAL  */
#line 181 "uccompiler.y"
              { if (debug) printf("Decimal: \n"); }
#line 1800 "y.tab.c"
    break;

  case 63: /* Expr: LPAR Expr RPAR  */
#line 182 "uccompiler.y"
                     { }
#line 1806 "y.tab.c"
    break;

  case 64: /* Expr: LPAR error RPAR  */
#line 183 "uccompiler.y"
                      { (yyval.no) = NULL; errorflag = true; }
#line 1812 "y.tab.c"
    break;


#line 1816 "y.tab.c"

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

#line 189 "uccompiler.y"


