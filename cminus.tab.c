/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cminus.y" /* yacc.c:339  */

#define YYPARSER

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "symtab.h"

#define YYSTYPE NodeInfoOrType
typedef union NodeInfoOrType NodeInfoOrType;
typedef struct Info{
	char * str;
	int line;
	char * scope;
}Info;

union NodeInfoOrType {
	TreeNode * tree;
	ExpType expType;
	TokenType opType;
	Info info;
};
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

char *scope;
static int yylex(void)
{
return getToken(); }

TreeNode * parse(void) {
  st_insert( copyString("input"), 0, copyString("Global"),Fun,Integer);
  st_insert( copyString("output"),0, copyString("Global"),Fun,Void);
  scope = copyString("Global");
  yyparse();
  return savedTree;
}


#line 108 "cminus.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cminus.tab.h".  */
#ifndef YY_YY_CMINUS_TAB_H_INCLUDED
# define YY_YY_CMINUS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    SOM = 260,
    SUB = 261,
    MUL = 262,
    DIV = 263,
    ATT = 264,
    PEV = 265,
    ABP = 266,
    FCP = 267,
    FIM = 268,
    ERR = 269,
    IF = 270,
    ELSE = 271,
    INT = 272,
    RETURN = 273,
    VOID = 274,
    WHILE = 275,
    COM = 276,
    MENIG = 277,
    MAIOR = 278,
    MENOR = 279,
    MAIIG = 280,
    DIF = 281,
    VIRG = 282,
    ABCH = 283,
    FECCH = 284,
    ABCO = 285,
    FCCO = 286,
    IGLIGL = 287,
    ERROR = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMINUS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 193 "cminus.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    52,    66,    70,    72,    76,    90,    89,
     113,   115,   120,   119,   140,   142,   146,   159,   163,   176,
     175,   195,   203,   216,   222,   236,   240,   242,   244,   246,
     248,   253,   255,   259,   265,   274,   282,   287,   295,   294,
     306,   310,   318,   317,   331,   338,   342,   344,   345,   346,
     347,   348,   351,   358,   362,   364,   368,   375,   379,   381,
     385,   387,   389,   391,   399,   398,   414,   416,   420,   433,
     437
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "SOM", "SUB", "MUL", "DIV",
  "ATT", "PEV", "ABP", "FCP", "FIM", "ERR", "IF", "ELSE", "INT", "RETURN",
  "VOID", "WHILE", "COM", "MENIG", "MAIOR", "MENOR", "MAIIG", "DIF",
  "VIRG", "ABCH", "FECCH", "ABCO", "FCCO", "IGLIGL", "ERROR", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao", "@1",
  "tipo_especificador", "fun_declaracao", "@2", "params", "param_lista",
  "param", "@3", "composto_decl", "local_declaracoes", "statement_lista",
  "statement", "expressao_decl", "selecao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "@4", "var", "@5", "simples_expressao",
  "relacional", "soma_expressao", "soma", "termo", "mult", "fator",
  "ativacao", "@6", "args", "arg_lista", "vazio", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -91,   -91,     7,    15,   -91,   -91,     0,   -91,   -91,
     -91,    55,   -91,   -14,    25,    35,    41,    11,    39,    56,
      59,    45,   -91,    63,    46,    47,    15,   -91,    48,   -91,
     -91,   -91,    43,    15,   -91,   -91,   -91,    74,     2,   -91,
      69,    -7,   -91,   -91,    44,    70,    53,    71,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,    73,    75,   -91,     3,    60,
     -91,   -91,    50,    76,    77,    44,   -91,    78,    44,   -91,
      81,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    44,
      44,   -91,   -91,    44,    44,    44,   -91,    79,   -91,    80,
      44,   -91,    64,    60,   -91,    54,   -91,    82,    66,   -91,
      34,    34,   -91,   -91,   -91,    44,    83,   -91,   -91,    34,
     -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     2,     4,     5,     0,     6,     1,
       3,     8,     7,     0,     0,     0,     0,     0,    11,     0,
       0,    14,    17,     0,    18,     0,     0,     9,     0,    70,
      13,    16,     0,    70,    23,    20,    22,     0,     0,    25,
       8,    41,    63,    32,     0,     0,     0,     0,    21,    27,
      24,    26,    28,    29,    30,     0,    61,    40,    45,    53,
      57,    62,     0,     0,     0,     0,    36,     0,     0,    31,
       0,    54,    55,    46,    48,    47,    49,    51,    50,     0,
       0,    58,    59,     0,     0,    70,    60,     0,    37,     0,
       0,    61,    44,    52,    56,     0,    69,     0,    66,    67,
       0,     0,    39,    43,    65,     0,    33,    35,    68,     0,
      34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,    91,    65,   -91,    17,   -91,   -91,   -91,
     -91,    84,   -91,    61,   -91,   -91,   -90,   -91,   -91,   -91,
     -91,   -44,   -91,   -65,   -91,   -91,   -91,    18,   -91,    16,
     -91,    19,   -91,   -91,   -91,   -91,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    13,     7,     8,    14,    20,
      21,    22,    28,    49,    33,    38,    50,    51,    52,    53,
      54,    55,    70,    56,    62,    57,    79,    58,    80,    59,
      83,    60,    61,    63,    97,    98,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    39,    67,    11,   -64,    41,    42,     9,    71,    72,
     106,   107,    43,    44,    91,    91,    15,    45,    91,   110,
      46,    87,    47,   -42,    89,    73,    74,    75,    76,    77,
      29,    48,     1,    19,     2,    78,    16,    41,    42,    17,
      95,    96,    23,    19,    43,    44,   102,    41,    42,    45,
      37,   -15,    46,    99,    47,    44,    41,    42,     1,    24,
      18,   108,    29,    66,    44,    12,   -12,    81,    82,    71,
      72,    25,    26,    27,    35,    29,   -19,    40,    32,    12,
      84,    65,    68,    69,   -38,   103,    30,    85,    88,    86,
      90,   100,   101,   105,   104,    10,    93,    92,    36,   109,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
      31
};

