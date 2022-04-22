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
#line 9 "gocompiler.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "functions.h"
    #include "symbol_table.h"
    #include "semantics.h"
    #include "structures.h"

    extern int column;
    extern int errColumn;
    extern int errLine;
    extern int line;
 
    extern int errorBrace2;
    extern int errorBrace;



    int flag=0;

    int yylex (void);
    int yylex_destroy();

    void yyerror(char *s);

    extern char *yytext;
    extern int yyleng;
    extern int yywrap();
    int printTree=0;

#line 104 "y.tab.c"

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

#line 255 "y.tab.c"

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
  YYSYMBOL_FUNC = 3,                       /* FUNC  */
  YYSYMBOL_PACKAGE = 4,                    /* PACKAGE  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_BLANKID = 7,                    /* BLANKID  */
  YYSYMBOL_ASSIGN = 8,                     /* ASSIGN  */
  YYSYMBOL_STAR = 9,                       /* STAR  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_RPAR = 19,                      /* RPAR  */
  YYSYMBOL_LPAR = 20,                      /* LPAR  */
  YYSYMBOL_LSQ = 21,                       /* LSQ  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_RSQ = 28,                       /* RSQ  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_FOR = 31,                       /* FOR  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_VAR = 33,                       /* VAR  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_FLOAT32 = 35,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 36,                      /* BOOL  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_PRINT = 38,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 39,                  /* PARSEINT  */
  YYSYMBOL_CMDARGS = 40,                   /* CMDARGS  */
  YYSYMBOL_INTLIT = 41,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 42,                   /* REALLIT  */
  YYSYMBOL_RESERVED = 43,                  /* RESERVED  */
  YYSYMBOL_STRLIT = 44,                    /* STRLIT  */
  YYSYMBOL_ID = 45,                        /* ID  */
  YYSYMBOL_UNARY = 46,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_Program = 48,                   /* Program  */
  YYSYMBOL_Declarations = 49,              /* Declarations  */
  YYSYMBOL_VarDeclaration = 50,            /* VarDeclaration  */
  YYSYMBOL_VarSpec = 51,                   /* VarSpec  */
  YYSYMBOL_ci = 52,                        /* ci  */
  YYSYMBOL_Type = 53,                      /* Type  */
  YYSYMBOL_FuncDeclaration = 54,           /* FuncDeclaration  */
  YYSYMBOL_para = 55,                      /* para  */
  YYSYMBOL_ty = 56,                        /* ty  */
  YYSYMBOL_Parameters = 57,                /* Parameters  */
  YYSYMBOL_cit = 58,                       /* cit  */
  YYSYMBOL_FuncBody = 59,                  /* FuncBody  */
  YYSYMBOL_VarsAndStatements = 60,         /* VarsAndStatements  */
  YYSYMBOL_vds = 61,                       /* vds  */
  YYSYMBOL_Statement = 62,                 /* Statement  */
  YYSYMBOL_ss = 63,                        /* ss  */
  YYSYMBOL_elr = 64,                       /* elr  */
  YYSYMBOL_exp = 65,                       /* exp  */
  YYSYMBOL_ParseArgs = 66,                 /* ParseArgs  */
  YYSYMBOL_FuncInvocation = 67,            /* FuncInvocation  */
  YYSYMBOL_expcexp = 68,                   /* expcexp  */
  YYSYMBOL_cexp = 69,                      /* cexp  */
  YYSYMBOL_Expr = 70                       /* Expr  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    86,    88,    96,   106,   111,   116,   188,
     190,   206,   211,   216,   221,   228,   246,   251,   254,   257,
     259,   287,   290,   316,   326,   328,   344,   346,   350,   354,
     364,   376,   404,   418,   426,   431,   436,   444,   454,   457,
     459,   479,   481,   491,   493,   497,   508,   511,   527,   529,
     544,   549,   551,   569,   577,   585,   593,   601,   609,   617,
     625,   633,   641,   650,   658,   666,   674,   682,   689,   696,
     701,   706,   709,   711,   713
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
  "\"end of file\"", "error", "\"invalid token\"", "FUNC", "PACKAGE",
  "SEMICOLON", "COMMA", "BLANKID", "ASSIGN", "STAR", "DIV", "MINUS",
  "PLUS", "EQ", "GE", "GT", "LBRACE", "RBRACE", "LE", "RPAR", "LPAR",
  "LSQ", "LT", "MOD", "NE", "NOT", "AND", "OR", "RSQ", "RETURN", "ELSE",
  "FOR", "IF", "VAR", "INT", "FLOAT32", "BOOL", "STRING", "PRINT",
  "PARSEINT", "CMDARGS", "INTLIT", "REALLIT", "RESERVED", "STRLIT", "ID",
  "UNARY", "$accept", "Program", "Declarations", "VarDeclaration",
  "VarSpec", "ci", "Type", "FuncDeclaration", "para", "ty", "Parameters",
  "cit", "FuncBody", "VarsAndStatements", "vds", "Statement", "ss", "elr",
  "exp", "ParseArgs", "FuncInvocation", "expcexp", "cexp", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -36,    19,    15,   -73,    -1,   -24,   -16,   -73,    25,
      26,    30,     8,    52,   -73,    -1,    -1,    14,    57,    21,
      39,   -73,   -73,    39,    48,   -73,    50,    52,   -73,   -73,
     -73,   -73,   -73,    72,    39,   -73,   -73,    36,   -73,   -73,
      66,    39,   -73,   -73,    72,    55,   -73,   -73,    32,   -73,
      97,    97,    97,    63,     2,   -73,    80,   -73,   -73,   -73,
      84,    89,    97,    97,    91,    97,   -73,   -73,    81,   -73,
     -73,   230,    96,   173,    85,   100,    97,    79,   -73,    32,
     -73,   -73,   -73,    94,   192,   -73,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    32,
      32,    95,   211,   107,   230,   -73,    99,   134,   -73,   -73,
     -73,   -73,   -73,    42,    42,   283,   283,   283,   283,   283,
     -73,   283,   267,   249,   102,   106,   -73,   -73,    86,   -73,
      97,   -73,   -73,    98,   111,   134,   118,   -73,    17,   -73,
      32,   116,   120,   133,   -73,    97,   -73,   153,   132,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     0,
       0,     0,     0,     9,     6,     3,     3,    16,     0,     0,
       0,     4,     5,     0,     0,    17,     0,     9,    11,    12,
      13,    14,     8,    21,    18,     7,    10,     0,    20,    19,
       0,     0,    24,    15,    21,     0,    22,    38,     0,    23,
      43,    43,     0,     0,     0,    27,     0,    28,    35,    34,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    33,
      72,    44,     0,     0,     0,     0,     0,     0,    25,     0,
      30,    67,    68,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    50,     0,    51,    40,    74,
      73,    63,    64,    62,    61,    57,    60,    56,    59,    55,
      65,    58,    54,    53,     0,     0,    37,    36,     0,    47,
       0,    49,    32,    41,     0,    51,     0,    31,     0,    52,
       0,     0,     0,     0,    46,     0,    42,     0,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,     0,    92,   141,   127,   -17,   -73,   -73,   -73,
     -73,   115,   -73,   -73,   -73,   110,   -72,   -73,   119,   -73,
     -45,   -73,    34,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    14,    20,    32,    10,    24,    40,
      25,    38,    43,    45,    56,    60,    61,   137,    69,    58,
      70,   106,   131,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    73,     6,    59,    12,     1,    33,   108,    75,     3,
      76,    81,    82,    84,    85,    21,    22,    39,   141,     4,
       5,    11,    77,   102,    44,   104,   107,   124,   125,    13,
      15,    16,     7,    47,    59,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    48,   -39,
      17,    86,    87,    13,    59,    59,    47,   142,    19,    23,
     -26,    50,    26,    51,    52,    95,    27,    34,   143,    35,
      53,    48,    49,    28,    29,    30,    31,    54,    37,   135,
     105,    41,    42,    74,    50,    78,    51,    52,     7,    79,
      62,    63,    83,    53,   147,    59,    62,    63,   -48,    64,
      54,    77,    62,    63,    65,    64,    80,   103,    62,    63,
      65,    64,    99,   109,   126,   128,    65,    64,   129,   132,
      66,    67,    65,   133,    68,   134,    66,    67,   136,   101,
      68,   138,    66,    67,   140,   144,    68,    55,    66,    67,
     130,   145,    68,    86,    87,    88,    89,    90,    91,    92,
     146,   149,    93,    18,    36,    57,    94,    95,    96,    46,
      97,    98,    86,    87,    88,    89,    90,    91,    92,   139,
      72,    93,     0,     0,     0,    94,    95,    96,     0,    97,
      98,   148,    86,    87,    88,    89,    90,    91,    92,   100,
       0,    93,     0,     0,     0,    94,    95,    96,     0,    97,
      98,    86,    87,    88,    89,    90,    91,    92,     0,     0,
      93,   110,     0,     0,    94,    95,    96,     0,    97,    98,
      86,    87,    88,    89,    90,    91,    92,     0,     0,    93,
     127,     0,     0,    94,    95,    96,     0,    97,    98,    86,
      87,    88,    89,    90,    91,    92,     0,     0,    93,     0,
       0,     0,    94,    95,    96,     0,    97,    98,    86,    87,
      88,    89,    90,    91,    92,     0,     0,    93,     0,     0,
       0,    94,    95,    96,     0,    97,    86,    87,    88,    89,
      90,    91,    92,     0,     0,    93,     0,     0,     0,    94,
      95,    96,    86,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
      45,    52,     3,    48,    20,     4,    23,    79,     6,    45,
       8,    62,    63,    64,    65,    15,    16,    34,     1,     0,
       5,    45,    20,    74,    41,    76,    77,    99,   100,    45,
       5,     5,    33,     1,    79,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    16,    17,
      20,     9,    10,    45,    99,   100,     1,    40,     6,    45,
       5,    29,     5,    31,    32,    23,    45,    19,   140,    19,
      38,    16,    17,    34,    35,    36,    37,    45,     6,   130,
       1,    45,    16,    20,    29,     5,    31,    32,    33,     5,
      11,    12,     1,    38,   145,   140,    11,    12,    19,    20,
      45,    20,    11,    12,    25,    20,    17,     7,    11,    12,
      25,    20,    16,    19,    19,     8,    25,    20,    19,    17,
      41,    42,    25,    17,    45,    39,    41,    42,    30,    44,
      45,    20,    41,    42,    16,    19,    45,    45,    41,    42,
       6,    21,    45,     9,    10,    11,    12,    13,    14,    15,
      17,    19,    18,    12,    27,    45,    22,    23,    24,    44,
      26,    27,     9,    10,    11,    12,    13,    14,    15,   135,
      51,    18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      27,    28,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      27,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    -1,    26,    27,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    26,    27,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    27,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    48,    45,     0,     5,     3,    33,    49,    50,
      54,    45,    20,    45,    51,     5,     5,    20,    51,     6,
      52,    49,    49,    45,    55,    57,     5,    45,    34,    35,
      36,    37,    53,    53,    19,    19,    52,     6,    58,    53,
      56,    45,    16,    59,    53,    60,    58,     1,    16,    17,
      29,    31,    32,    38,    45,    50,    61,    62,    66,    67,
      62,    63,    11,    12,    20,    25,    41,    42,    45,    65,
      67,    70,    65,    70,    20,     6,     8,    20,     5,     5,
      17,    70,    70,     1,    70,    70,     9,    10,    11,    12,
      13,    14,    15,    18,    22,    23,    24,    26,    27,    16,
      16,    44,    70,     7,    70,     1,    68,    70,    63,    19,
      19,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    63,    63,    19,    19,     8,    19,
       6,    69,    17,    17,    39,    70,    30,    64,    20,    69,
      16,     1,    40,    63,    19,    21,    17,    70,    28,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    53,    53,    54,    55,    55,    56,    56,
      57,    58,    58,    59,    60,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     3,     2,     5,     3,     0,
       3,     1,     1,     1,     1,     7,     0,     1,     0,     1,
       3,     0,     4,     3,     0,     3,     0,     1,     1,     3,
       3,     6,     5,     2,     1,     1,     4,     4,     1,     0,
       3,     0,     4,     0,     1,    11,     8,     4,     0,     2,
       1,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
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
  case 2: /* Program: PACKAGE ID SEMICOLON Declarations  */
