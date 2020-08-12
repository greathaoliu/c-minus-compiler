%{
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
%}

%union{
    class SyntaxTree* syntaxtree;
}

%token <syntaxtree> DEC_OP INC_OP OR_OP AND_OP ELSE IF INT RETURN VOID WHILE DOUBLE TRUE FALSE BREAK CHAR BOOL ID CONST_INT CONST_DOUBLE STRING EQUAL LESS_EQUAL GREATER_EQUAL NOT_EQUAL ADD_OP SUB_OP MUL_OP DIV_OP LESS GREATER MOD_OP SEMICOLON COMMA LEFT_PARE RIGHT_PARE LEFT_BRA RIGHT_BRA LEFT_BRACE RIGHT_BRACE ASSIGN

%type <syntaxtree> program declaration_list declaration var_declaration type_specifier func_definition declarator param_list param compound_stmt block_item_list block_item statement expression_stmt selection_stmt iteration_stmt jump_stmt expression simple_expression relop additive_expression addop term mulop factor arg_list logical_or_expression logical_and_expression equality_expression unaryop postfix_expression primary_expression init_declarator_list init_declarator

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program : declaration_list{
		root = new SyntaxTree(T_PROGRAM,1,$1);
	}
	;
declaration_list : declaration_list declaration{
			$$ = new SyntaxTree(T_DECLARATION_LIST,2,$1,$2);	
		}
		| declaration{
			$$ = new SyntaxTree(T_DECLARATION_LIST,1,$1);
		}
		;
declaration : var_declaration{
			$$ = new SyntaxTree(T_DECLARATION,1,$1);		
		}
		| func_definition{
			$$ = new SyntaxTree(T_DECLARATION,1,$1);
		}
		;
var_declaration : type_specifier SEMICOLON{
			$$ = new SyntaxTree(T_VAR_DECLARATION,2,$1,$2);
		}
		| type_specifier init_declarator_list SEMICOLON{
			$$ = new SyntaxTree(T_VAR_DECLARATION,3,$1,$2,$3);
		}
		;
init_declarator_list : init_declarator {
		$$ = new SyntaxTree(T_INIT_DECLARATOR_LIST,1,$1);
	}
	| init_declarator_list COMMA init_declarator {
		$$ =  new SyntaxTree(T_INIT_DECLARATOR_LIST,3,$1,$2,$3);
	}
	;
init_declarator : declarator {
		$$ = new SyntaxTree(T_INIT_DECLARATOR,1,$1);
	}
	| declarator ASSIGN expression {
		$$ = new SyntaxTree(T_INIT_DECLARATOR,3,$1,$2,$3);
	}
	;
type_specifier : INT{
			$$ = new SyntaxTree(T_TYPE_SPECIFIER,1,$1);
		}
		| VOID{
			$$ = new SyntaxTree(T_TYPE_SPECIFIER,1,$1);
		}
		| DOUBLE{
			$$ = new SyntaxTree(T_TYPE_SPECIFIER,1,$1);
		}
		| CHAR{
			$$ = new SyntaxTree(T_TYPE_SPECIFIER,1,$1);
		}
		| BOOL{
			$$ = new SyntaxTree(T_TYPE_SPECIFIER,1,$1);
		}
		;
func_definition : type_specifier declarator compound_stmt{
			$$ = new SyntaxTree(T_FUNC_DEFINITION,3,$1,$2,$3);
		}
		;
declarator : ID {
			//variable, include function name
			$$ = new SyntaxTree(T_DECLARATOR,1,$1);
		}
		| declarator LEFT_PARE param_list RIGHT_PARE {
			$$ = new SyntaxTree(T_DECLARATOR,4,$1,$2,$3,$4);
		}
		| declarator LEFT_PARE RIGHT_PARE{
			$$ = new SyntaxTree(T_DECLARATOR,3,$1,$2,$3);
		}
		| declarator LEFT_BRA RIGHT_BRA{
			$$ = new SyntaxTree(T_DECLARATOR,3,$1,$2,$3);
		}
		;
param_list : param_list COMMA param{
			$$ = new SyntaxTree(T_PARAM_LIST,3,$1,$2,$3);
		}
		| param{
			$$ = new SyntaxTree(T_PARAM_LIST,1,$1);
		}
		;
