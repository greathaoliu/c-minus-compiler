#ifndef _TREE_H_

#define _TREE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstdarg>
#include <cmath>

using namespace std;

enum Name {
	T_CONST_INT,
	T_CONST_DOUBLE,
	T_STRING,
	T_TRUE,
	T_FALSE,
	T_BREAK,
	T_ID,
	T_ELSE,
	T_IF,
	T_INT,
	T_RETURN,
	T_VOID,
	T_CHAR,
	T_BOOL,
	T_WHILE,
	T_DOUBLE,
	T_EQUAL,				//==
	T_LESS_EQUAL,
	T_GREATER_EQUAL,
	T_NOT_EQUAL,
	T_ADD_OP,
	T_SUB_OP,
	T_MUL_OP,
	T_DIV_OP,
	T_AND_OP,
	T_OR_OP,
	T_ASSIGN,				//=
	T_LESS,
	T_GREATER,
	T_MOD_OP,				//*
	T_SEMICOLON,			//;
	T_COMMA,				//,
	T_LEFT_PARE,			//(
	T_RIGHT_PARE,			//)
	T_LEFT_BRA,				//[
	T_RIGHT_BRA,			//]
	T_LEFT_BRACE,			//{
	T_RIGHT_BRACE,			//}
	T_PROGRAM,
	T_DECLARATION_LIST,
	T_DECLARATION,
	T_VAR_DECLARATION,
	T_TYPE_SPECIFIER,
	T_FUNC_DEFINITION,
	T_PARAM_LIST,
	T_PARAM,
	T_COMPOUND_STMT,
	T_BLOCK_ITEM_LIST,
	T_BLOCK_ITEM,
	T_STATEMENT,
	T_EXPRESSION_STMT,
	T_SELECTION_STMT,
	T_ITERATION_STMT,
	T_JUMP_STMT,
	T_EXPRESSION,
	T_SIMPLE_EXPRESSION,
	T_RELOP,
	T_ADDITIVE_EXPRESSION,
	T_ADDOP,
	T_TERM,
	T_MULOP,
	T_FACTOR,
	T_ARG_LIST,
	T_DECLARATOR,//////////////////////
	T_DEC_OP,
	T_INC_OP,
	T_EQUALITY_EXPRESSION,
	T_INIT_DECLARATOR_LIST,
	T_INIT_DECLARATOR,
	T_LOGICAL_AND_EXPRESSION,
	T_LOGICAL_OR_EXPRESSION,
	T_POSTFIX_EXPRESSION,
	T_PRIMARY_EXPRESSION,
	T_UNARYOP
};

extern char *yytext;

class SyntaxTree {
public:
	SyntaxTree(Name name, int num, ...);
	SyntaxTree(Name name, char zero, int Line);
	~SyntaxTree();

	int GetLine() { return Line; }
	string GetValue() { return Value; }
	Name GetName() { return name; }
	SyntaxTree* GetSon() { return LeftChild; }
	SyntaxTree* GetSibling() { return RightChild; }

	void SetLine(int Line) { this->Line = Line; }
	void SetValue(string Value) { this->Value = Value; }
	void SetSon(SyntaxTree* Child) { this->LeftChild = Child; }
	void SetSibling(SyntaxTree* Child) { this->RightChild = Child; }
	void SetName(Name name) { this->name = name; }
	void eval(int leavel);

private:
	string Value;
	Name name;
	SyntaxTree *LeftChild, *RightChild;
	int Line;//for error info
};

#endif