#line 68 "gocompiler.y"
                                            {
                                           
                                            idToken * idaux = createID("",-1,-1);
                                            head= newNode("Program",idaux);
                                            if ((yyvsp[0].node) != NULL) {
                                               
                                                addNode((yyvsp[0].node), head);
                                                
                                            }
                                           (yyval.node)=head;
		                                   
                                           
                                           
		
                                            

}
#line 1446 "y.tab.c"
    break;

  case 3: /* Declarations: %empty  */
#line 86 "gocompiler.y"
                        { (yyval.node) = NULL; }
#line 1452 "y.tab.c"
    break;

  case 4: /* Declarations: VarDeclaration SEMICOLON Declarations  */
#line 88 "gocompiler.y"
                                                   {
               if ((yyvsp[0].node) != NULL) {
			        addSibling((yyvsp[-2].node), (yyvsp[0].node));
			    }
			    (yyval.node) = (yyvsp[-2].node);
                

            }
#line 1465 "y.tab.c"
    break;

  case 5: /* Declarations: FuncDeclaration SEMICOLON Declarations  */
#line 96 "gocompiler.y"
                                                    {

                if ((yyvsp[0].node) != NULL) {
				    addSibling((yyvsp[-2].node), (yyvsp[0].node));
			    }
			    (yyval.node) = (yyvsp[-2].node);


            }