param : type_specifier declarator{
		$$ = new SyntaxTree(T_PARAM,2,$1,$2);	
	}
	| type_specifier {
		$$ = new SyntaxTree(T_PARAM,1,$1);	
	}
	;
compound_stmt : LEFT_BRACE block_item_list RIGHT_BRACE{
		$$ = new SyntaxTree(T_COMPOUND_STMT,3,$1,$2,$3);
	}
	| LEFT_BRACE RIGHT_BRACE{
		$$ = new SyntaxTree(T_COMPOUND_STMT,2,$1,$2);
	}
	;
block_item_list : block_item_list block_item {
		$$ = new SyntaxTree(T_BLOCK_ITEM_LIST,2,$1,$2);
	}
	| block_item {
		$$ = new SyntaxTree(T_BLOCK_ITEM_LIST,1,$1);
	}
	;
block_item : var_declaration {
		$$ = new SyntaxTree(T_BLOCK_ITEM,1,$1);
	}
	| statement {
		$$ = new SyntaxTree(T_BLOCK_ITEM,1,$1);
	}
	;
statement : expression_stmt{
		$$ = new SyntaxTree(T_STATEMENT,1,$1);
	}
	| compound_stmt{
		$$ = new SyntaxTree(T_STATEMENT,1,$1);
	}
	| selection_stmt{
		$$ = new SyntaxTree(T_STATEMENT,1,$1);
	}
	| iteration_stmt{
		$$ = new SyntaxTree(T_STATEMENT,1,$1);
	}
	| jump_stmt{
		$$ = new SyntaxTree(T_STATEMENT,1,$1);
	}
	;
expression_stmt : expression SEMICOLON{
			$$ = new SyntaxTree(T_EXPRESSION_STMT,2,$1,$2);
		}
		| SEMICOLON{
			$$ = new SyntaxTree(T_EXPRESSION_STMT,1,$1);
		}
		;
selection_stmt : IF LEFT_PARE expression RIGHT_PARE statement %prec  LOWER_THAN_ELSE{
			$$ = new SyntaxTree(T_SELECTION_STMT,5,$1,$2,$3,$4,$5);
		}
		| IF LEFT_PARE expression RIGHT_PARE statement ELSE statement{
			$$ = new SyntaxTree(T_SELECTION_STMT,7,$1,$2,$3,$4,$5,$6,$7);
		}
		;
iteration_stmt : WHILE LEFT_PARE expression RIGHT_PARE statement{
			$$ = new SyntaxTree(T_ITERATION_STMT,5,$1,$2,$3,$4,$5);
		}
		;
jump_stmt : RETURN expression SEMICOLON{
			$$ = new SyntaxTree(T_JUMP_STMT,3,$1,$2,$3);
		}
		| RETURN SEMICOLON{
			$$ = new SyntaxTree(T_JUMP_STMT,2,$1,$2);
		}
		| BREAK SEMICOLON{
			$$ = new SyntaxTree(T_JUMP_STMT,2,$1,$2);
		}
		;
expression : postfix_expression ASSIGN expression{
			$$ = new SyntaxTree(T_EXPRESSION,3,$1,$2,$3);
		}
		| logical_or_expression{
			$$ = new SyntaxTree(T_EXPRESSION,1,$1);
		}
		;
postfix_expression : primary_expression {
		$$ = new SyntaxTree(T_POSTFIX_EXPRESSION,1,$1);
	}
	| postfix_expression LEFT_PARE RIGHT_PARE{
		$$ = new SyntaxTree(T_POSTFIX_EXPRESSION,3,$1,$2,$3);
	}
	| postfix_expression LEFT_PARE arg_list RIGHT_PARE{
		$$ = new SyntaxTree(T_POSTFIX_EXPRESSION,4,$1,$2,$3,$4);
	}
	;
