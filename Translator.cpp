#include "Translator.h"
#include <string>
#include <iostream>
#include <assert.h>
#include "SyntaxTree.h"
#include "InterRepresent.h"

//using namespace std;

// 初始化自带函数read和write
Translator::Translator(SyntaxTree *stRoot) {
    this->root = stRoot;
    Scope block;
    scopes.push_back(block);

    funcNode fWrite;
    funcNode fRead;
    fWrite.rtype = type_VOID;
    fRead.rtype = type_INT; // read()只支持读1个int
    fWrite.name = "write";
    fRead.name = "read";
    fWrite.paralist.emplace_back(type_INT);
    funcTable.emplace("write", fWrite);
    funcTable.emplace("read", fRead);

    translate_SyntaxTree(root); // 从语法树根结点开始生成IR
}

Translator::~Translator() {
    interCode.outputIR();
    interCode.outputIR(false);
}

// 报错函数，显示出错的行号和错误message
void Translator::raise_error(int lineno, string message) {
    interCode.outputIR(false);
    cout << "Error in line " << lineno << ": " << message;
}

// 在local作用域查找变量名是否已定义 未定义true
bool Translator::checkLocalScope(string varname) {
    return scopes.back().varMap.find(varname) != scopes.back().varMap.end();
}

varNode Translator::getNodeByName(string varname) {
    int n = scopes.size();
    for (int i = n - 1; i >= 0; i--) {
        if (scopes[i].varMap.find(varname) != scopes[i].varMap.end()) {
            return scopes[i].varMap.at(varname);
        }
    }
    varNode var;
    var.num = -1;
    return var;
}

int Translator::getBreakScopeNumber() {
    int n = scopes.size();
    for (int i = n - 1; i >= 0; i--) {
        if (scopes[i].canBreak) {
            return i;
        }
    }
    return -1;
}

Types Translator::getRType() {
    int n = scopes.size();
    for (int i = n - 1; i >= 0; i--) {
        if (scopes[i].isfunc) {
            return scopes[i].func.rtype;
        }
    }
    return type_VOID;
}

//program -> declaration_list
//declaration_list -> declaration_list declaration
//declaration -> var_declaration | func_declaration
void Translator::translate_SyntaxTree(SyntaxTree *node) {
    if (node == nullptr) return;

    if (node->GetName() == T_VAR_DECLARATION) { // 变量声明
        translate_var_declaration(node);
        node = node->GetSibling();
    } else if (node->GetName() == T_FUNC_DEFINITION) { // 函数定义
        translate_function_definition(node);
        node = node->GetSibling();
    } else if (node->GetName() == T_STATEMENT) { // 套娃
        translate_statement(node);
        node = node->GetSibling();
    }
    if (node) {
        translate_SyntaxTree(node->GetSon());
        translate_SyntaxTree(node->GetSibling());
    }
}

// var_declaration -> type_specifier; | type_specifier init_declarator
void Translator::translate_var_declaration(SyntaxTree *node) {
    auto type_specifier = node->GetSon();
    // int;也是合法语法
    if (type_specifier->GetSibling()->GetName() == T_SEMICOLON) {
        return; // 继续分析下一个node
    }

    string type = type_specifier->GetSon()->GetValue(); // "int" "char"
    if (types_set.count(type) == 0 || type == "void") {
        raise_error(type_specifier->GetSon()->GetLine(), "Wrong type specifier!"); //报错
    }
    auto init_declarator_list = type_specifier->GetSibling();
    translate_init_declarator_list(init_declarator_list, type);
}

// init_declarator_list -> init_declarator | init_declarator_list , init_declarator
void Translator::translate_init_declarator_list(SyntaxTree *node, string type) {
    if (node->GetSon()->GetName() == T_INIT_DECLARATOR_LIST) { // 套娃，一个list中可能有很多init_declarator
        translate_init_declarator_list(node->GetSon(), type);
    } else if (node->GetSon()->GetName() == T_INIT_DECLARATOR) {
        translate_init_declarator(node->GetSon(), type);
    }

    if (node->GetSibling() && node->GetSibling()->GetName() == T_COMMA) {
        translate_init_declarator(node->GetSibling()->GetSibling(), type); // , 后面的init_declarator
    }
}