#line 1479 "y.tab.c"
    break;

  case 6: /* VarDeclaration: VAR VarSpec  */
#line 106 "gocompiler.y"
                            {
                            (yyval.node)=(yyvsp[0].node);

                            }
#line 1488 "y.tab.c"
    break;

  case 7: /* VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR  */
#line 111 "gocompiler.y"
                                                {
                        (yyval.node) = (yyvsp[-2].node);
                        
                }
#line 1497 "y.tab.c"
    break;

  case 8: /* VarSpec: ID ci Type  */
#line 116 "gocompiler.y"
                    {
    //Lista com os vardecs
    idToken * idaux = createID("",-1,-1);
    node * vardecList = newNode("VarDecl",idaux);

    //cada elemento contem um vardec
    node * vardecs[100];
    
    node *firstId= newNode("Id",(yyvsp[-2].id));

    addNode((yyvsp[0].node),vardecList);
    addNode(firstId,vardecList);

   

    node *vardecsCI =(yyvsp[-1].node);
    int numIds=0;
    node *type;
    while(vardecsCI!=NULL){
        idToken * idaux = createID("",-1,-1);
        //Nova declaracao de var
        vardecs[numIds]=newNode("VarDecl",idaux);
        type=newNode((yyvsp[0].node)->type,idaux);
        //tipo
        addNode(type,vardecs[numIds]);
        //var
        addNode(vardecsCI,vardecs[numIds]);

        numIds++;
        vardecsCI=vardecsCI->sibling;
    }
  

    //retirar irmandade dos irmaos Ci
    node * aux2 = (yyvsp[-1].node);
    node *destroy;
    if(aux2!=NULL){
        if (aux2->sibling != NULL) {
        
					while(aux2 != NULL) {
                        
						destroy = aux2->sibling;
						aux2->sibling = NULL;
						aux2 = destroy;
					}
	    }
    }
    
   
    //torna vardecList e os restantes vardecs em irmaos
    if(numIds>0){
     

        addSibling(vardecList,vardecs[0]);
        if(numIds>1){
             
            
            for (int j=0;j<numIds-1;j++){
               
                addSibling(vardecs[j],vardecs[j+1]);
            }
        }
    }
    
   
                        
    (yyval.node)=vardecList;
    
   
}
#line 1572 "y.tab.c"
    break;

  case 9: /* ci: %empty  */