primary_expression : ID {
		$$ = new SyntaxTree(T_PRIMARY_EXPRESSION,1,$1);
	}
	| TRUE {
		$$ = new SyntaxTree(T_PRIMARY_EXPRESSION,1,$1);
	}
	| FALSE {
		$$ = new SyntaxTree(T_PRIMARY_EXPRESSION,1,$1);
	}
	| CONST_INT {
		$$ = new SyntaxTree(T_PRIMARY_EXPRESSION,1,$1);
	}
	| CONST_DOUBLE {
		$$ = new SyntaxTree(T_PRIMARY_EXPRESSION,1,$1);
	}
	| LEFT_PARE expression RIGHT_PARE {
		$$ = new SyntaxTree(T_PRIMARY_EXPRESSION,3,$1,$2,$3);
	}
	;
logical_or_expression : logical_and_expression {
		$$ = new SyntaxTree(T_LOGICAL_OR_EXPRESSION,1,$1);
	}
	| logical_or_expression OR_OP logical_and_expression {
		$$ = new SyntaxTree(T_LOGICAL_OR_EXPRESSION,3,$1,$2,$3);
	}
	;
logical_and_expression : equality_expression {
		$$ = new SyntaxTree(T_LOGICAL_AND_EXPRESSION,1,$1);
	}
	| logical_and_expression AND_OP equality_expression {
		$$ = new SyntaxTree(T_LOGICAL_AND_EXPRESSION,3,$1,$2,$3);
	}
	;
equality_expression : simple_expression {
		$$ = new SyntaxTree(T_EQUALITY_EXPRESSION,1,$1);
	}
	| equality_expression EQUAL simple_expression {
		$$ = new SyntaxTree(T_EQUALITY_EXPRESSION,3,$1,$2,$3);
	}
	| equality_expression NOT_EQUAL simple_expression {
		$$ = new SyntaxTree(T_EQUALITY_EXPRESSION,3,$1,$2,$3);
	}
	;
simple_expression : simple_expression relop additive_expression{
			$$ = new SyntaxTree(T_SIMPLE_EXPRESSION,3,$1,$2,$3);		
		}
		| additive_expression{
			$$ = new SyntaxTree(T_SIMPLE_EXPRESSION,1,$1);
		}
		;
relop : LESS_EQUAL{
		$$ = new SyntaxTree(T_RELOP,1,$1);
	}
	| LESS {
		$$ = new SyntaxTree(T_RELOP,1,$1);	
	}
	| GREATER{
		$$ = new SyntaxTree(T_RELOP,1,$1);
	}
	| GREATER_EQUAL{
		$$ = new SyntaxTree(T_RELOP,1,$1);
	}
	;
additive_expression : additive_expression addop term{
		$$ = new SyntaxTree(T_ADDITIVE_EXPRESSION,3,$1,$2,$3);
	}
	| term{
		$$ = new SyntaxTree(T_ADDITIVE_EXPRESSION,1,$1);
	}
	;
addop : ADD_OP{
		$$ = new SyntaxTree(T_ADDOP,1,$1);
	}
	| SUB_OP{
		$$ = new SyntaxTree(T_ADDOP,1,$1);
	}
	;
term : term mulop factor{
		$$ = new SyntaxTree(T_TERM,3,$1,$2,$3);
	}
	| factor{
		$$ = new SyntaxTree(T_TERM,1,$1);
	}
	;
mulop : MUL_OP{
		$$ = new SyntaxTree(T_MULOP,1,$1);
	}
	| DIV_OP{
		$$ = new SyntaxTree(T_MULOP,1,$1);
	}
	| MOD_OP{
		$$ = new SyntaxTree(T_MULOP,1,$1);
	}
	;
factor : postfix_expression {
		$$ = new SyntaxTree(T_FACTOR,1,$1);
	}
	| INC_OP {
		$$ = new SyntaxTree(T_FACTOR,1,$1);
	}
	| DEC_OP {
		$$ = new SyntaxTree(T_FACTOR,1,$1);
	}
	| unaryop factor {
		$$ = new SyntaxTree(T_FACTOR,2,$1,$2);
	}
	;
unaryop : ADD_OP {
		$$ = new SyntaxTree(T_UNARYOP,1,$1);
	}
	| SUB_OP {
		$$ = new SyntaxTree(T_UNARYOP,1,$1);
	}
	;
arg_list : arg_list COMMA expression{
		$$ = new SyntaxTree(T_ARG_LIST,3,$1,$2,$3);
	}
	| expression{
		$$ = new SyntaxTree(T_ARG_LIST,1,$1);
	}
	;

%%
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
