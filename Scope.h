#ifndef _BLOCK_H_
#define _BLOCK_H_

#include<iostream>
#include<string>
#include<vector>
#include<map>

#include "SyntaxTree.h"

using namespace std;

enum Types {
	type_VOID, type_CHAR, type_INT, type_DOUBLE, type_BOOL
}; // 返回类型enum

const map<string, Types> TypeMap = { {"void",   type_VOID},
									{"char",   type_CHAR},
									{"int",    type_INT},
									{"double", type_DOUBLE},
									{"bool",   type_BOOL} };

//变量节点
struct varNode {
	string name;
	Types type;
	int num = -1;
	bool useAddress = false;
	string condition;

	varNode() {

	}

	varNode(string name, Types type) {
		this->name = name;
		this->type = type;
	}

	varNode(Types type) {
		this->type = type;
	}

	string getVarName() { // 返回变量在中间代码中的形式
		if (this->useAddress) {
			return "*" + this->name;
		}
		else {
			if (this->num < 0) {
				return this->name;
			}
			else {
				return "var" + to_string(this->num);
			}
		}
	}
};

//函数节点
struct funcNode {
	bool isdefinied = false;
	string name;                //函数名
	Types rtype;                //函数返回类型
	vector<varNode> paralist;    //记录形参列表
	funcNode() {

	}
	funcNode(string fname, Types ftype) {
		name = fname;
		rtype = ftype;
	}
};


struct Scope {
public:
	bool isfunc = false; //记录是否是函数作用域
	funcNode func;    //如果是函数，记录函数名
	map<string, struct varNode> varMap;        //变量的map
	string breakLabelname;
	bool canBreak = false;
	Scope() {

	}
	Scope(string fname, Types ftype) {
		func = funcNode(fname, ftype);
		isfunc = true;
	}
};

#endif // !_BLOCK_H_