#line 188 "gocompiler.y"
              {(yyval.node) = NULL;}
#line 1578 "y.tab.c"
    break;

  case 10: /* ci: COMMA ID ci  */
#line 190 "gocompiler.y"
                         {

                node * id = newNode("Id",(yyvsp[-1].id));

                if((yyvsp[0].node)!=NULL){
                    (yyval.node)=addSibling(id,(yyvsp[0].node));
                   
                }
                else{
                    (yyval.node)=id;
                }
                

            }
#line 1597 "y.tab.c"
    break;

  case 11: /* Type: INT  */
#line 206 "gocompiler.y"
          {
        idToken * idaux = createID("",-1,-1);
        (yyval.node)=newNode("Int",idaux);
    }
#line 1606 "y.tab.c"
    break;

  case 12: /* Type: FLOAT32  */
#line 211 "gocompiler.y"
              {
        idToken * idaux = createID("",-1,-1);
        (yyval.node)=newNode("Float32",idaux);
        }
#line 1615 "y.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 216 "gocompiler.y"
          {
        idToken * idaux = createID("",-1,-1);
         (yyval.node)=newNode("Bool",idaux);
    }
#line 1624 "y.tab.c"
    break;

  case 14: /* Type: STRING  */
#line 221 "gocompiler.y"
            {
          idToken * idaux = createID("",-1,-1);
          (yyval.node)=newNode("String",idaux);
    
    }
#line 1634 "y.tab.c"
    break;

  case 15: /* FuncDeclaration: FUNC ID LPAR para RPAR ty FuncBody  */
#line 228 "gocompiler.y"
                                                    {
    idToken * idaux = createID("",-1,-1);
    node* funcDecl = newNode("FuncDecl",idaux);
    node* funcHead = newNode("FuncHeader",idaux);
    node * idHead= newNode("Id",(yyvsp[-5].id));
    addNode(idHead,funcHead);
    addNode((yyvsp[-1].node),funcHead);
    
    addNode((yyvsp[-3].node),funcHead);
    
    addNode(funcHead,funcDecl);
    addNode((yyvsp[0].node),funcDecl);
    (yyval.node)=funcDecl;


}
#line 1655 "y.tab.c"
    break;

  case 16: /* para: %empty  */
#line 246 "gocompiler.y"
                {
      idToken * idaux = createID("",-1,-1);
    (yyval.node) = newNode("FuncParams", idaux);
    }
#line 1664 "y.tab.c"
    break;

  case 17: /* para: Parameters  */
#line 251 "gocompiler.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1670 "y.tab.c"
    break;

  case 18: /* ty: %empty  */
#line 254 "gocompiler.y"
              {(yyval.node) = NULL;}
#line 1676 "y.tab.c"
    break;

  case 19: /* ty: Type  */
#line 257 "gocompiler.y"
          {(yyval.node)=(yyvsp[0].node);}
#line 1682 "y.tab.c"
    break;

  case 20: /* Parameters: ID Type cit  */
#line 259 "gocompiler.y"
                        {
      idToken * idaux = createID("",-1,-1);
   node * funcPara = newNode("FuncParams",idaux);

   node * firstparaDecl= newNode("ParamDecl",idaux);
   node * firstId = newNode("Id",(yyvsp[-2].id));
   addNode((yyvsp[-1].node),firstparaDecl);
   addNode(firstId,firstparaDecl);
   if((yyvsp[0].node)!=NULL){
       addSibling(firstparaDecl,(yyvsp[0].node));
   }
   //node *aux2=firstparaDecl;
    if(firstparaDecl != NULL) {

        addNode(firstparaDecl,funcPara);
        (yyval.node) = funcPara;

    }
    else {
        (yyval.node) = funcPara;
    }
   
   
   

}
#line 1713 "y.tab.c"
    break;

  case 21: /* cit: %empty  */