static const yytype_int8 yycheck[] =
{
      44,    33,    46,     3,    11,     3,     4,     0,     5,     6,
     100,   101,    10,    11,    79,    80,    30,    15,    83,   109,
      18,    65,    20,    30,    68,    22,    23,    24,    25,    26,
      28,    29,    17,    16,    19,    32,    11,     3,     4,     4,
      84,    85,    31,    26,    10,    11,    90,     3,     4,    15,
      33,    12,    18,    85,    20,    11,     3,     4,    17,     3,
      19,   105,    28,    10,    11,    10,    11,     7,     8,     5,
       6,    12,    27,    10,    31,    28,    30,     3,    30,    10,
      30,    11,    11,    10,     9,    31,    25,    11,    10,    12,
       9,    12,    12,    27,    12,     4,    80,    79,    33,    16,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    19,    35,    36,    37,    38,    40,    41,     0,
      37,     3,    10,    39,    42,    30,    11,     4,    19,    40,
      43,    44,    45,    31,     3,    12,    27,    10,    46,    28,
      47,    45,    30,    48,    70,    31,    38,    40,    49,    70,
       3,     3,     4,    10,    11,    15,    18,    20,    29,    47,
      50,    51,    52,    53,    54,    55,    57,    59,    61,    63,
      65,    66,    58,    67,    55,    11,    10,    55,    11,    10,
      56,     5,     6,    22,    23,    24,    25,    26,    32,    60,
      62,     7,     8,    64,    30,    11,    12,    55,    10,    55,
       9,    57,    61,    63,    65,    55,    55,    68,    69,    70,
      12,    12,    55,    31,    12,    27,    50,    50,    55,    16,
      50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    38,
      40,    40,    42,    41,    43,    43,    44,    44,    45,    46,
      45,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    54,    54,    56,    55,
      55,    57,    58,    57,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    67,    66,    68,    68,    69,    69,
      70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     7,
       1,     1,     0,     7,     1,     1,     3,     1,     2,     0,
       5,     4,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     0,     4,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     0,     5,     1,     1,     3,     1,
       0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 49 "cminus.y" /* yacc.c:1646  */
    { savedTree = (yyvsp[0]).tree; }
#line 1355 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "cminus.y" /* yacc.c:1646  */
    {
			YYSTYPE t;
			t.tree = (yyvsp[-1]).tree;
			if (t.tree != NULL) {
				while (t.tree->sibling != NULL)  {
					t.tree = t.tree->sibling;
				}
				t.tree->sibling = (yyvsp[0]).tree;
				(yyval).tree = (yyvsp[-1]).tree;
			} else {
				(yyval).tree = (yyvsp[0]).tree;
			}
     	}
#line 1373 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1379 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 71 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1385 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1391 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "cminus.y" /* yacc.c:1646  */
    {//Para decl variavel}
			(yyval).tree=newDeclNode(VarK);
			(yyval).tree->type=(yyvsp[-2]).expType;
			if((yyval).tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, variavel %s\n",(yyval).info.line,tokenString);
			}
			(yyval).tree->attr.name = copyString(tokenString);
			//if(scope==NULL)
				//scope= copyString("Global");
			if(check_not_exist((yyval).tree->attr.name, copyString(scope),Var)==1)
				st_insert( (yyval).tree->attr.name,lineno, copyString(scope), Var, (yyval).tree->type);
		}
#line 1408 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).info.str=copyString(tokenString);
				//if(scope==NULL)
				//   scope= copyString("Global");
			(yyval).info.scope=copyString(scope);(yyval).info.line=lineno;
		}
