/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "project.y"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "SyntaxTree.h"
#include "Translator.h"
#include "Scope.h"
#include "InterRepresent.h"

int yylex(void);
int yyparse(void);
int yyerror(const char* str);
SyntaxTree* root;
extern int yylineno;
extern FILE * yyin;

#line 88 "y.tab.c"

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

#line 230 "y.tab.c"

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
  YYSYMBOL_DEC_OP = 3,                     /* DEC_OP  */
  YYSYMBOL_INC_OP = 4,                     /* INC_OP  */
  YYSYMBOL_OR_OP = 5,                      /* OR_OP  */
  YYSYMBOL_AND_OP = 6,                     /* AND_OP  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_DOUBLE = 13,                    /* DOUBLE  */
  YYSYMBOL_TRUE = 14,                      /* TRUE  */
  YYSYMBOL_FALSE = 15,                     /* FALSE  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CHAR = 17,                      /* CHAR  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_CONST_INT = 20,                 /* CONST_INT  */
  YYSYMBOL_CONST_DOUBLE = 21,              /* CONST_DOUBLE  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_EQUAL = 23,                     /* EQUAL  */
  YYSYMBOL_LESS_EQUAL = 24,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 25,             /* GREATER_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 26,                 /* NOT_EQUAL  */
  YYSYMBOL_ADD_OP = 27,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 28,                    /* SUB_OP  */
  YYSYMBOL_MUL_OP = 29,                    /* MUL_OP  */
  YYSYMBOL_DIV_OP = 30,                    /* DIV_OP  */
  YYSYMBOL_LESS = 31,                      /* LESS  */
  YYSYMBOL_GREATER = 32,                   /* GREATER  */
  YYSYMBOL_MOD_OP = 33,                    /* MOD_OP  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_LEFT_PARE = 36,                 /* LEFT_PARE  */
  YYSYMBOL_RIGHT_PARE = 37,                /* RIGHT_PARE  */
  YYSYMBOL_LEFT_BRA = 38,                  /* LEFT_BRA  */
  YYSYMBOL_RIGHT_BRA = 39,                 /* RIGHT_BRA  */
  YYSYMBOL_LEFT_BRACE = 40,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 41,               /* RIGHT_BRACE  */
  YYSYMBOL_ASSIGN = 42,                    /* ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 43,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_declaration_list = 46,          /* declaration_list  */
  YYSYMBOL_declaration = 47,               /* declaration  */
  YYSYMBOL_var_declaration = 48,           /* var_declaration  */
  YYSYMBOL_init_declarator_list = 49,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 50,           /* init_declarator  */
  YYSYMBOL_type_specifier = 51,            /* type_specifier  */
  YYSYMBOL_func_definition = 52,           /* func_definition  */
  YYSYMBOL_declarator = 53,                /* declarator  */
  YYSYMBOL_param_list = 54,                /* param_list  */
  YYSYMBOL_param = 55,                     /* param  */
  YYSYMBOL_compound_stmt = 56,             /* compound_stmt  */
  YYSYMBOL_block_item_list = 57,           /* block_item_list  */
  YYSYMBOL_block_item = 58,                /* block_item  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_expression_stmt = 60,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 61,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 62,            /* iteration_stmt  */
  YYSYMBOL_jump_stmt = 63,                 /* jump_stmt  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_postfix_expression = 65,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 66,        /* primary_expression  */
  YYSYMBOL_logical_or_expression = 67,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 68,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 69,       /* equality_expression  */
  YYSYMBOL_simple_expression = 70,         /* simple_expression  */
  YYSYMBOL_relop = 71,                     /* relop  */
  YYSYMBOL_additive_expression = 72,       /* additive_expression  */
  YYSYMBOL_addop = 73,                     /* addop  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_mulop = 75,                     /* mulop  */
  YYSYMBOL_factor = 76,                    /* factor  */
  YYSYMBOL_unaryop = 77,                   /* unaryop  */
  YYSYMBOL_arg_list = 78                   /* arg_list  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    35,    38,    42,    45,    49,    52,    56,
      59,    63,    66,    70,    73,    76,    79,    82,    86,    90,
      94,    97,   100,   104,   107,   111,   114,   118,   121,   125,
     128,   132,   135,   139,   142,   145,   148,   151,   155,   158,
     162,   165,   169,   173,   176,   179,   183,   186,   190,   193,
     196,   200,   203,   206,   209,   212,   215,   219,   222,   226,
     229,   233,   236,   239,   243,   246,   250,   253,   256,   259,
     263,   266,   270,   273,   277,   280,   284,   287,   290,   294,
     297,   300,   303,   307,   310,   314,   317
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
  "\"end of file\"", "error", "\"invalid token\"", "DEC_OP", "INC_OP",
  "OR_OP", "AND_OP", "ELSE", "IF", "INT", "RETURN", "VOID", "WHILE",
  "DOUBLE", "TRUE", "FALSE", "BREAK", "CHAR", "BOOL", "ID", "CONST_INT",
  "CONST_DOUBLE", "STRING", "EQUAL", "LESS_EQUAL", "GREATER_EQUAL",
  "NOT_EQUAL", "ADD_OP", "SUB_OP", "MUL_OP", "DIV_OP", "LESS", "GREATER",
  "MOD_OP", "SEMICOLON", "COMMA", "LEFT_PARE", "RIGHT_PARE", "LEFT_BRA",
  "RIGHT_BRA", "LEFT_BRACE", "RIGHT_BRACE", "ASSIGN", "LOWER_THAN_ELSE",
  "$accept", "program", "declaration_list", "declaration",
  "var_declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "func_definition", "declarator", "param_list", "param",
  "compound_stmt", "block_item_list", "block_item", "statement",
  "expression_stmt", "selection_stmt", "iteration_stmt", "jump_stmt",
  "expression", "postfix_expression", "primary_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "unaryop", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -68,   -68,   -68,   -68,   -68,    24,    75,   -68,   -68,
     -12,   -68,   -68,   -68,   -68,   -68,    79,   -68,    93,   -68,
       9,   181,    23,    27,   168,   -68,   -68,    49,   -68,     9,
     -31,   -68,   -68,   -68,   -68,    58,   142,    69,   -68,   -68,
      35,   -68,   -68,   -68,   -68,   -68,   -68,   168,   -68,   -68,
     -12,   -68,    62,   -68,   -68,   -68,   -68,   -68,   -68,    73,
      59,   -68,   104,   128,   102,   -15,   -13,    89,   -68,   168,
     -68,   -25,    75,   -68,   168,   -68,   105,   168,   -68,   103,
     -68,   -68,   -68,   123,   168,   168,   168,   168,   168,   -68,
     -68,   -68,   -68,   168,   -68,   -68,   168,   -68,   -68,   -68,
     168,   111,   -68,   -68,   112,   -68,   115,   -68,   -68,   -68,
      14,   -68,   128,   102,   -15,   -15,   -13,    89,   -68,    96,
      96,   168,   -68,   134,   -68,   -68,    96,   -68
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,    14,    15,    16,    17,     0,     2,     4,     5,
       0,     6,     1,     3,    19,     7,     0,     9,    11,     8,
       0,     0,     0,     0,     0,    18,    10,    11,    21,    26,
       0,    24,    22,    81,    80,     0,     0,     0,    52,    53,
       0,    51,    54,    55,    83,    84,    39,     0,    28,    31,
       0,    34,     0,    30,    32,    33,    35,    36,    37,     0,
      79,    48,    47,    57,    59,    61,    65,    71,    75,     0,
      12,    25,     0,    20,     0,    44,     0,     0,    45,     0,
      27,    29,    38,     0,     0,     0,     0,     0,     0,    66,
      69,    67,    68,     0,    72,    73,     0,    76,    77,    78,
       0,    79,    82,    23,     0,    43,     0,    56,    49,    86,
       0,    46,    58,    60,    62,    63,    64,    70,    74,     0,
       0,     0,    50,    40,    42,    85,     0,    41
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   141,   -18,   -68,   133,   -20,   -68,    -2,
     -68,    82,   137,   -68,   106,   -62,   -68,   -68,   -68,   -68,
     -24,   -67,   -68,   -68,    80,    78,    33,   -68,    74,   -68,
      70,   -68,   -44,   -68,   -68
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    16,    17,    10,    11,    27,
      30,    31,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    93,    66,    96,
      67,   100,    68,    69,   110
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      70,    29,   101,    50,    72,    49,    73,    14,    18,    89,
      90,    21,    76,    22,    94,    95,    91,    92,   101,   101,
     101,   101,    15,    79,    12,   102,   101,    71,    14,   101,
      33,    34,    50,   101,    49,    35,     1,    36,     2,    37,
       3,    38,    39,    40,     4,     5,    41,    42,    43,   121,
     104,   122,    29,   106,    44,    45,   118,   123,   124,   109,
     111,    46,    32,    47,   127,    33,    34,    23,    48,    78,
      35,     1,    36,     2,    37,     3,    38,    39,    40,     4,
       5,    41,    42,    43,     1,    21,     2,    22,     3,    44,
      45,    24,     4,     5,    74,    83,    46,   125,    47,    33,
      34,    84,    23,    80,    35,    77,    36,    82,    37,    85,
      38,    39,    40,    19,    20,    41,    42,    43,    97,    98,
     114,   115,    99,    44,    45,    87,    33,    34,    88,    21,
      46,    22,    47,    23,    86,    24,    23,    38,    39,   105,
     107,   126,    41,    42,    43,    33,    34,    83,    13,   119,
      44,    45,   120,    26,   103,    25,    38,    39,    81,    47,
     108,    41,    42,    43,   113,   112,   117,   116,     0,    44,
      45,    33,    34,     0,     0,     0,    75,     0,    47,     0,
       0,     0,    38,    39,     0,     0,     0,    41,    42,    43,
       1,     0,     2,     0,     3,    44,    45,     0,     4,     5,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28
};

static const yytype_int8 yycheck[] =
{
      24,    21,    69,    23,    35,    23,    37,    19,    10,    24,
      25,    36,    36,    38,    27,    28,    31,    32,    85,    86,
      87,    88,    34,    47,     0,    69,    93,    29,    19,    96,
       3,     4,    52,   100,    52,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    35,
      74,    37,    72,    77,    27,    28,   100,   119,   120,    83,
      84,    34,    39,    36,   126,     3,     4,    40,    41,    34,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     9,    36,    11,    38,    13,    27,
      28,    42,    17,    18,    36,    36,    34,   121,    36,     3,
       4,    42,    40,    41,     8,    36,    10,    34,    12,     5,
      14,    15,    16,    34,    35,    19,    20,    21,    29,    30,
      87,    88,    33,    27,    28,    23,     3,     4,    26,    36,
      34,    38,    36,    40,     6,    42,    40,    14,    15,    34,
      37,     7,    19,    20,    21,     3,     4,    36,     7,    37,
      27,    28,    37,    20,    72,    18,    14,    15,    52,    36,
      37,    19,    20,    21,    86,    85,    96,    93,    -1,    27,
      28,     3,     4,    -1,    -1,    -1,    34,    -1,    36,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    19,    20,    21,
       9,    -1,    11,    -1,    13,    27,    28,    -1,    17,    18,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    11,    13,    17,    18,    45,    46,    47,    48,
      51,    52,     0,    47,    19,    34,    49,    50,    53,    34,
      35,    36,    38,    40,    42,    56,    50,    53,    37,    51,
      54,    55,    39,     3,     4,     8,    10,    12,    14,    15,
      16,    19,    20,    21,    27,    28,    34,    36,    41,    48,
      51,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    72,    74,    76,    77,
      64,    53,    35,    37,    36,    34,    64,    36,    34,    64,
      41,    58,    34,    36,    42,     5,     6,    23,    26,    24,
      25,    31,    32,    71,    27,    28,    73,    29,    30,    33,
      75,    65,    76,    55,    64,    34,    64,    37,    37,    64,
      78,    64,    68,    69,    70,    70,    72,    74,    76,    37,
      37,    35,    37,    59,    59,    64,     7,    59
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    52,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    76,    76,    77,    77,    78,    78
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     3,     3,     1,     2,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     3,     2,     2,     3,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2:
#line 31 "project.y"
                          {
		root = new SyntaxTree(T_PROGRAM,1,(yyvsp[0].syntaxtree));
	}
#line 1410 "y.tab.c"
    break;

  case 3:
#line 35 "project.y"
                                               {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATION_LIST,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));	
		}
#line 1418 "y.tab.c"
    break;

  case 4:
#line 38 "project.y"
                             {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATION_LIST,1,(yyvsp[0].syntaxtree));
		}
#line 1426 "y.tab.c"
    break;

  case 5:
#line 42 "project.y"
                             {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATION,1,(yyvsp[0].syntaxtree));		
		}
#line 1434 "y.tab.c"
    break;

  case 6:
#line 45 "project.y"
                                 {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATION,1,(yyvsp[0].syntaxtree));
		}
#line 1442 "y.tab.c"
    break;

  case 7:
#line 49 "project.y"
                                          {
			(yyval.syntaxtree) = new SyntaxTree(T_VAR_DECLARATION,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1450 "y.tab.c"
    break;

  case 8:
#line 52 "project.y"
                                                               {
			(yyval.syntaxtree) = new SyntaxTree(T_VAR_DECLARATION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1458 "y.tab.c"
    break;

  case 9:
#line 56 "project.y"
                                       {
		(yyval.syntaxtree) = new SyntaxTree(T_INIT_DECLARATOR_LIST,1,(yyvsp[0].syntaxtree));
	}
#line 1466 "y.tab.c"
    break;

  case 10:
#line 59 "project.y"
                                                     {
		(yyval.syntaxtree) =  new SyntaxTree(T_INIT_DECLARATOR_LIST,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1474 "y.tab.c"
    break;

  case 11:
#line 63 "project.y"
                             {
		(yyval.syntaxtree) = new SyntaxTree(T_INIT_DECLARATOR,1,(yyvsp[0].syntaxtree));
	}
#line 1482 "y.tab.c"
    break;

  case 12:
#line 66 "project.y"
                                       {
		(yyval.syntaxtree) = new SyntaxTree(T_INIT_DECLARATOR,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1490 "y.tab.c"
    break;

  case 13:
#line 70 "project.y"
                    {
			(yyval.syntaxtree) = new SyntaxTree(T_TYPE_SPECIFIER,1,(yyvsp[0].syntaxtree));
		}
#line 1498 "y.tab.c"
    break;

  case 14:
#line 73 "project.y"
                      {
			(yyval.syntaxtree) = new SyntaxTree(T_TYPE_SPECIFIER,1,(yyvsp[0].syntaxtree));
		}
#line 1506 "y.tab.c"
    break;

  case 15:
#line 76 "project.y"
                        {
			(yyval.syntaxtree) = new SyntaxTree(T_TYPE_SPECIFIER,1,(yyvsp[0].syntaxtree));
		}
#line 1514 "y.tab.c"
    break;

  case 16:
#line 79 "project.y"
                      {
			(yyval.syntaxtree) = new SyntaxTree(T_TYPE_SPECIFIER,1,(yyvsp[0].syntaxtree));
		}
#line 1522 "y.tab.c"
    break;

  case 17:
#line 82 "project.y"
                      {
			(yyval.syntaxtree) = new SyntaxTree(T_TYPE_SPECIFIER,1,(yyvsp[0].syntaxtree));
		}
#line 1530 "y.tab.c"
    break;

  case 18:
#line 86 "project.y"
                                                         {
			(yyval.syntaxtree) = new SyntaxTree(T_FUNC_DEFINITION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1538 "y.tab.c"
    break;

  case 19:
#line 90 "project.y"
                {
			//variable, include function name
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATOR,1,(yyvsp[0].syntaxtree));
		}
#line 1547 "y.tab.c"
    break;

  case 20:
#line 94 "project.y"
                                                             {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATOR,4,(yyvsp[-3].syntaxtree),(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1555 "y.tab.c"
    break;

  case 21:
#line 97 "project.y"
                                                 {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATOR,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1563 "y.tab.c"
    break;

  case 22:
#line 100 "project.y"
                                               {
			(yyval.syntaxtree) = new SyntaxTree(T_DECLARATOR,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1571 "y.tab.c"
    break;

  case 23:
#line 104 "project.y"
                                   {
			(yyval.syntaxtree) = new SyntaxTree(T_PARAM_LIST,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1579 "y.tab.c"
    break;

  case 24:
#line 107 "project.y"
                       {
			(yyval.syntaxtree) = new SyntaxTree(T_PARAM_LIST,1,(yyvsp[0].syntaxtree));
		}
#line 1587 "y.tab.c"
    break;

  case 25:
#line 111 "project.y"
                                 {
		(yyval.syntaxtree) = new SyntaxTree(T_PARAM,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));	
	}
#line 1595 "y.tab.c"
    break;

  case 26:
#line 114 "project.y"
                         {
		(yyval.syntaxtree) = new SyntaxTree(T_PARAM,1,(yyvsp[0].syntaxtree));	
	}
#line 1603 "y.tab.c"
    break;

  case 27:
#line 118 "project.y"
                                                      {
		(yyval.syntaxtree) = new SyntaxTree(T_COMPOUND_STMT,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1611 "y.tab.c"
    break;

  case 28:
#line 121 "project.y"
                                {
		(yyval.syntaxtree) = new SyntaxTree(T_COMPOUND_STMT,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1619 "y.tab.c"
    break;

  case 29:
#line 125 "project.y"
                                             {
		(yyval.syntaxtree) = new SyntaxTree(T_BLOCK_ITEM_LIST,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1627 "y.tab.c"
    break;

  case 30:
#line 128 "project.y"
                     {
		(yyval.syntaxtree) = new SyntaxTree(T_BLOCK_ITEM_LIST,1,(yyvsp[0].syntaxtree));
	}
#line 1635 "y.tab.c"
    break;

  case 31:
#line 132 "project.y"
                             {
		(yyval.syntaxtree) = new SyntaxTree(T_BLOCK_ITEM,1,(yyvsp[0].syntaxtree));
	}
#line 1643 "y.tab.c"
    break;

  case 32:
#line 135 "project.y"
                    {
		(yyval.syntaxtree) = new SyntaxTree(T_BLOCK_ITEM,1,(yyvsp[0].syntaxtree));
	}
#line 1651 "y.tab.c"
    break;

  case 33:
#line 139 "project.y"
                           {
		(yyval.syntaxtree) = new SyntaxTree(T_STATEMENT,1,(yyvsp[0].syntaxtree));
	}
#line 1659 "y.tab.c"
    break;

  case 34:
#line 142 "project.y"
                       {
		(yyval.syntaxtree) = new SyntaxTree(T_STATEMENT,1,(yyvsp[0].syntaxtree));
	}
#line 1667 "y.tab.c"
    break;

  case 35:
#line 145 "project.y"
                        {
		(yyval.syntaxtree) = new SyntaxTree(T_STATEMENT,1,(yyvsp[0].syntaxtree));
	}
#line 1675 "y.tab.c"
    break;

  case 36:
#line 148 "project.y"
                        {
		(yyval.syntaxtree) = new SyntaxTree(T_STATEMENT,1,(yyvsp[0].syntaxtree));
	}
#line 1683 "y.tab.c"
    break;

  case 37:
#line 151 "project.y"
                   {
		(yyval.syntaxtree) = new SyntaxTree(T_STATEMENT,1,(yyvsp[0].syntaxtree));
	}
#line 1691 "y.tab.c"
    break;

  case 38:
#line 155 "project.y"
                                      {
			(yyval.syntaxtree) = new SyntaxTree(T_EXPRESSION_STMT,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1699 "y.tab.c"
    break;

  case 39:
#line 158 "project.y"
                           {
			(yyval.syntaxtree) = new SyntaxTree(T_EXPRESSION_STMT,1,(yyvsp[0].syntaxtree));
		}
#line 1707 "y.tab.c"
    break;

  case 40:
#line 162 "project.y"
                                                                                    {
			(yyval.syntaxtree) = new SyntaxTree(T_SELECTION_STMT,5,(yyvsp[-4].syntaxtree),(yyvsp[-3].syntaxtree),(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1715 "y.tab.c"
    break;

  case 41:
#line 165 "project.y"
                                                                             {
			(yyval.syntaxtree) = new SyntaxTree(T_SELECTION_STMT,7,(yyvsp[-6].syntaxtree),(yyvsp[-5].syntaxtree),(yyvsp[-4].syntaxtree),(yyvsp[-3].syntaxtree),(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1723 "y.tab.c"
    break;

  case 42:
#line 169 "project.y"
                                                                {
			(yyval.syntaxtree) = new SyntaxTree(T_ITERATION_STMT,5,(yyvsp[-4].syntaxtree),(yyvsp[-3].syntaxtree),(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1731 "y.tab.c"
    break;

  case 43:
#line 173 "project.y"
                                       {
			(yyval.syntaxtree) = new SyntaxTree(T_JUMP_STMT,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1739 "y.tab.c"
    break;

  case 44:
#line 176 "project.y"
                                  {
			(yyval.syntaxtree) = new SyntaxTree(T_JUMP_STMT,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1747 "y.tab.c"
    break;

  case 45:
#line 179 "project.y"
                                 {
			(yyval.syntaxtree) = new SyntaxTree(T_JUMP_STMT,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1755 "y.tab.c"
    break;

  case 46:
#line 183 "project.y"
                                                 {
			(yyval.syntaxtree) = new SyntaxTree(T_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
		}
#line 1763 "y.tab.c"
    break;

  case 47:
#line 186 "project.y"
                                       {
			(yyval.syntaxtree) = new SyntaxTree(T_EXPRESSION,1,(yyvsp[0].syntaxtree));
		}
#line 1771 "y.tab.c"
    break;

  case 48:
#line 190 "project.y"
                                        {
		(yyval.syntaxtree) = new SyntaxTree(T_POSTFIX_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1779 "y.tab.c"
    break;

  case 49:
#line 193 "project.y"
                                                 {
		(yyval.syntaxtree) = new SyntaxTree(T_POSTFIX_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1787 "y.tab.c"
    break;

  case 50:
#line 196 "project.y"
                                                          {
		(yyval.syntaxtree) = new SyntaxTree(T_POSTFIX_EXPRESSION,4,(yyvsp[-3].syntaxtree),(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1795 "y.tab.c"
    break;

  case 51:
#line 200 "project.y"
                        {
		(yyval.syntaxtree) = new SyntaxTree(T_PRIMARY_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1803 "y.tab.c"
    break;

  case 52:
#line 203 "project.y"
               {
		(yyval.syntaxtree) = new SyntaxTree(T_PRIMARY_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1811 "y.tab.c"
    break;

  case 53:
#line 206 "project.y"
                {
		(yyval.syntaxtree) = new SyntaxTree(T_PRIMARY_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1819 "y.tab.c"
    break;

  case 54:
#line 209 "project.y"
                    {
		(yyval.syntaxtree) = new SyntaxTree(T_PRIMARY_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1827 "y.tab.c"
    break;

  case 55:
#line 212 "project.y"
                       {
		(yyval.syntaxtree) = new SyntaxTree(T_PRIMARY_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1835 "y.tab.c"
    break;

  case 56:
#line 215 "project.y"
                                          {
		(yyval.syntaxtree) = new SyntaxTree(T_PRIMARY_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1843 "y.tab.c"
    break;

  case 57:
#line 219 "project.y"
                                               {
		(yyval.syntaxtree) = new SyntaxTree(T_LOGICAL_OR_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1851 "y.tab.c"
    break;

  case 58:
#line 222 "project.y"
                                                             {
		(yyval.syntaxtree) = new SyntaxTree(T_LOGICAL_OR_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1859 "y.tab.c"
    break;

  case 59:
#line 226 "project.y"
                                             {
		(yyval.syntaxtree) = new SyntaxTree(T_LOGICAL_AND_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1867 "y.tab.c"
    break;

  case 60:
#line 229 "project.y"
                                                            {
		(yyval.syntaxtree) = new SyntaxTree(T_LOGICAL_AND_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1875 "y.tab.c"
    break;

  case 61:
#line 233 "project.y"
                                        {
		(yyval.syntaxtree) = new SyntaxTree(T_EQUALITY_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1883 "y.tab.c"
    break;

  case 62:
#line 236 "project.y"
                                                      {
		(yyval.syntaxtree) = new SyntaxTree(T_EQUALITY_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1891 "y.tab.c"
    break;

  case 63:
#line 239 "project.y"
                                                          {
		(yyval.syntaxtree) = new SyntaxTree(T_EQUALITY_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1899 "y.tab.c"
    break;

  case 64:
#line 243 "project.y"
                                                               {
			(yyval.syntaxtree) = new SyntaxTree(T_SIMPLE_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));		
		}
#line 1907 "y.tab.c"
    break;

  case 65:
#line 246 "project.y"
                                     {
			(yyval.syntaxtree) = new SyntaxTree(T_SIMPLE_EXPRESSION,1,(yyvsp[0].syntaxtree));
		}
#line 1915 "y.tab.c"
    break;

  case 66:
#line 250 "project.y"
                  {
		(yyval.syntaxtree) = new SyntaxTree(T_RELOP,1,(yyvsp[0].syntaxtree));
	}
#line 1923 "y.tab.c"
    break;

  case 67:
#line 253 "project.y"
               {
		(yyval.syntaxtree) = new SyntaxTree(T_RELOP,1,(yyvsp[0].syntaxtree));	
	}
#line 1931 "y.tab.c"
    break;

  case 68:
#line 256 "project.y"
                 {
		(yyval.syntaxtree) = new SyntaxTree(T_RELOP,1,(yyvsp[0].syntaxtree));
	}
#line 1939 "y.tab.c"
    break;

  case 69:
#line 259 "project.y"
                       {
		(yyval.syntaxtree) = new SyntaxTree(T_RELOP,1,(yyvsp[0].syntaxtree));
	}
#line 1947 "y.tab.c"
    break;

  case 70:
#line 263 "project.y"
                                                    {
		(yyval.syntaxtree) = new SyntaxTree(T_ADDITIVE_EXPRESSION,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1955 "y.tab.c"
    break;

  case 71:
#line 266 "project.y"
              {
		(yyval.syntaxtree) = new SyntaxTree(T_ADDITIVE_EXPRESSION,1,(yyvsp[0].syntaxtree));
	}
#line 1963 "y.tab.c"
    break;

  case 72:
#line 270 "project.y"
              {
		(yyval.syntaxtree) = new SyntaxTree(T_ADDOP,1,(yyvsp[0].syntaxtree));
	}
#line 1971 "y.tab.c"
    break;

  case 73:
#line 273 "project.y"
                {
		(yyval.syntaxtree) = new SyntaxTree(T_ADDOP,1,(yyvsp[0].syntaxtree));
	}
#line 1979 "y.tab.c"
    break;

  case 74:
#line 277 "project.y"
                        {
		(yyval.syntaxtree) = new SyntaxTree(T_TERM,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 1987 "y.tab.c"
    break;

  case 75:
#line 280 "project.y"
                {
		(yyval.syntaxtree) = new SyntaxTree(T_TERM,1,(yyvsp[0].syntaxtree));
	}
#line 1995 "y.tab.c"
    break;

  case 76:
#line 284 "project.y"
              {
		(yyval.syntaxtree) = new SyntaxTree(T_MULOP,1,(yyvsp[0].syntaxtree));
	}
#line 2003 "y.tab.c"
    break;

  case 77:
#line 287 "project.y"
                {
		(yyval.syntaxtree) = new SyntaxTree(T_MULOP,1,(yyvsp[0].syntaxtree));
	}
#line 2011 "y.tab.c"
    break;

  case 78:
#line 290 "project.y"
                {
		(yyval.syntaxtree) = new SyntaxTree(T_MULOP,1,(yyvsp[0].syntaxtree));
	}
#line 2019 "y.tab.c"
    break;

  case 79:
#line 294 "project.y"
                            {
		(yyval.syntaxtree) = new SyntaxTree(T_FACTOR,1,(yyvsp[0].syntaxtree));
	}
#line 2027 "y.tab.c"
    break;

  case 80:
#line 297 "project.y"
                 {
		(yyval.syntaxtree) = new SyntaxTree(T_FACTOR,1,(yyvsp[0].syntaxtree));
	}
#line 2035 "y.tab.c"
    break;

  case 81:
#line 300 "project.y"
                 {
		(yyval.syntaxtree) = new SyntaxTree(T_FACTOR,1,(yyvsp[0].syntaxtree));
	}
#line 2043 "y.tab.c"
    break;

  case 82:
#line 303 "project.y"
                         {
		(yyval.syntaxtree) = new SyntaxTree(T_FACTOR,2,(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 2051 "y.tab.c"
    break;

  case 83:
#line 307 "project.y"
                 {
		(yyval.syntaxtree) = new SyntaxTree(T_UNARYOP,1,(yyvsp[0].syntaxtree));
	}
#line 2059 "y.tab.c"
    break;

  case 84:
#line 310 "project.y"
                 {
		(yyval.syntaxtree) = new SyntaxTree(T_UNARYOP,1,(yyvsp[0].syntaxtree));
	}
#line 2067 "y.tab.c"
    break;

  case 85:
#line 314 "project.y"
                                    {
		(yyval.syntaxtree) = new SyntaxTree(T_ARG_LIST,3,(yyvsp[-2].syntaxtree),(yyvsp[-1].syntaxtree),(yyvsp[0].syntaxtree));
	}
#line 2075 "y.tab.c"
    break;

  case 86:
#line 317 "project.y"
                    {
		(yyval.syntaxtree) = new SyntaxTree(T_ARG_LIST,1,(yyvsp[0].syntaxtree));
	}
#line 2083 "y.tab.c"
    break;


#line 2087 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 322 "project.y"

int main(int argc,char** argv)
{
    FILE* file;
	file=fopen(argv[1],"r");
	yyin=file;
	yyparse();
	root->eval(0);
	Translator translator(root);
    return 0;
}
int yyerror(const char* str)
{
    fprintf(stderr,"%s",str);
    return 0;
}