#line 287 "gocompiler.y"
               { (yyval.node) = NULL;}
#line 1719 "y.tab.c"
    break;

  case 22: /* cit: COMMA ID Type cit  */
#line 290 "gocompiler.y"
                        {
        //parametro
          idToken * idaux = createID("",-1,-1);
        node * paraDecl = newNode("ParamDecl",idaux);
        //adiciona o tipo como filho do parametro
        
        addNode((yyvsp[-1].node),paraDecl);
        //adiciona id como filho do parametro
        node * id = newNode("Id",(yyvsp[-2].id));
        (yyval.node)=addNode(id,paraDecl);

        
        if((yyvsp[-1].node)!=NULL){
            //parametros ficam irmaos
            addSibling(paraDecl, (yyvsp[0].node));
        }
        else{
            (yyval.node)=id;

        }

    }
#line 1746 "y.tab.c"
    break;

  case 23: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 316 "gocompiler.y"
                                          {
      idToken * idaux = createID("",-1,-1);
    node* funcBody = newNode("FuncBody", idaux);
    if((yyvsp[-1].node)!=NULL){
        addNode((yyvsp[-1].node),funcBody);
    }
    (yyval.node)=funcBody;
  
}
#line 1760 "y.tab.c"
    break;

  case 24: /* VarsAndStatements: %empty  */
#line 326 "gocompiler.y"
                             {(yyval.node) = NULL;}
#line 1766 "y.tab.c"
    break;

  case 25: /* VarsAndStatements: VarsAndStatements vds SEMICOLON  */
#line 328 "gocompiler.y"
                                    {
        if ((yyvsp[-1].node) == NULL && (yyvsp[-2].node) == NULL){
            (yyval.node) = NULL;
        }
		else if ((yyvsp[-2].node) == NULL){ 
            (yyval.node) = (yyvsp[-1].node);
            }
		else if ((yyvsp[-1].node) == NULL){ 
            (yyval.node) = (yyvsp[-2].node);
            }
		else{ 
            (yyval.node) = addSibling((yyvsp[-2].node), (yyvsp[-1].node));
            }
    }
#line 1785 "y.tab.c"
    break;

  case 26: /* vds: %empty  */
#line 344 "gocompiler.y"
               {(yyval.node) = NULL;}
#line 1791 "y.tab.c"
    break;

  case 27: /* vds: VarDeclaration  */
#line 346 "gocompiler.y"
                    {
      (yyval.node)=(yyvsp[0].node);
      }
#line 1799 "y.tab.c"
    break;

  case 28: /* vds: Statement  */
#line 350 "gocompiler.y"
               {
        (yyval.node) = (yyvsp[0].node);
        }
#line 1807 "y.tab.c"
    break;

  case 29: /* Statement: ID ASSIGN Expr  */
#line 354 "gocompiler.y"
                          {
            idToken * idaux = createID("",-1,-1);
            node * assign = newNode("Assign", idaux);
            node * statementId = newNode("Id", (yyvsp[-2].id));
            addNode(statementId, assign);
            if((yyvsp[0].node) != NULL) {addNode((yyvsp[0].node), assign);}
            (yyval.node) = assign;

        }
