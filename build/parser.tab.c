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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '{'  */
  YYSYMBOL_4_ = 4,                         /* '}'  */
  YYSYMBOL_5_ = 5,                         /* '('  */
  YYSYMBOL_6_ = 6,                         /* ')'  */
  YYSYMBOL_7_ = 7,                         /* ';'  */
  YYSYMBOL_8_ = 8,                         /* ':'  */
  YYSYMBOL_9_ = 9,                         /* ','  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_CASE = 11,                      /* CASE  */
  YYSYMBOL_DEFAULT = 12,                   /* DEFAULT  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_INPUT = 15,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 16,                    /* OUTPUT  */
  YYSYMBOL_SWITCH = 17,                    /* SWITCH  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_NUM = 21,                       /* NUM  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_ADDOP = 23,                     /* ADDOP  */
  YYSYMBOL_MULOP = 24,                     /* MULOP  */
  YYSYMBOL_RELOP = 25,                     /* RELOP  */
  YYSYMBOL_CAST = 26,                      /* CAST  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_declarations = 34,              /* declarations  */
  YYSYMBOL_declaration = 35,               /* declaration  */
  YYSYMBOL_type = 36,                      /* type  */
  YYSYMBOL_idlist = 37,                    /* idlist  */
  YYSYMBOL_stmt = 38,                      /* stmt  */
  YYSYMBOL_assignment_stmt = 39,           /* assignment_stmt  */
  YYSYMBOL_input_stmt = 40,                /* input_stmt  */
  YYSYMBOL_output_stmt = 41,               /* output_stmt  */
  YYSYMBOL_if_stmt = 42,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 43,                /* while_stmt  */
  YYSYMBOL_switch_stmt = 44,               /* switch_stmt  */
  YYSYMBOL_caselist = 45,                  /* caselist  */
  YYSYMBOL_break_stmt = 46,                /* break_stmt  */
  YYSYMBOL_stmt_block = 47,                /* stmt_block  */
  YYSYMBOL_stmtlist = 48,                  /* stmtlist  */
  YYSYMBOL_boolexpr = 49,                  /* boolexpr  */
  YYSYMBOL_boolterm = 50,                  /* boolterm  */
  YYSYMBOL_boolfactor = 51,                /* boolfactor  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_factor = 54                     /* factor  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
       5,     6,     2,     2,     9,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     8,     7,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,     4,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    65,    66,    67,    71,    74,    75,    76,
      80,    81,    85,    88,    91,    92,    97,    98,    99,   100,
     101,   102,   103,   104,   107,   109,   113,   114,   118,   121,
     125,   128,   132,   135,   139,   142,   147,   151,   152,   156,
     160,   161,   165,   169,   173,   174,   175,   176,   177,   181,
     182,   183,   184,   185,   189,   190,   191,   192,   193,   194,
     198,   199,   200,   201,   202,   206,   207,   208,   209,   210,
     214,   215,   216,   217,   221,   222
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'{'", "'}'", "'('",
  "')'", "';'", "':'", "','", "BREAK", "CASE", "DEFAULT", "ELSE", "IF",
  "INPUT", "OUTPUT", "SWITCH", "WHILE", "INT", "FLOAT", "NUM", "ID",
  "ADDOP", "MULOP", "RELOP", "CAST", "ASSIGN", "OR", "AND", "NOT", "'='",
  "$accept", "program", "declarations", "declaration", "type", "idlist",
  "stmt", "assignment_stmt", "input_stmt", "output_stmt", "if_stmt",
  "while_stmt", "switch_stmt", "caselist", "break_stmt", "stmt_block",
  "stmtlist", "boolexpr", "boolterm", "boolfactor", "expression", "term",
  "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -79,    21,    16,   -79,    40,   197,   -79,   -79,   107,   -79,
      56,    49,   206,    46,    82,    19,    64,   -79,   -79,    67,
     -79,   -79,    83,    92,   104,   132,   163,   190,   -15,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   112,
     159,   -79,   -79,   -79,   -79,   -79,     6,    42,    77,    84,
      25,    91,   172,   -79,   -79,   154,    99,   -79,   -79,   194,
     198,    -3,   173,   -79,   183,   203,   -79,   211,   212,   139,
       8,   164,   118,   161,     7,    70,     1,   223,   240,   106,
     113,   121,    28,    39,   236,   152,   128,    51,   240,    58,
      65,   135,   143,   150,   224,   226,   256,   260,   249,   276,
     240,   240,   -79,   -79,   216,   257,   203,   -79,   -79,    70,
     259,   241,   173,   252,   -79,   -79,   -79,   245,   255,   168,
       9,   267,   241,   173,   252,   -79,   257,   203,    70,   259,
     -79,   -79,   -79,   -79,   -79,   -79,   193,   193,   -79,   -79,
     240,   -79,   -79,   -79,   -79,   240,   272,   141,   169,   -79,
     -79,   263,   264,   278,   279,   280,   281,   -79,   -79,   -79,
     -79,   222,   231,   240,   240,   -79,   -79
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     4,     0,    13,     3,     0,     2,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
      41,    40,     0,     0,     0,     0,     0,     0,     0,    42,
      16,    17,    18,    19,    20,    21,    22,    23,    14,     0,
       0,    15,    12,     9,     7,    39,     0,     0,     0,     0,
       0,     0,     0,     8,     6,     0,     0,    73,    72,     0,
       0,     0,    45,    50,     0,    61,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,    64,    63,    69,    67,    59,
      57,    48,    46,    53,    51,    74,    70,     0,     0,     0,
       0,     0,    47,    44,    52,    49,    62,    60,    58,    55,
      68,    65,    27,    26,    29,    28,     0,     0,    33,    32,
       0,    75,    71,    56,    54,     0,     0,     0,     0,    31,
      30,     0,     0,     0,     0,     0,     0,    43,    43,    43,
      43,     0,     0,    37,    36,    35,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   277,   -79,   -78,   -79,   -79,   -79,
     -79,   -79,   -79,   153,   -79,   290,   114,   -45,    41,    48,
     -47,   -73,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,    19,     8,    29,    30,    31,    32,
      33,    34,    35,   147,    36,    37,    12,    61,    62,    63,
      64,    65,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     104,    70,    72,    88,    76,    74,   106,    55,   102,    85,
     121,    56,    51,   101,    97,   144,    52,     4,   127,     5,
      41,     3,   138,   139,    91,    89,    73,    57,    58,   111,
      56,    91,    59,    56,   110,    89,    60,    89,     6,   118,
     113,    42,   120,    67,    56,   129,    57,    58,    10,    57,
      58,    59,   119,    20,    59,    60,    56,    16,    60,   122,
      57,    58,   149,    56,    68,    59,   124,   150,    38,    60,
      56,    43,    57,    58,    44,    17,    18,    59,    69,    57,
      58,    60,    56,    39,    59,    71,    57,    58,    60,    56,
      45,    59,    75,    79,    80,    60,    56,    46,    57,    58,
      84,    17,    18,    59,    56,    57,    58,   105,    13,    47,
      59,    56,    57,    58,   107,    14,    15,    59,    56,    53,
      57,    58,   109,   112,    99,    59,    56,    57,    58,   117,
     123,   114,    59,    56,    57,    58,   126,    48,   125,    59,
      56,    91,    57,    58,   128,    96,   108,    59,    56,    57,
      58,   130,   152,   153,    59,    56,    57,    58,   116,   131,
      78,    59,    79,    80,    57,    58,    54,   100,    49,    59,
      98,    57,    58,    77,   143,    91,    59,    79,    80,    81,
     152,   154,    82,    83,    79,    80,    81,    79,    80,    82,
      83,    79,    80,    81,   146,    50,    82,    83,    11,    86,
     -43,   -43,    90,    87,   -38,   -38,    91,   -43,    92,     5,
      21,   -43,   -43,   -43,   -43,   -43,    22,    94,    95,   -43,
      23,    24,    25,    26,    27,     5,   165,    93,    28,   140,
     103,   132,    22,   133,     5,   166,    23,    24,    25,    26,
      27,    22,   115,     5,    28,    23,    24,    25,    26,    27,
      22,   141,   136,    28,    23,    24,    25,    26,    27,    79,
      80,   142,    28,   134,    79,    80,    81,   135,    79,    80,
      83,   161,   162,   163,   164,    79,    80,    81,    91,   137,
     145,    80,    91,   151,   155,   156,   157,   158,   159,   160,
     148,    40,     9
};

static const yytype_uint8 yycheck[] =
{
      78,    48,    49,     6,    51,    50,    79,     1,     7,    56,
      88,     5,    27,     6,     6,     6,    31,     1,    91,     3,
       1,     0,   100,   101,    23,    28,     1,    21,    22,     1,
       5,    23,    26,     5,    81,    28,    30,    28,    22,    86,
       1,    22,    87,     1,     5,    92,    21,    22,     8,    21,
      22,    26,     1,     4,    26,    30,     5,     1,    30,     1,
      21,    22,   140,     5,    22,    26,     1,   145,    22,    30,
       5,     7,    21,    22,     7,    19,    20,    26,     1,    21,
      22,    30,     5,     1,    26,     1,    21,    22,    30,     5,
       7,    26,     1,    23,    24,    30,     5,     5,    21,    22,
       1,    19,    20,    26,     5,    21,    22,     1,     1,     5,
      26,     5,    21,    22,     1,     8,     9,    26,     5,     7,
      21,    22,     1,    82,     6,    26,     5,    21,    22,     1,
      89,    83,    26,     5,    21,    22,     1,     5,    90,    26,
       5,    23,    21,    22,     1,     6,    80,    26,     5,    21,
      22,     1,    11,    12,    26,     5,    21,    22,     6,    93,
       6,    26,    23,    24,    21,    22,     7,     6,     5,    26,
       6,    21,    22,     1,     6,    23,    26,    23,    24,    25,
      11,    12,    28,    29,    23,    24,    25,    23,    24,    28,
      29,    23,    24,    25,     1,     5,    28,    29,     1,     5,
       3,     4,    29,     5,    11,    12,    23,    10,    25,     3,
       4,    14,    15,    16,    17,    18,    10,     6,     6,    22,
      14,    15,    16,    17,    18,     3,     4,    24,    22,    13,
       7,     7,    10,     7,     3,     4,    14,    15,    16,    17,
      18,    10,     6,     3,    22,    14,    15,    16,    17,    18,
      10,     6,     3,    22,    14,    15,    16,    17,    18,    23,
      24,     6,    22,     7,    23,    24,    25,     7,    23,    24,
      29,   157,   158,   159,   160,    23,    24,    25,    23,     3,
      13,    24,    23,    11,    21,    21,     8,     8,     8,     8,
     137,    14,     2
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,     1,     3,    22,    35,    37,    47,
       8,     1,    48,     1,     8,     9,     1,    19,    20,    36,
       4,     4,    10,    14,    15,    16,    17,    18,    22,    38,
      39,    40,    41,    42,    43,    44,    46,    47,    22,     1,
      36,     1,    22,     7,     7,     7,     5,     5,     5,     5,
       5,    27,    31,     7,     7,     1,     5,    21,    22,    26,
      30,    49,    50,    51,    52,    53,    54,     1,    22,     1,
      52,     1,    52,     1,    49,     1,    52,     1,     6,    23,
      24,    25,    28,    29,     1,    52,     5,     5,     6,    28,
      29,    23,    25,    24,     6,     6,     6,     6,     6,     6,
       6,     6,     7,     7,    38,     1,    53,     1,    54,     1,
      52,     1,    50,     1,    51,     6,     6,     1,    52,     1,
      49,    38,     1,    50,     1,    51,     1,    53,     1,    52,
       1,    54,     7,     7,     7,     7,     3,     3,    38,    38,
      13,     6,     6,     6,     6,    13,     1,    45,    45,    38,
      38,    11,    11,    12,    12,    21,    21,     8,     8,     8,
       8,    48,    48,    48,    48,     4,     4
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    34,    35,    35,    35,    35,
      36,    36,    37,    37,    37,    37,    38,    38,    38,    38,
      38,    38,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    45,    46,
      47,    47,    48,    48,    49,    49,    49,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     4,     4,     4,     4,
       1,     1,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     5,     5,     5,
       7,     7,     5,     5,    10,    10,     5,     5,     0,     2,
       3,     3,     2,     0,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     4,     3,     4,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     4,     1,     1,     3,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: declarations stmt_block  */