// 变量定义，不支持函数声明
// init_declarator -> declarator | declarator = expression
// declarator -> IDENTIFIER
void Translator::translate_init_declarator(SyntaxTree *node, string type) {
    auto declarator = node->GetSon();
    if (declarator->GetSon()->GetName() == T_ID) {
        auto IDENTIFIER = declarator->GetSon();
        string varname = IDENTIFIER->GetValue();
        if (checkLocalScope(varname)) {
            raise_error(declarator->GetSon()->GetLine(), "redefinition of variable " + varname);
        }
        varNode var(varname, TypeMap.at(type));
        var.num = interCode.varNo++;
        scopes.back().varMap.emplace(varname, var); // 新变量加入local scope

        if (declarator->GetSibling() != nullptr && declarator->GetSibling()->GetName() == T_ASSIGN) { // 初始化赋值
            auto expression = declarator->GetSibling()->GetSibling();
            varNode var2 = translate_expression(expression);
            interCode.addIR(interCode.genAssignIR(var, var2));
        }
    }
}

// 赋值语句
// expression -> logical_or_expression | postfix_expression = expression
varNode Translator::translate_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_LOGICAL_OR_EXPRESSION) {
        return translate_logical_or_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_POSTFIX_EXPRESSION) {
        auto postfix_expression = node->GetSon();
        varNode var1 = translate_postfix_expression(postfix_expression);
        string op = postfix_expression->GetSibling()->GetValue();
        if (op != "=") {
            raise_error(postfix_expression->GetLine(), "Only support use = to assign! " + op + " used.");
        }
        varNode var2 = translate_expression(postfix_expression->GetSibling()->GetSibling());
        interCode.addIR(interCode.genAssignIR(var1, var2));
        return var1;
    }
}

// logical_or_expression -> logical_and_expression | logical_or_expression OR_OP logical_and_expression
varNode Translator::translate_logical_or_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_LOGICAL_AND_EXPRESSION) {
        return translate_logical_and_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_LOGICAL_OR_EXPRESSION) {
        auto logical_or_expression = node->GetSon();
        auto logical_and_expression = logical_or_expression->GetSibling()->GetSibling();
        varNode var1 = translate_logical_or_expression(logical_or_expression);
        varNode var2 = translate_logical_and_expression(logical_and_expression);
        assert(var1.type == var2.type && var1.type == type_BOOL);

        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, type_BOOL);
        tNode.condition = var1.getVarName() + "||" + var2.getVarName();
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(interCode.genBinaryOpIR(tName, "||", var1, var2));

        return tNode;
    }
};

// logical_and_expression -> equality_expression | logical_and_expression AND_OP equality_expression
varNode Translator::translate_logical_and_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_EQUALITY_EXPRESSION) {
        return translate_equality_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_LOGICAL_AND_EXPRESSION) {
        auto logical_and_expression = node->GetSon();
        auto equality_expression = logical_and_expression->GetSibling()->GetSibling();
        varNode var1 = translate_logical_and_expression(logical_and_expression);
        varNode var2 = translate_equality_expression(equality_expression);
		assert(var1.type == var2.type && var1.type == type_BOOL);
		
        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, type_BOOL);
        tNode.condition = var1.getVarName() + "&&" + var2.getVarName();
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(interCode.genBinaryOpIR(tName, "&&", var1, var2));
        return tNode;
    }
}

// equality_expression -> simple_expression | equality_expression EQ_OP simple_expression
// | equality_expression NE_OP simple_expression
varNode Translator::translate_equality_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_SIMPLE_EXPRESSION) {//simple_expression is relational_expression
        return translate_relational_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_EQUALITY_EXPRESSION) {
        auto equality_expression = node->GetSon();
        auto relational_expression = equality_expression->GetSibling()->GetSibling();
        string op = equality_expression->GetSibling()->GetValue();
        assert(op == "==" || op == "!=");
        varNode var1 = translate_equality_expression(equality_expression);
        varNode var2 = translate_relational_expression(relational_expression);
        assert(var1.type == var2.type);
        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, type_BOOL);
        tNode.condition = var1.getVarName() + " " + op + " " + var2.getVarName();
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(interCode.genBinaryOpIR(tName, op, var1, var2));

        return tNode;
    }
    raise_error(node->GetLine());
}

// relational_expression -> additive_expression | relational_expression relop additive_expression
varNode Translator::translate_relational_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_ADDITIVE_EXPRESSION) {
        return translate_additive_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_SIMPLE_EXPRESSION) {
        auto relational_expression = node->GetSon();
        auto additive_expression = node->GetSon()->GetSibling()->GetSibling();
        string op = relational_expression->GetSibling()->GetSon()->GetValue();
        varNode var1 = translate_relational_expression(relational_expression);
        varNode var2 = translate_additive_expression(additive_expression);
        assert(var1.type == var2.type);
        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, type_BOOL);
        tNode.condition = var1.getVarName() + " " + op + " " + var2.getVarName();
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(interCode.genBinaryOpIR(tName, op, var1, var2));

        return tNode;
    }
    raise_error(node->GetLine());
}