#line 1419 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "cminus.y" /* yacc.c:1646  */
    {//Decl Array
			(yyval).tree=newDeclNode(VarArrayK);
			(yyval).tree->type=(yyvsp[-6]).expType;
			if((yyval).tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, variavel %s\n",lineno,(yyvsp[-4]).info.str);
			}

			//Checar tabela de simbolos
			(yyval).tree->attr.name = (yyvsp[-4]).info.str;

			if(check_not_exist((yyval).tree->attr.name, (yyvsp[-4]).info.scope,Var)==1)
				st_insert( (yyval).tree->attr.name,(yyvsp[-4]).info.line, (yyvsp[-4]).info.scope, Var, (yyval).tree->type);
			//Valor do numero
		}
#line 1438 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 114 "cminus.y" /* yacc.c:1646  */
    { (yyval).expType=Integer; }
#line 1444 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "cminus.y" /* yacc.c:1646  */
    { (yyval).expType=Void; }
#line 1450 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).info.str =copyString(tokenString);
			if(check_not_exist(  copyString(tokenString),copyString("Global"),Fun)==1)
				st_insert( copyString(tokenString),lineno, copyString("Global"),Fun, (yyvsp[-1]).expType);
			scope = copyString((yyval).info.str);
		}
#line 1461 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newDeclNode(FunK);
			(yyval).tree->type=(yyvsp[-6]).expType;
			(yyval).tree->attr.name =(yyvsp[-4]).info.str;
			//Checar tabela de simbolos
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->child[1]=(yyvsp[0]).tree;

			//$$.tree->attr.name = copyString(tokenString);
			scope = copyString("Global");
		}
#line 1477 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1483 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=NULL; }
#line 1489 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "cminus.y" /* yacc.c:1646  */
    {
			YYSTYPE t;
		   	t.tree = (yyvsp[-2]).tree;
			if (t.tree != NULL) {
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
				t.tree->sibling = (yyvsp[0]).tree;
				(yyval).tree = (yyvsp[-2]).tree;
			} else {
				(yyval).tree = (yyvsp[0]).tree;
			}
		}
#line 1506 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "cminus.y" /* yacc.c:1646  */
    {(yyval).tree=(yyvsp[0]).tree;}
