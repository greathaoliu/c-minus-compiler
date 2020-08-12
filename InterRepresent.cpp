//
// Created by Hao Liu on 2020/5/23. 
//

#include "InterRepresent.h"
#include <fstream>


//using namespace std;

InterRepresent::InterRepresent() {

}

void InterRepresent::outputIR(bool tofile, string filename) {
    if (tofile) {
        optimize();
        ofstream out(filename);
        // 输出结果到文件
        for (string str:codes) {
            out << str << endl;
        }
    } else {
        for (string str:codes) {
            cout << str << endl;
        }
    }
}

string InterRepresent::newTemp() {
    return "temp" + to_string(tempNo++);
}

void InterRepresent::addIR(string IR) {
    cout<<IR<<endl;
    codes.push_back(IR);
}

string InterRepresent::genBinaryOpIR(string temp, string op, varNode var1, varNode var2) {
    string code = temp +  " = ";
    code = code + var1.getVarName() + " " + op + " " + var2.getVarName();
    return code;
}

string InterRepresent::genAssignIR(varNode var1, varNode var2) {
    string code = var1.getVarName() + " = " + var2.getVarName();
    return code;
}

string InterRepresent::genParamIR(varNode param) {
    string code = "PARAM " + param.getVarName();
    return code;
}

string InterRepresent::genReturnIR(varNode var) {
    string code = "RETURN " + var.getVarName();
    return code;
}

string InterRepresent::genArgIR(varNode var) {
    string code = "ARG " + var.getVarName();
    return code;
}

string InterRepresent::newLabel() {
    return "label" + to_string(labelNo++);
}

void InterRepresent::optimize() {

}