// additive_expression -> multiplicative_expression | additive_expression + multiplicative_expression
// | additive_expressoon - multiplicative_expression
varNode Translator::translate_additive_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_TERM) {//multiplicative_expression
        return translate_multiplicative_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_ADDITIVE_EXPRESSION) {
        auto additive_expression = node->GetSon();
        auto multiplicative_expression = additive_expression->GetSibling()->GetSibling();
        string op = additive_expression->GetSibling()->GetSon()->GetValue();
        varNode var1 = translate_additive_expression(additive_expression);
        varNode var2 = translate_multiplicative_expression(multiplicative_expression);
        if (var1.type != var2.type) {
            raise_error(additive_expression->GetLine(), "The types are different!");
        }
        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, var1.type);
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(interCode.genBinaryOpIR(tName, op, var1, var2));

        return tNode;
    }
}

// multiplicative_expression -> unary_expression | multiplicative_expression * unary_expression
// | multiplicative_expression / unary_expression
varNode Translator::translate_multiplicative_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_FACTOR) {//unary_expression
        return translate_unary_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_TERM) {//multiplicative_expression
        auto multiplicative_expression = node->GetSon();
        auto unary_expression = multiplicative_expression->GetSibling()->GetSibling();
        string op = multiplicative_expression->GetSibling()->GetSon()->GetValue();
        varNode var1 = translate_multiplicative_expression(multiplicative_expression);
        varNode var2 = translate_unary_expression(unary_expression);
        if (var1.type != var2.type) {
            raise_error(multiplicative_expression->GetLine(), "The types are different!");
        }
        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, var1.type);
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(interCode.genBinaryOpIR(tName, op, var1, var2));

        return tNode;
    }
    raise_error(node->GetLine());
}

// unary_expression -> postfix_expression
// | unary_operator unary_expression | INC_OP unary_expression
varNode Translator::translate_unary_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_POSTFIX_EXPRESSION) {
        return translate_postfix_expression(node->GetSon());
    } else if (node->GetSon()->GetName() == T_INC_OP || node->GetSon()->GetName() == T_DEC_OP) {
        auto unary_expression = node->GetSon()->GetSibling();
        varNode var1 = translate_unary_expression(unary_expression);
        assert(var1.type == type_INT);
        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, type_INT);
        scopes.back().varMap.emplace(tName, tNode);
        interCode.addIR(tName + " = #1");
        if (node->GetSon()->GetName() == T_INC_OP) {
            interCode.addIR(interCode.genBinaryOpIR(var1.getVarName(), "+", var1, tNode));
        } else {
            interCode.addIR(interCode.genBinaryOpIR(var1.getVarName(), "-", var1, tNode));
        }
        return var1;
    } else if (node->GetSon()->GetSon()->GetName() == T_SUB_OP) {
        auto unary_expression = node->GetSon()->GetSibling();
        varNode var1 = translate_unary_expression(unary_expression);

        string tName = interCode.newTemp();
        varNode tNode = varNode(tName, var1.type);
        scopes.back().varMap.emplace(tName, tNode);

        interCode.addIR(tName + " = #0");

        string tName2 = interCode.newTemp();
        varNode tNode2 = varNode(tName, var1.type);
        scopes.back().varMap.emplace(tName2, tNode2);

        interCode.addIR(interCode.genBinaryOpIR(tNode2.getVarName(), "-", tNode, var1));
        return tNode2;
    } else if (node->GetSon()->GetSon()->GetName() == T_ADD_OP) {
        return translate_unary_expression(node->GetSon()->GetSibling());
    }
    raise_error(node->GetLine());
}