#line 1512 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newDeclNode(ParamK);
			(yyval).tree->type=(yyvsp[-1]).expType;
			(yyval).tree->attr.name = copyString(tokenString);
			if((yyval).tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, parametro %s\n",lineno,(yyval).tree->attr.name);
			}
			if(check_not_exist((yyval).tree->attr.name, copyString(scope), Var)==1)
				st_insert( (yyval).tree->attr.name,lineno, copyString(scope), Var, (yyval).tree->type);
			//Checar tabela simbolo
		}
#line 1528 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 176 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).info.str=copyString(tokenString);
			(yyval).info.scope=copyString(scope);
			(yyval).info.line=lineno;
		}
#line 1538 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 181 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newDeclNode(ParamArrayK);
			(yyval).tree->type=(yyvsp[-4]).expType;
			(yyval).tree->attr.name =(yyvsp[-2]).info.str;
			if((yyval).tree->type==Void){
				printf("Erro semantico: declaracao invalida de variavel (void). Linha %d, parametro %s\n",(yyval).info.line,(yyvsp[-2]).info.str);
			}
			//Checar tabela simbolo
			if(check_not_exist((yyval).tree->attr.name,(yyvsp[-2]).info.scope, Var)==1)
				st_insert( (yyval).tree->attr.name,(yyvsp[-2]).info.line,(yyvsp[-2]).info.scope, Var, (yyval).tree->type);
		}
#line 1554 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 196 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(CompostK);
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->child[1]=(yyvsp[-1]).tree;
		}
#line 1564 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 204 "cminus.y" /* yacc.c:1646  */
    {
			YYSTYPE t;
		 	t.tree = (yyvsp[-1]).tree;
			if (t.tree != NULL){
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
				t.tree->sibling = (yyvsp[0]).tree;
				(yyval).tree = (yyvsp[-1]).tree;
			} else {
				(yyval).tree = (yyvsp[0]).tree;
			}
		}
#line 1581 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 217 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=NULL; }
#line 1587 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 223 "cminus.y" /* yacc.c:1646  */
    {
			YYSTYPE t;
			t.tree = (yyvsp[-1]).tree;
			if (t.tree != NULL){
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
				t.tree->sibling = (yyvsp[0]).tree;
				(yyval).tree = (yyvsp[-1]).tree;
			}
			else {
				(yyval).tree = (yyvsp[0]).tree;
			}
		}
#line 1605 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 237 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=NULL; }
#line 1611 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 241 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1617 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 243 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1623 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 245 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1629 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 247 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1635 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 249 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1641 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 254 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[-1]).tree; }
#line 1647 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 256 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=NULL; }
#line 1653 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 260 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(IfK);
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->child[1]=(yyvsp[0]).tree;
		}
#line 1663 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 266 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(IfElseK);
			(yyval).tree->child[0]=(yyvsp[-4]).tree;
			(yyval).tree->child[1]=(yyvsp[-2]).tree;
			(yyval).tree->child[2]=(yyvsp[0]).tree;
		}
#line 1674 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 275 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(IterK);
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->child[1]=(yyvsp[0]).tree;
		}
#line 1684 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 283 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(RetK);
			(yyval).tree->child[0]=NULL;
		}
#line 1693 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 288 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(RetK);
			(yyval).tree->child[0]=(yyvsp[-1]).tree;
		}
#line 1702 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 295 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).info.str=copyString(tokenString);
			(yyval).info.scope=copyString(scope);
			(yyval).info.line=lineno;
		}
#line 1712 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 300 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(AssignK);
			(yyval).tree->child[0]=(yyvsp[-3]).tree;
			(yyval).tree->attr.name=(yyvsp[-2]).info.str;
			(yyval).tree->child[1]=(yyvsp[0]).tree;
		}
#line 1723 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 307 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1729 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 311 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newExpNode(IdK);
			(yyval).tree->attr.name=copyString(tokenString);
			if(validate_decl( (yyval).tree->attr.name,lineno, copyString(scope), Var, (yyval).tree->type)==1)
				st_insert( (yyval).tree->attr.name,lineno, copyString(scope), Var, (yyval).tree->type);
		}
