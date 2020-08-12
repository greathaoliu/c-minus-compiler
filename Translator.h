#ifndef MY_COMPLIER_TRANSLATOR_H
#define MY_COMPLIER_TRANSLATOR_H

#include "SyntaxTree.h"
#include "InterRepresent.h"
#include "Scope.h"
#include <unordered_set>

using namespace std;
class Translator {
public:
	Translator(SyntaxTree *st);
	~Translator();

private:
	// 符号表
	map<string, funcNode> funcTable;    //函数定义表
	vector<Scope> scopes;                //维护的栈

	InterRepresent interCode;            //中间代码生成

	SyntaxTree *root;
	unordered_set<string> types_set = { "void", "char", "int", "double", "bool" };

	void translate_SyntaxTree(SyntaxTree *node); // 从语法树的法root开始遍历并生成代码，相当于从Program开始

	void translate_var_declaration(SyntaxTree *node);
	void translate_init_declarator_list(SyntaxTree *node, string type);
	void translate_init_declarator(SyntaxTree *node, string type);

	// 下面的排列是按照优先级
	varNode translate_expression(SyntaxTree *node);
	varNode translate_logical_or_expression(SyntaxTree *node); // ||
	varNode translate_logical_and_expression(SyntaxTree *node); // &&
	varNode translate_equality_expression(SyntaxTree *node); // == !=
	varNode translate_relational_expression(SyntaxTree *node); // > < >= <=
	varNode translate_additive_expression(SyntaxTree *node); // + -
	varNode translate_multiplicative_expression(SyntaxTree *node); // * /
	varNode translate_unary_expression(SyntaxTree *node); // - +
	varNode translate_postfix_expression(SyntaxTree *node); // 包含函数调用
	void translate_arg_list(SyntaxTree *node, string funcName); // 调用函数的参数
	varNode translate_primary_expression(SyntaxTree *node); // ID、字面量、(expression)

	void translate_function_definition(SyntaxTree *node);
	void translate_parameter_list(SyntaxTree *st, string funcName, Types type);
	void translate_parameter_declaration(SyntaxTree *node, string funcName);

	void translate_statement(SyntaxTree *node);
	void translate_compound_stmt(SyntaxTree *node);
	void translate_selection_stmt(SyntaxTree* node);
	void translate_iteration_stmt(SyntaxTree *node); // 只支持while
	void translate_jump_statement(SyntaxTree* node);



	void raise_error(int lineno, string message = "Unknown error!");

	bool checkLocalScope(string varname);
	int getBreakScopeNumber();
	bool checkGlobalScope(string varname);
	varNode getNodeByName(string varname);
	Types getRType();
};


#endif //MY_COMPLIER_TRANSLATOR_H