#line 1821 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE ss RBRACE  */
#line 364 "gocompiler.y"
                      {

        if((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->sibling != NULL) { 
            idToken * idaux = createID("",-1,-1);
            node *block = newNode("Block", idaux);
            addNode((yyvsp[-1].node), block);
            (yyval.node) = block;
        }
        else{(yyval.node)= (yyvsp[-1].node);}

    }
#line 1837 "y.tab.c"
    break;

  case 31: /* Statement: IF Expr LBRACE ss RBRACE elr  */
#line 376 "gocompiler.y"
                                  {
          idToken * idaux = createID("",-1,-1);
        node * statementIf = newNode("If", idaux);
        
        if((yyvsp[-4].node) != NULL){
            addNode((yyvsp[-4].node), statementIf);
        }
          
        node * blockIfStart = newNode("Block", idaux);
        addNode(blockIfStart, statementIf);

        if((yyvsp[-2].node) != NULL) {
            addNode((yyvsp[-2].node), blockIfStart);
        }

        if((yyvsp[0].node) == NULL) {
              idToken * idaux = createID("",-1,-1);
            node * blockIfEnd = newNode("Block", idaux);
            addNode(blockIfEnd, statementIf);
        }
        else{
            addNode((yyvsp[0].node), statementIf);
        }
      
        (yyval.node) = statementIf;

    }
#line 1869 "y.tab.c"
    break;

  case 32: /* Statement: FOR exp LBRACE ss RBRACE  */
#line 404 "gocompiler.y"
                              {
          idToken * idaux = createID("",-1,-1);
        node * statementFor = newNode("For", idaux);
        
        node * blockFor = newNode("Block", idaux);
        addNode((yyvsp[-3].node), statementFor);
        addNode(blockFor, statementFor);
        if((yyvsp[-1].node) != NULL) {
            addNode((yyvsp[-1].node), blockFor);
        }
        (yyval.node) = statementFor;

    }
#line 1887 "y.tab.c"
    break;

  case 33: /* Statement: RETURN exp  */
#line 418 "gocompiler.y"
                {
          idToken * idaux = createID("",-1,-1);
        node * ret = newNode("Return", idaux);
        addNode((yyvsp[0].node), ret);
        (yyval.node) = ret;
        
    }
#line 1899 "y.tab.c"
    break;

  case 34: /* Statement: FuncInvocation  */
#line 426 "gocompiler.y"
                    { 

        (yyval.node) = (yyvsp[0].node);
    }
#line 1908 "y.tab.c"
    break;

  case 35: /* Statement: ParseArgs  */
#line 431 "gocompiler.y"
               {

        (yyval.node) = (yyvsp[0].node);
    }
#line 1917 "y.tab.c"
    break;

  case 36: /* Statement: PRINT LPAR Expr RPAR  */
#line 436 "gocompiler.y"
                          {
          idToken * idaux = createID("",-1,-1);
        node * print = newNode("Print", idaux);
        addNode((yyvsp[-1].node), print);
        (yyval.node) = print;

    }
#line 1929 "y.tab.c"
    break;

  case 37: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 444 "gocompiler.y"
                            {
          idToken * idaux = createID("",-1,-1);
        node * print = newNode("Print",idaux);
          idToken * idaux2 = createID((yyvsp[-1].str),-1,-1);
        node * strlit = newNode("StrLit", idaux2);
        addNode(strlit,print);
        (yyval.node) = print;

    }
#line 1943 "y.tab.c"
    break;

  case 38: /* Statement: error  */
#line 454 "gocompiler.y"
            {(yyval.node) = NULL;}
#line 1949 "y.tab.c"
    break;

  case 39: /* ss: %empty  */
#line 457 "gocompiler.y"
              {(yyval.node) = NULL;}
#line 1955 "y.tab.c"
    break;

  case 40: /* ss: Statement SEMICOLON ss  */
#line 459 "gocompiler.y"
                            {
        if ((yyvsp[-2].node) == NULL && (yyvsp[0].node) == NULL) {
            (yyval.node) = NULL;
        }
			else if ((yyvsp[-2].node) == NULL) {
                (yyval.node) = (yyvsp[0].node);
            }
			else if ((yyvsp[0].node) == NULL){ 
                (yyval.node) = (yyvsp[-2].node);
            }
			else {
                (yyval.node) = addSibling((yyvsp[-2].node), (yyvsp[0].node));
            }
                


    }
#line 1977 "y.tab.c"
    break;

  case 41: /* elr: %empty  */
#line 479 "gocompiler.y"
               {(yyval.node) = NULL;}
#line 1983 "y.tab.c"
    break;

  case 42: /* elr: ELSE LBRACE ss RBRACE  */
#line 481 "gocompiler.y"
                           {
        idToken * idaux = createID("",-1,-1);
        node * blockElse = newNode("Block", idaux);
        if((yyvsp[-1].node) != NULL) {addNode((yyvsp[-1].node), blockElse);}
        (yyval.node) = blockElse;

    }
#line 1995 "y.tab.c"
    break;

  case 43: /* exp: %empty  */
#line 491 "gocompiler.y"
               {(yyval.node) = NULL;}
#line 2001 "y.tab.c"
    break;

  case 44: /* exp: Expr  */
#line 493 "gocompiler.y"
          {(yyval.node)=(yyvsp[0].node);}
#line 2007 "y.tab.c"
    break;

  case 45: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 497 "gocompiler.y"
                                                                           {
                idToken * idaux = createID("",-1,-1);
                node * parseArgs=newNode("ParseArgs",idaux);
                node * id=newNode("Id",(yyvsp[-10].id));
                addNode(id,parseArgs);
                if((yyvsp[-2].node)!=NULL){
                    addNode((yyvsp[-2].node),parseArgs);
                }
                (yyval.node)=parseArgs;
            }
#line 2022 "y.tab.c"
    break;

  case 46: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 508 "gocompiler.y"
                                                           {printTree=1;(yyval.node) = NULL;}
#line 2028 "y.tab.c"
    break;

  case 47: /* FuncInvocation: ID LPAR expcexp RPAR  */
#line 511 "gocompiler.y"
                                     {
                      idToken * idaux = createID("",-1,-1);
                    node * call = newNode("Call",idaux);
                    node * id = newNode("Id",(yyvsp[-3].id));
                    addNode(id,call);
                    if((yyvsp[-1].node)!=NULL){
                        addNode((yyvsp[-1].node),call);
                    }
                    (yyval.node)=call;

                    }
#line 2044 "y.tab.c"
    break;

  case 48: /* expcexp: %empty  */
#line 527 "gocompiler.y"
                   {(yyval.node) = NULL;}
#line 2050 "y.tab.c"
    break;

  case 49: /* expcexp: Expr cexp  */
#line 529 "gocompiler.y"
               {
        if ((yyvsp[-1].node) == NULL && (yyvsp[0].node) == NULL){ 
            (yyval.node) = NULL;
            }
		else if((yyvsp[-1].node)==NULL){ 
            (yyval.node) = (yyvsp[0].node);
            }
		else if((yyvsp[0].node)==NULL) {
            (yyval.node) = (yyvsp[-1].node);
            }
		else{ (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node));
            }

    }
