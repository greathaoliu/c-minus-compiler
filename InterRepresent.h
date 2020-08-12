#ifndef MY_COMPLIER_INTERREPRESENT_H
#define MY_COMPLIER_INTERREPRESENT_H

#include <iostream>
#include <string>
#include "SyntaxTree.h"
#include "Scope.h"

using namespace std;

// 中间代码生成和优化
class InterRepresent {
public:
	InterRepresent();

	void outputIR(bool tofile = true, string filename = "intercode.txt");

	void addIR(string IR);
	string newTemp();
	string newLabel();

	string genBinaryOpIR(string temp, string op, varNode var1, varNode var2); // temp = var0 + var1
	string genAssignIR(varNode var1, varNode var2);
	string genParamIR(varNode param); // 函数定义参数 PARAM var0
	string genReturnIR(varNode var); // RETURN var0
	string genArgIR(varNode var); // 传递实参
	string genConditonIR(); // IF GOTO

	void optimize();

	vector<string> codes;
	int tempNo = 0;
	int varNo = 0;
	int labelNo = 0;
	int arrayNo = 0;
};


#endif //MY_COMPLIER_INTERREPRESENT_H