// postfix_expression -> primary_expression | postfix_expression ( ) | postfix_expression ( argument_expression_list )
// primary_expression -> IDENTIFIER | TRUE | FALSE | CONST_INT | CONST_DOUBLE
varNode Translator::translate_postfix_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_PRIMARY_EXPRESSION) {
        return translate_primary_expression(node->GetSon());
    } else if (node->GetSon()->GetSibling()->GetName() == T_LEFT_PARE) { // 函数调用
        auto ID = node->GetSon()->GetSon()->GetSon();
        string funcName = ID->GetValue();
        varNode var;
        if (funcTable.find(funcName) == funcTable.end()) {
            raise_error(ID->GetLine(), "Function " + funcName + " isn't defined!");
        }
        if (node->GetSon()->GetSibling()->GetSibling()->GetName() == T_ARG_LIST && funcName != "write") {
            auto argument_expression_list = node->GetSon()->GetSibling()->GetSibling();
            translate_arg_list(argument_expression_list, funcName);
        }
        funcNode function = funcTable[funcName];

        if (function.rtype == type_VOID) {
            if (funcName == "write") {
                varNode var = translate_expression(node->GetSon()->GetSibling()->GetSibling()->GetSon());
                interCode.addIR("WRITE " + var.getVarName());
            } else {
                interCode.addIR("CALL " + funcName);
            }
        } else {
            string tName = interCode.newTemp();
            var = varNode(tName, function.rtype);
            if (funcName == "read") {
                interCode.addIR("READ "+ tName);
            } else {
                interCode.addIR(tName + " = CALL " + funcName);
            }
        }
        return var;
    }
    raise_error(node->GetLine());
}

// arg_list -> arg_list , expression | expression
void Translator::translate_arg_list(SyntaxTree *node, string funcName) {
    auto argument_expression_list = node->GetSon();
    funcNode function = funcTable[funcName];
    int count = 0;
    while (argument_expression_list->GetName() == T_ARG_LIST) {
        varNode var = translate_expression(argument_expression_list->GetSibling()->GetSibling());
        interCode.addIR(interCode.genArgIR(var));
        argument_expression_list = argument_expression_list->GetSon();
        count ++;
        if(function.paralist[function.paralist.size()-count].type != var.type) {
            raise_error(argument_expression_list->GetLine(),"Wrong type argument!");
        }
    }
    varNode var = translate_expression(argument_expression_list);
    interCode.addIR(interCode.genArgIR(var));
    count++;
    if(function.paralist[function.paralist.size()-count].type != var.type||count != function.paralist.size()) {
        raise_error(argument_expression_list->GetLine(),"Wrong argument!");
    }
}

// primary_expression -> IDENTIFIER | TRUE | FALSE | CONST_INT | CONST_DOUBLE
// | ( expression )
varNode Translator::translate_primary_expression(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_ID) {
        auto ID = node->GetSon();
        varNode var = getNodeByName(ID->GetValue());
        assert(var.num >= 0);
        return var;
    } else if (node->GetSon()->GetName() == T_TRUE || node->GetSon()->GetName() == T_FALSE) {
        string tName = interCode.newTemp();

        varNode newNode = varNode(tName, type_BOOL);
        scopes.back().varMap.emplace(tName, newNode);
        if (node->GetSon()->GetName() == T_TRUE) {
            interCode.addIR(tName + " = #1");
        } else {
            interCode.addIR(tName + " = #0");
        }
        return newNode;
    } else if (node->GetSon()->GetName() == T_CONST_INT) {
        string int_literal = node->GetSon()->GetValue();
        string tName = interCode.newTemp();

        varNode newNode = varNode(tName, type_INT);
        scopes.back().varMap.emplace(tName, newNode);
        interCode.addIR(tName + " = #" + int_literal);
        return newNode;
    } else if (node->GetSon()->GetName() == T_CONST_DOUBLE) {
        string double_literal = node->GetSon()->GetValue();
        string tName = interCode.newTemp();

        varNode newNode = varNode(tName, type_DOUBLE);

        scopes.back().varMap.emplace(tName, newNode);
        interCode.addIR(tName + " = F" + double_literal);
        return newNode;
    } else if (node->GetSon()->GetName() == T_LEFT_PARE) {
        return translate_expression(node->GetSon()->GetSibling());
    }
    raise_error(node->GetLine());
}