#line 2069 "y.tab.c"
    break;

  case 50: /* expcexp: error  */
#line 544 "gocompiler.y"
          {printTree=1;(yyval.node) = NULL;}
#line 2075 "y.tab.c"
    break;

  case 51: /* cexp: %empty  */
#line 549 "gocompiler.y"
                {(yyval.node) = NULL;}
#line 2081 "y.tab.c"
    break;

  case 52: /* cexp: COMMA Expr cexp  */
#line 551 "gocompiler.y"
                     {
        if ((yyvsp[-1].node) == NULL && (yyvsp[0].node) == NULL) {
            (yyval.node) = NULL;
            }
        
		else if((yyvsp[-1].node)==NULL){ 
            (yyval.node) = (yyvsp[0].node);
            }

			else if((yyvsp[0].node)==NULL){
                 (yyval.node) = (yyvsp[-1].node);
                 }
			else {
                (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node));
                }

    }
#line 2103 "y.tab.c"
    break;

  case 53: /* Expr: Expr OR Expr  */
#line 569 "gocompiler.y"
                   {
      idToken * idaux = createID("",-1,-1);
        node * orr = newNode("Or",idaux);
        addNode((yyvsp[-2].node),orr);
        addNode((yyvsp[0].node),orr);
        (yyval.node)=orr;
    }
#line 2115 "y.tab.c"
    break;

  case 54: /* Expr: Expr AND Expr  */
#line 577 "gocompiler.y"
                   {
          idToken * idaux = createID("",-1,-1);
        node * andd = newNode("And",idaux);
        addNode((yyvsp[-2].node),andd);
        addNode((yyvsp[0].node),andd);
        (yyval.node)=andd;
    }
#line 2127 "y.tab.c"
    break;

  case 55: /* Expr: Expr LT Expr  */
#line 585 "gocompiler.y"
                  {
          idToken * idaux = createID("",-1,-1);
        node * lt = newNode("Lt",idaux);
        addNode((yyvsp[-2].node),lt);
        addNode((yyvsp[0].node),lt);
        (yyval.node)=lt;
    }
#line 2139 "y.tab.c"
    break;

  case 56: /* Expr: Expr GT Expr  */
#line 593 "gocompiler.y"
                  {
          idToken * idaux = createID("",-1,-1);
        node * gt = newNode("Gt",idaux);
        addNode((yyvsp[-2].node),gt);
        addNode((yyvsp[0].node),gt);
        (yyval.node)=gt;
    }
#line 2151 "y.tab.c"
    break;

  case 57: /* Expr: Expr EQ Expr  */
#line 601 "gocompiler.y"
                  {
          idToken * idaux = createID("",-1,-1);
        node * eq= newNode("Eq",idaux);
        addNode((yyvsp[-2].node),eq);
        addNode((yyvsp[0].node),eq);
        (yyval.node)=eq;
    }
#line 2163 "y.tab.c"
    break;

  case 58: /* Expr: Expr NE Expr  */
#line 609 "gocompiler.y"
                  {
          idToken * idaux = createID("",-1,-1);
        node * ne = newNode("Ne",idaux);
        addNode((yyvsp[-2].node),ne);
        addNode((yyvsp[0].node),ne);
        (yyval.node)=ne;
    }
#line 2175 "y.tab.c"
    break;

  case 59: /* Expr: Expr LE Expr  */
#line 617 "gocompiler.y"
                  {  
        idToken * idaux = createID("",-1,-1);
        node * le = newNode("Le",idaux);
        addNode((yyvsp[-2].node),le);
        addNode((yyvsp[0].node),le);
        (yyval.node)=le;
    }
#line 2187 "y.tab.c"
    break;

  case 60: /* Expr: Expr GE Expr  */
#line 625 "gocompiler.y"
                  {
          idToken * idaux = createID("",-1,-1);
        node * ge = newNode("Ge",idaux);
        addNode((yyvsp[-2].node),ge);
        addNode((yyvsp[0].node),ge);
        (yyval.node)=ge;
    }
#line 2199 "y.tab.c"
    break;

  case 61: /* Expr: Expr PLUS Expr  */
#line 633 "gocompiler.y"
                    {
          idToken * idaux = createID("",-1,-1);
        node * plus = newNode("Add",idaux);
        addNode((yyvsp[-2].node),plus);
        addNode((yyvsp[0].node),plus);
        (yyval.node)=plus;
    }
#line 2211 "y.tab.c"
    break;

  case 62: /* Expr: Expr MINUS Expr  */