#line 1740 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 318 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).info.str=copyString(tokenString);
			(yyval).info.scope=copyString(scope);(yyval).info.line=lineno;
		}
#line 1749 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 323 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newExpNode(ArrayK);
			(yyval).tree->attr.name=(yyvsp[-3]).info.str;
			(yyval).tree->child[0]=(yyvsp[-1]).tree;
			st_insert( (yyval).tree->attr.name,(yyvsp[-3]).info.line, (yyvsp[-3]).info.scope, Var, (yyval).tree->type);
		}
#line 1760 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 332 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newExpNode(OpK);
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->attr.op=(yyvsp[-1]).opType;
			(yyval).tree->child[1]=(yyvsp[0]).tree;
		}
#line 1771 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 339 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1777 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 343 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=MENIG; }
#line 1783 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 344 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=MENOR; }
#line 1789 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 345 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=MAIOR; }
#line 1795 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 346 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=MAIIG; }
#line 1801 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 347 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=IGLIGL; }
#line 1807 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 348 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=DIF; }
#line 1813 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 352 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newExpNode(OpK);
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->attr.op=(yyvsp[-1]).opType;
			(yyval).tree->child[1]=(yyvsp[0]).tree;
		}
#line 1824 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 359 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1830 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 363 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=SOM; }
#line 1836 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 365 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=SUB; }
#line 1842 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 369 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newExpNode(OpK);
			(yyval).tree->child[0]=(yyvsp[-2]).tree;
			(yyval).tree->attr.op=(yyvsp[-1]).opType;
			(yyval).tree->child[1]=(yyvsp[0]).tree;
		}
#line 1853 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 376 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1859 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 380 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=MUL; }
#line 1865 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 382 "cminus.y" /* yacc.c:1646  */
    { (yyval).opType=DIV; }
#line 1871 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 386 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[-1]).tree; }
#line 1877 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 388 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1883 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 390 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1889 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 392 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newExpNode(ConstK);
			(yyval).tree->attr.name=copyString(nextToken);
		}
#line 1898 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 399 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).info.str=copyString(tokenString);
			(yyval).info.scope=copyString(scope);
			(yyval).info.line=lineno;
		}
#line 1908 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "cminus.y" /* yacc.c:1646  */
    {
			(yyval).tree=newStmtNode(AtivK);
			(yyval).tree->attr.name=(yyvsp[-3]).info.str;
			(yyval).tree->child[0]=(yyvsp[-1]).tree;
			if(validate_decl((yyval).tree->attr.name,(yyvsp[-3]).info.line, (yyvsp[-3]).info.scope, Fun, (yyval).tree->type)==1)
				st_insert( (yyval).tree->attr.name,(yyvsp[-3]).info.line, (yyvsp[-3]).info.scope, Fun, (yyval).tree->type);
		}
#line 1920 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 415 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1926 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 417 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=NULL; }
#line 1932 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 421 "cminus.y" /* yacc.c:1646  */
    {
			YYSTYPE t;
			t.tree = (yyvsp[-2]).tree;
			if (t.tree != NULL) {
				while (t.tree->sibling != NULL)
					t.tree = t.tree->sibling;
                     t.tree->sibling = (yyvsp[0]).tree;
                     (yyval).tree = (yyvsp[-2]).tree;
			} else {
				(yyval).tree = (yyvsp[0]).tree;
			}
		}
#line 1949 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 434 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=(yyvsp[0]).tree; }
#line 1955 "cminus.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 437 "cminus.y" /* yacc.c:1646  */
    { (yyval).tree=NULL; }
#line 1961 "cminus.tab.c" /* yacc.c:1646  */
    break;


#line 1965 "cminus.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 440 "cminus.y" /* yacc.c:1906  */


int yyerror(char * message)
{ if(yychar!=ERROR){
	  printf("Erro de sintaxe na linha %d. ",lineno);
	  printf("Token nao esperado: ");
	  printToken(yychar,nextToken);}
  Error = 1;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
/*int main()
{
  yyparse();
  return 1;
}*/