// 函数定义，不支持先声明再定义
// function_definition -> type_specifier declarator compound_stmt
void Translator::translate_function_definition(SyntaxTree *node) {
    auto type_specifier = node->GetSon();
    auto declarator = type_specifier->GetSibling();
    auto compound_stmt = declarator->GetSibling();

    Types funcType = TypeMap.at(type_specifier->GetSon()->GetValue());
    string funcName = declarator->GetSon()->GetSon()->GetValue();
    funcNode function;
    if (funcTable.find(funcName) != funcTable.end()) {
        raise_error(node->GetLine(), "Function " + funcName + " has been defined!");
    }
    Scope funScope(funcName, funcType);
    scopes.push_back(funScope);
    funcTable.emplace(funcName, funScope.func);
    interCode.addIR("FUNCTION " + funcName + " :");
    funScope.func = function; // 多余>

    if (declarator->GetSon()->GetSibling()->GetSibling()->GetName() == T_PARAM_LIST) {
        translate_parameter_list(declarator->GetSon()->GetSibling()->GetSibling(), funcName, funcType);
    }

    funScope.func = funcTable[funcName]; // 添加了参数信息
    translate_compound_stmt(compound_stmt);
    scopes.pop_back();
}

// parameter_list -> parameter_list , parameter_declaration | parameter_declaration
void Translator::translate_parameter_list(SyntaxTree *node, string funcName, Types type) {
    if (node->GetSon()->GetName() == T_PARAM_LIST) {
        translate_parameter_list(node->GetSon(), funcName, type);
    } else if (node->GetSon()->GetName() == T_PARAM) {
        translate_parameter_declaration(node->GetSon(), funcName);
    }
    if (node->GetSon()->GetSibling() && node->GetSon()->GetSibling()->GetName() == T_COMMA) {
        translate_parameter_declaration(node->GetSon()->GetSibling()->GetSibling(), funcName);
    }
}

// parameter_declaration -> type_specifier declarator
void Translator::translate_parameter_declaration(SyntaxTree *node, string funcName) {
    auto type_specifier = node->GetSon();
    auto declarator = type_specifier->GetSibling();
    Types type = TypeMap.at(type_specifier->GetSon()->GetValue());
    if (type == 0 || type == type_VOID) {
        raise_error(type_specifier->GetLine(), "Wrong type of parameter");
    }
    string varName = declarator->GetSon()->GetValue();
    varNode var = varNode(varName, type);
    var.num = interCode.varNo++;
    scopes.back().func.paralist.push_back(var);
    funcTable[funcName].paralist.push_back(var);
    scopes.back().varMap.emplace(varName, var);
    interCode.addIR(interCode.genParamIR(var));
}

// statement -> compound_stmt | expression_stmt | selection_stmt |
// iteration_statement | jump_statement
void Translator::translate_statement(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_COMPOUND_STMT) {
        translate_compound_stmt(node->GetSon());
    } else if (node->GetSon()->GetName() == T_EXPRESSION_STMT && node->GetSon()->GetSon()->GetName() == T_EXPRESSION) {
        translate_expression(node->GetSon()->GetSon());
    } else if (node->GetSon()->GetName() == T_SELECTION_STMT) {
        translate_selection_stmt(node->GetSon());
    } else if (node->GetSon()->GetName() == T_ITERATION_STMT) {
        translate_iteration_stmt(node->GetSon());
    } else if (node->GetSon()->GetName() == T_JUMP_STMT) {
        translate_jump_statement(node->GetSon());
    }
}

// statement -> compound_stmt | expression_stmt | selection_stmt |
// iteration_statement | jump_statement
// statement 和 compound_stmt相互套娃
void Translator::translate_compound_stmt(SyntaxTree *node) {
    translate_SyntaxTree(node);
}