#line 58 "src/parser.y"
                            {
        //globalScope.printTable();
        root = new ASTProgramRoot((yyvsp[0].node));
    }
#line 1509 "build/parser.tab.c"
    break;

  case 4: /* declarations: declarations error  */
#line 66 "src/parser.y"
                         { yyerrok; yyclearin; }
#line 1515 "build/parser.tab.c"
    break;

  case 6: /* declaration: idlist ':' type ';'  */
#line 71 "src/parser.y"
                        {
        globalScope.finalizeDeclarations((yyvsp[-1].dataType));
    }
#line 1523 "build/parser.tab.c"
    break;

  case 7: /* declaration: error ':' type ';'  */
#line 74 "src/parser.y"
                         { yyerrok; yyclearin; }
#line 1529 "build/parser.tab.c"
    break;

  case 8: /* declaration: idlist ':' error ';'  */
#line 75 "src/parser.y"
                           { yyerrok; yyclearin; }
#line 1535 "build/parser.tab.c"
    break;

  case 9: /* declaration: error ':' error ';'  */
#line 76 "src/parser.y"
                          { yyerrok; yyclearin; }
#line 1541 "build/parser.tab.c"
    break;

  case 10: /* type: INT  */
#line 80 "src/parser.y"
       { (yyval.dataType) = DataType::INT; }