#line 641 "gocompiler.y"
                     {
          idToken * idaux = createID("",-1,-1);
        node * sub= newNode("Sub",idaux);
        addNode((yyvsp[-2].node),sub);
        addNode((yyvsp[0].node),sub);
        (yyval.node)=sub;
    }
#line 2223 "y.tab.c"
    break;

  case 63: /* Expr: Expr STAR Expr  */
#line 650 "gocompiler.y"
                    {
          idToken * idaux = createID("",-1,-1);
        node * mult = newNode("Mul",idaux);
        addNode((yyvsp[-2].node),mult);
        addNode((yyvsp[0].node),mult);
        (yyval.node)=mult;
    }
#line 2235 "y.tab.c"
    break;

  case 64: /* Expr: Expr DIV Expr  */
#line 658 "gocompiler.y"
                   {
          idToken * idaux = createID("",-1,-1);
        node * div = newNode("Div",idaux);
        addNode((yyvsp[-2].node),div);
        addNode((yyvsp[0].node),div);
        (yyval.node)=div;}
#line 2246 "y.tab.c"
    break;

  case 65: /* Expr: Expr MOD Expr  */
#line 666 "gocompiler.y"
                   {
          idToken * idaux = createID("",-1,-1);
        node * mod = newNode("Mod",idaux);
        addNode((yyvsp[-2].node),mod);
        addNode((yyvsp[0].node),mod);
        (yyval.node)=mod;
    }
#line 2258 "y.tab.c"
    break;

  case 66: /* Expr: NOT Expr  */
#line 674 "gocompiler.y"
                          {
          idToken * idaux = createID("",-1,-1);
        node * nott=newNode("Not",idaux);
        addNode((yyvsp[0].node),nott);
        (yyval.node)=nott;

        }
#line 2270 "y.tab.c"
    break;

  case 67: /* Expr: MINUS Expr  */
#line 682 "gocompiler.y"
                           {
          idToken * idaux = createID("",-1,-1);
        node * minus=newNode("Minus",idaux);
        addNode((yyvsp[0].node),minus);
        (yyval.node)=minus;
    }
#line 2281 "y.tab.c"
    break;

  case 68: /* Expr: PLUS Expr  */
#line 689 "gocompiler.y"
                           {
          idToken * idaux = createID("",-1,-1);
        node * pluss=newNode("Plus",idaux);
        addNode((yyvsp[0].node),pluss);
        (yyval.node)=pluss;
    }
#line 2292 "y.tab.c"
    break;

  case 69: /* Expr: INTLIT  */
#line 696 "gocompiler.y"
            {
          idToken * idaux = createID((yyvsp[0].str),-1,-1);
        (yyval.node)=newNode("IntLit",idaux);
        }
#line 2301 "y.tab.c"
    break;

  case 70: /* Expr: REALLIT  */
#line 701 "gocompiler.y"
             {
          idToken * idaux = createID((yyvsp[0].str),-1,-1);
        (yyval.node)=newNode("RealLit",idaux);
        }
#line 2310 "y.tab.c"
    break;

  case 71: /* Expr: ID  */
#line 706 "gocompiler.y"
        {
        (yyval.node)=newNode("Id",(yyvsp[0].id));}
#line 2317 "y.tab.c"
    break;

  case 72: /* Expr: FuncInvocation  */
#line 709 "gocompiler.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2323 "y.tab.c"
    break;

  case 73: /* Expr: LPAR Expr RPAR  */
#line 711 "gocompiler.y"
                    {(yyval.node)=(yyvsp[-1].node);}
#line 2329 "y.tab.c"
    break;

  case 74: /* Expr: LPAR error RPAR  */
#line 713 "gocompiler.y"
                    {printTree=1;(yyval.node) = NULL; }
#line 2335 "y.tab.c"
    break;


#line 2339 "y.tab.c"

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

#line 716 "gocompiler.y"


int main(int argc, char **argv)
{
    if (argc > 1) {
        
        if (strcmp(argv[1], "-l") == 0) {
            flag = 1;
            yylex();
            return 0;
        }
        if(strcmp(argv[1],"-t") == 0 ){
            flag=2;
            yyparse();
            if(printTree==0){
                printAST(head,0);
            }
          
        }
         if(strcmp(argv[1],"-s") == 0 ){

            flag=2;
            yyparse();
             if(printTree==0){
            makeTables(head,0);
            printf("\n");
            annotateTree(head,0,"");
            printAST(head, 0);
            }
           

         }
        
    }
    else{
             flag=2;
           
             yyparse();
              if(printTree==0){
                makeTables(head,1);
                annotateTree(head,0,"");
                }
             
        }

    //deleteTree(head);
    
    yylex_destroy();
    return 0;
}

void yyerror(char *s) {
    printTree=1;
   
    
    if(errorBrace2==1){
      

        printf ("Line %d, column %d: %s: %s\n", errLine,errColumn, s, yytext);
        errorBrace2=0;
    }
    else{
       
        int trueColumn=column - yyleng;
        printf ("Line %d, column %d: %s: %s\n", line,trueColumn, s, yytext);
        }
        
    

}