//selection_stmt : IF ( expression ) statement
// | IF ( expression ) statement ELSE statement
void Translator::translate_selection_stmt(SyntaxTree *node) {
    // TODO 改写
    if (node->GetSon()->GetName() == T_IF) {
        if (node->GetSon()->GetSibling()->GetSibling()->GetSibling()->GetSibling()->GetSibling() == nullptr) {
            Scope newblock;
            scopes.push_back(newblock);

            auto expression = node->GetSon()->GetSibling()->GetSibling();
            varNode exp_rnode = translate_expression(expression);
            auto statement = node->GetSon()->GetSibling()->GetSibling()->GetSibling()->GetSibling();

            string label1 = interCode.newLabel();
            string label2 = interCode.newLabel();

            if (exp_rnode.type == type_BOOL) {
                interCode.addIR("IF " + exp_rnode.condition + " GOTO " + label1);
            } else {
                string t0Name = interCode.newTemp();
                varNode var = varNode(t0Name, type_INT);
                interCode.addIR(t0Name + " = #0");

                interCode.addIR("IF " + exp_rnode.getVarName() + " != " + t0Name + " GOTO " + label1);
            }

            interCode.addIR("GOTO " + label2);
            interCode.addIR("LABEL " + label1 + " :");

            translate_statement(statement);

            interCode.addIR("LABEL " + label2 + " :");

            //弹出添加的block
            scopes.pop_back();

        } else if (node->GetSon()->GetSibling()->GetSibling()->GetSibling()->GetSibling()->GetSibling()->GetName() == T_ELSE) {
            //添加一个新的block
            Scope newblock1;
            scopes.push_back(newblock1);

            auto expression = node->GetSon()->GetSibling()->GetSibling();
            varNode exp_rnode = translate_expression(expression);
            auto statement1 = node->GetSon()->GetSibling()->GetSibling()->GetSibling()->GetSibling();
            auto statement2 = node->GetSon()->GetSibling()->GetSibling()->GetSibling()->GetSibling()->GetSibling()->GetSibling();

            string label1 = interCode.newLabel();
            string label2 = interCode.newLabel();
            string label3 = interCode.newLabel();

            if (exp_rnode.type == type_BOOL) {
                interCode.addIR("IF " + exp_rnode.condition + " GOTO " + label1);
            } else {
                string t0Name = interCode.newTemp();
                varNode newznode = varNode(t0Name, type_INT);
                interCode.addIR(t0Name + " = #0");

                interCode.addIR("IF " + exp_rnode.getVarName() + " != " + t0Name + " GOTO " + label1);
            }

            interCode.addIR("GOTO " + label2);
            interCode.addIR("LABEL " + label1 + " :");

            translate_statement(statement1);

            interCode.addIR("GOTO " + label3);
            //弹出添加的block
            scopes.pop_back();

            //else
            interCode.addIR("LABEL " + label2 + " :");

            Scope newblock2;
            scopes.push_back(newblock2);

            translate_statement(statement2);

            interCode.addIR("LABEL " + label3 + " :");

            //弹出添加的block
            scopes.pop_back();
        }
    }
}

// jump_stmt -> BREAK ; | RETURN ; | RETURN expression ;
void Translator::translate_jump_statement(SyntaxTree *node) {
    if (node->GetSon()->GetName() == T_BREAK) {
        int num = getBreakScopeNumber();
        if (num < 0) {
            raise_error(node->GetSon()->GetLine(), "This scope doesn't support break.");
        }

        interCode.addIR("GOTO " + scopes[num].breakLabelname);
    } else if (node->GetSon()->GetName() == T_RETURN) {
        Types funcType = getRType();
        if (node->GetSon()->GetSibling()->GetName() == T_EXPRESSION) {//return expression
            varNode rnode = translate_expression(node->GetSon()->GetSibling());
            interCode.addIR(interCode.genReturnIR(rnode));
            if (rnode.type != funcType) {
                raise_error(node->GetSon()->GetSibling()->GetLine(), "rong return type!");
            }
        } else if (node->GetSon()->GetSibling()->GetName() == T_SEMICOLON) {//return ;
            interCode.addIR("RETURN");
            if (funcType != type_VOID) {
                raise_error(node->GetSon()->GetSibling()->GetLine(), "Wrong return type!");
            }
        }
    }
}

// iteration_stmt -> WHILE ( expression ) statement
void Translator::translate_iteration_stmt(SyntaxTree *node) {
    // TODO 需要改写
    if (node->GetSon()->GetName() == T_WHILE) {
        Scope newblock;
        newblock.canBreak = true;
        scopes.push_back(newblock);

        auto expression = node->GetSon()->GetSibling()->GetSibling();
        auto statement = node->GetSon()->GetSibling()->GetSibling()->GetSibling()->GetSibling();

        string label1 = interCode.newLabel();
        string label2 = interCode.newLabel();
        string label3 = interCode.newLabel();

        scopes.back().breakLabelname = label3;

        interCode.addIR("LABEL " + label1 + " :");

        varNode var = translate_expression(expression);

        if (var.type == type_BOOL) {
            interCode.addIR("IF " + var.condition + " GOTO " + label2);
        } else {
            string tempzeroname = interCode.newTemp();
            varNode newznode = varNode(tempzeroname, type_INT);
            interCode.addIR(tempzeroname + " = #0");

            interCode.addIR("IF " + var.getVarName() + " != " + tempzeroname + " GOTO " + label2);
        }
        interCode.addIR("GOTO " + label3);
        interCode.addIR("LABEL " + label2 + " :");

        translate_statement(statement);

        interCode.addIR("GOTO " + label1);
        interCode.addIR("LABEL " + label3 + " :");

        scopes.pop_back();
    }
}