#line 1547 "build/parser.tab.c"
    break;

  case 11: /* type: FLOAT  */
#line 81 "src/parser.y"
            { (yyval.dataType) = DataType::FLOAT; }
#line 1553 "build/parser.tab.c"
    break;

  case 12: /* idlist: idlist ',' ID  */
#line 85 "src/parser.y"
                 {
        globalScope.addDeclaration((yyvsp[0].strval));                // We add the ID to symbol table temp list
    }
#line 1561 "build/parser.tab.c"
    break;

  case 13: /* idlist: ID  */
#line 88 "src/parser.y"
        {
        globalScope.addDeclaration((yyvsp[0].strval));                // We add the ID to symbol table temp list
    }
#line 1569 "build/parser.tab.c"
    break;

  case 14: /* idlist: idlist error ID  */
#line 91 "src/parser.y"
                      { yyerrok; yyclearin; }
#line 1575 "build/parser.tab.c"
    break;

  case 15: /* idlist: idlist ',' error  */
#line 92 "src/parser.y"
                       { yyerrok; yyclearin; }
#line 1581 "build/parser.tab.c"
    break;

  case 24: /* assignment_stmt: ID ASSIGN expression ';'  */
#line 107 "src/parser.y"
                             { 
        (yyval.node) = new ASTAssignNode((yyvsp[-3].strval),(yyvsp[-1].node),line_number);}
#line 1588 "build/parser.tab.c"
    break;

  case 25: /* assignment_stmt: ID '=' error ';'  */
#line 109 "src/parser.y"
                       { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1594 "build/parser.tab.c"
    break;

  case 26: /* input_stmt: INPUT '(' ID ')' ';'  */
#line 113 "src/parser.y"
                         { (yyval.node) = new ASTInputNode((yyvsp[-2].strval),line_number); }
#line 1600 "build/parser.tab.c"
    break;

  case 27: /* input_stmt: INPUT '(' error ')' ';'  */
#line 114 "src/parser.y"
                              { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1606 "build/parser.tab.c"
    break;

  case 28: /* output_stmt: OUTPUT '(' expression ')' ';'  */
#line 118 "src/parser.y"
                                  {
        (yyval.node) = new ASTOutputNode((yyvsp[-2].node),line_number);
    }
#line 1614 "build/parser.tab.c"
    break;

  case 29: /* output_stmt: OUTPUT '(' error ')' ';'  */
#line 121 "src/parser.y"
                               { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1620 "build/parser.tab.c"
    break;

  case 30: /* if_stmt: IF '(' boolexpr ')' stmt ELSE stmt  */
#line 125 "src/parser.y"
                                       {
        (yyval.node) = new ASTIfNode((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node),line_number);
    }
#line 1628 "build/parser.tab.c"
    break;

  case 31: /* if_stmt: IF '(' error ')' stmt ELSE stmt  */
#line 128 "src/parser.y"
                                      { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1634 "build/parser.tab.c"
    break;

  case 32: /* while_stmt: WHILE '(' boolexpr ')' stmt  */
#line 132 "src/parser.y"
                               {
        (yyval.node) = new ASTWhileNode((yyvsp[-2].node),(yyvsp[0].node),line_number);
    }
#line 1642 "build/parser.tab.c"
    break;

  case 33: /* while_stmt: WHILE '(' error ')' stmt  */
#line 135 "src/parser.y"
                               { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1648 "build/parser.tab.c"
    break;

  case 34: /* switch_stmt: SWITCH '(' expression ')' '{' caselist DEFAULT ':' stmtlist '}'  */
#line 139 "src/parser.y"
                                                                   {
        (yyval.node) = new ASTSwitchNode((yyvsp[-7].node),(yyvsp[-4].caseListNode),(yyvsp[-1].stmtListNode),line_number);
    }
#line 1656 "build/parser.tab.c"
    break;

  case 35: /* switch_stmt: SWITCH '(' error ')' '{' caselist DEFAULT ':' stmtlist '}'  */
#line 142 "src/parser.y"
                                                                 { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1662 "build/parser.tab.c"
    break;

  case 36: /* caselist: caselist CASE NUM ':' stmtlist  */
#line 147 "src/parser.y"
                                   { 
        (yyval.caseListNode) = (yyvsp[-4].caseListNode);
        (yyval.caseListNode)->addCase(new ASTLiteralNode((yyvsp[-2].val).val.intval,line_number), (yyvsp[0].stmtListNode));
    }
#line 1671 "build/parser.tab.c"
    break;

  case 37: /* caselist: error CASE NUM ':' stmtlist  */
#line 151 "src/parser.y"
                                  { yyerrok; yyclearin; (yyval.caseListNode) = nullptr; }
#line 1677 "build/parser.tab.c"
    break;

  case 38: /* caselist: %empty  */
#line 152 "src/parser.y"
                    { (yyval.caseListNode) = new ASTCaseListNode(); }
#line 1683 "build/parser.tab.c"
    break;

  case 39: /* break_stmt: BREAK ';'  */
#line 156 "src/parser.y"
               {(yyval.node) = new ASTBreakNode(line_number); }
#line 1689 "build/parser.tab.c"
    break;

  case 40: /* stmt_block: '{' stmtlist '}'  */
#line 160 "src/parser.y"
                      { (yyval.node) = new ASTBlockNode((yyvsp[-1].stmtListNode)); }
#line 1695 "build/parser.tab.c"
    break;

  case 41: /* stmt_block: '{' error '}'  */
#line 161 "src/parser.y"
                    { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1701 "build/parser.tab.c"
    break;

  case 42: /* stmtlist: stmtlist stmt  */
#line 165 "src/parser.y"
                   { 
        (yyval.stmtListNode) = (yyvsp[-1].stmtListNode);
        (yyval.stmtListNode) -> addStatement((yyvsp[0].node));
    }
#line 1710 "build/parser.tab.c"
    break;

  case 43: /* stmtlist: %empty  */
#line 169 "src/parser.y"
                    { (yyval.stmtListNode) = new ASTStatementListNode(); }
#line 1716 "build/parser.tab.c"
    break;

  case 44: /* boolexpr: boolexpr OR boolterm  */
#line 173 "src/parser.y"
                         { (yyval.node) = new ASTBinaryExprNode((yyvsp[-1].op),(yyvsp[-2].node),(yyvsp[0].node),line_number); }
#line 1722 "build/parser.tab.c"
    break;

  case 45: /* boolexpr: boolterm  */
#line 174 "src/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1728 "build/parser.tab.c"
    break;

  case 46: /* boolexpr: error OR boolterm  */
#line 175 "src/parser.y"
                        { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1734 "build/parser.tab.c"
    break;

  case 47: /* boolexpr: boolexpr OR error  */
#line 176 "src/parser.y"
                        { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1740 "build/parser.tab.c"
    break;

  case 48: /* boolexpr: error OR error  */
#line 177 "src/parser.y"
                     { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1746 "build/parser.tab.c"
    break;

  case 49: /* boolterm: boolterm AND boolfactor  */
#line 181 "src/parser.y"
                            { (yyval.node) = new ASTBinaryExprNode((yyvsp[-1].op),(yyvsp[-2].node),(yyvsp[0].node),line_number);}
#line 1752 "build/parser.tab.c"
    break;

  case 50: /* boolterm: boolfactor  */
#line 182 "src/parser.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 1758 "build/parser.tab.c"
    break;

  case 51: /* boolterm: error AND boolfactor  */
#line 183 "src/parser.y"
                           { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1764 "build/parser.tab.c"
    break;

  case 52: /* boolterm: boolterm AND error  */
#line 184 "src/parser.y"
                         { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1770 "build/parser.tab.c"
    break;

  case 53: /* boolterm: error AND error  */
#line 185 "src/parser.y"
                      { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1776 "build/parser.tab.c"
    break;

  case 54: /* boolfactor: NOT '(' boolexpr ')'  */
#line 189 "src/parser.y"
                         { (yyval.node) = new ASTUnaryExprNode((yyvsp[-1].node),line_number); }
#line 1782 "build/parser.tab.c"
    break;

  case 55: /* boolfactor: expression RELOP expression  */
#line 190 "src/parser.y"
                                  { (yyval.node) = new ASTBinaryExprNode((yyvsp[-1].op),(yyvsp[-2].node),(yyvsp[0].node),line_number); }
#line 1788 "build/parser.tab.c"
    break;

  case 56: /* boolfactor: NOT '(' error ')'  */
#line 191 "src/parser.y"
                        { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1794 "build/parser.tab.c"
    break;

  case 57: /* boolfactor: error RELOP expression  */
#line 192 "src/parser.y"
                             { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1800 "build/parser.tab.c"
    break;

  case 58: /* boolfactor: expression RELOP error  */
#line 193 "src/parser.y"
                             { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1806 "build/parser.tab.c"
    break;

  case 59: /* boolfactor: error RELOP error  */
#line 194 "src/parser.y"
                        { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1812 "build/parser.tab.c"
    break;

  case 60: /* expression: expression ADDOP term  */
#line 198 "src/parser.y"
                          { (yyval.node) = new ASTBinaryExprNode((yyvsp[-1].op),(yyvsp[-2].node),(yyvsp[0].node),line_number); }
#line 1818 "build/parser.tab.c"
    break;

  case 61: /* expression: term  */
#line 199 "src/parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1824 "build/parser.tab.c"
    break;

  case 62: /* expression: expression ADDOP error  */
#line 200 "src/parser.y"
                             { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1830 "build/parser.tab.c"
    break;

  case 63: /* expression: error ADDOP term  */
#line 201 "src/parser.y"
                       { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1836 "build/parser.tab.c"
    break;

  case 64: /* expression: error ADDOP error  */
#line 202 "src/parser.y"
                        { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1842 "build/parser.tab.c"
    break;

  case 65: /* term: term MULOP factor  */
#line 206 "src/parser.y"
                      { (yyval.node) = new ASTBinaryExprNode((yyvsp[-1].op),(yyvsp[-2].node),(yyvsp[0].node),line_number);}
#line 1848 "build/parser.tab.c"
    break;

  case 66: /* term: factor  */
#line 207 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1854 "build/parser.tab.c"
    break;

  case 67: /* term: error MULOP factor  */
#line 208 "src/parser.y"
                         { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1860 "build/parser.tab.c"
    break;

  case 68: /* term: term MULOP error  */
#line 209 "src/parser.y"
                       { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1866 "build/parser.tab.c"
    break;

  case 69: /* term: error MULOP error  */
#line 210 "src/parser.y"
                        { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1872 "build/parser.tab.c"
    break;

  case 70: /* factor: '(' expression ')'  */
#line 214 "src/parser.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1878 "build/parser.tab.c"
    break;

  case 71: /* factor: CAST '(' expression ')'  */
#line 215 "src/parser.y"
                              { (yyval.node) = new ASTCastExprNode((yyvsp[-3].op),(yyvsp[-1].node),line_number);}
#line 1884 "build/parser.tab.c"
    break;

  case 72: /* factor: ID  */
#line 216 "src/parser.y"
         { (yyval.node) = new ASTIdentifierNode((yyvsp[0].strval),line_number); }
#line 1890 "build/parser.tab.c"
    break;

  case 73: /* factor: NUM  */
#line 217 "src/parser.y"
          { 
        if ((yyvsp[0].val).numType == NumType::INT) (yyval.node) = new ASTLiteralNode((yyvsp[0].val).val.intval,line_number);
        else (yyval.node) = new ASTLiteralNode((yyvsp[0].val).val.floatval,line_number); 
            }
#line 1899 "build/parser.tab.c"
    break;

  case 74: /* factor: '(' error ')'  */
#line 221 "src/parser.y"
                    { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1905 "build/parser.tab.c"
    break;

  case 75: /* factor: CAST '(' error ')'  */
#line 222 "src/parser.y"
                         { yyerrok; yyclearin; (yyval.node) = nullptr; }
#line 1911 "build/parser.tab.c"
    break;


#line 1915 "build/parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 226 "src/parser.y"


void yyerror(const char* error_msg) {
    errorHandler(ErrorCode::ERR_PARSER,line_number,error_msg);
    if (yychar == YYEOF)  return;
}
