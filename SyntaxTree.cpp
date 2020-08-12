#include "SyntaxTree.h"

void PrintName(Name n) {
    switch (n) {
        case T_CONST_INT:
            cout << "CONST_INT";
            break;
        case T_CONST_DOUBLE:
            cout << "CONST_DOUBLE";
            break;
        case T_STRING:
            cout << "STRING";
            break;
        case T_TRUE:
            cout << "TRUE";
            break;
        case T_FALSE:
            cout << "FALSE";
            break;
        case T_BREAK:
            cout << "BREAK";
            break;
        case T_ID:
            cout << "ID";
            break;
        case T_ELSE:
            cout << "ELSE";
            break;
        case T_IF:
            cout << "IF";
            break;
        case T_INT:
            cout << "INT";
            break;
        case T_RETURN:
            cout << "RETURN";
            break;
        case T_VOID:
            cout << "VOID";
            break;
        case T_CHAR:
            cout << "CHAR";
            break;
        case T_BOOL:
            cout << "BOOL";
            break;
        case T_WHILE:
            cout << "WHILE";
            break;
        case T_DOUBLE:
            cout << "DOUBLE";
            break;
        case T_EQUAL:
            cout << "EQUAL";
            break;
        case T_LESS_EQUAL:
            cout << "LESS_EQUAL";
            break;
        case T_GREATER_EQUAL:
            cout << "GREATER_EQUAL";
            break;
        case T_NOT_EQUAL:
            cout << "NOT_EQUAL";
            break;
        case T_ADD_OP:
            cout << "ADD_OP";
            break;
        case T_SUB_OP:
            cout << "SUB_OP";
            break;
        case T_MUL_OP:
            cout << "MUL_OP";
            break;
        case T_DIV_OP:
            cout << "DIV_OP";
            break;
        case T_ASSIGN:
            cout << "ASSIGN";
            break;
        case T_LESS:
            cout << "LESS";
            break;
        case T_GREATER:
            cout << "GREATER";
            break;
        case T_MOD_OP:
            cout << "MOD_OP";
            break;
        case T_SEMICOLON:
            cout << "SEMICOLON";
            break;
        case T_COMMA:
            cout << "COMMA";
            break;
        case T_LEFT_PARE:
            cout << "LEFT_PARE";
            break;
        case T_RIGHT_PARE:
            cout << "RIGHT_PARE";
            break;
        case T_LEFT_BRA:
            cout << "LEFT_BRA";
            break;
        case T_RIGHT_BRA:
            cout << "RIGHT_BRA";
            break;
        case T_LEFT_BRACE:
            cout << "LEFT_BRACE";
            break;
        case T_RIGHT_BRACE:
            cout << "RIGHT_BRACE";
            break;
        case T_PROGRAM:
            cout << "PROGRAM";
            break;
        case T_DECLARATION_LIST:
            cout << "DECLARATION_LIST";
            break;
        case T_DECLARATION:
            cout << "DECLARATION";
            break;
        case T_VAR_DECLARATION:
            cout << "VAR_DECLARATION";
            break;
        case T_TYPE_SPECIFIER:
            cout << "TYPE_SPECIFIER";
            break;
        case T_FUNC_DEFINITION:
            cout << "FUNC_DECLARATION";
            break;
        case T_PARAM_LIST:
            cout << "PARAM_LIST";
            break;
        case T_PARAM:
            cout << "PARAM";
            break;
        case T_COMPOUND_STMT:
            cout << "COMPOUND_STMT";
            break;
        case T_BLOCK_ITEM_LIST:
            cout << "BLOCK_ITEM_LIST";
            break;
        case T_BLOCK_ITEM:
            cout << "BLOCK_ITEM";
            break;
        case T_STATEMENT:
            cout << "STATEMENT";
            break;
        case T_EXPRESSION_STMT:
            cout << "EXPRESSION_STMT";
            break;
        case T_SELECTION_STMT:
            cout << "SELECTION_STMT";
            break;
        case T_ITERATION_STMT:
            cout << "ITERATION_STMT";
            break;
        case T_JUMP_STMT:
            cout << "JUMP_STMT";
            break;
        case T_EXPRESSION:
            cout << "EXPRESSION";
            break;
        case T_SIMPLE_EXPRESSION:
            cout << "SIMPLE_EXPRESSION";
            break;
        case T_RELOP:
            cout << "RELOP";
            break;
        case T_ADDITIVE_EXPRESSION:
            cout << "ADDITIVE_EXPRESSION";
            break;
        case T_ADDOP:
            cout << "ADDOP";
            break;
        case T_TERM:
            cout << "TERM";
            break;
        case T_MULOP:
            cout << "MULOP";
            break;
        case T_FACTOR:
            cout << "FACTOR";
            break;
        case T_ARG_LIST:
            cout << "ARG_LIST";
            break;
        case T_DECLARATOR:
            cout << "DECLARATOR";
            break;
        case T_DEC_OP:
            cout << "DEC_OP";
            break;
        case T_INC_OP:
            cout << "INC_OP";
            break;
        case T_EQUALITY_EXPRESSION:
            cout << "EQUALITY_EXPRESSION";
            break;
        case T_INIT_DECLARATOR_LIST:
            cout << "INIT_DECLARATOR_LIST";
            break;
        case T_INIT_DECLARATOR:
            cout << "INIT_DECLARATOR";
            break;
        case T_LOGICAL_AND_EXPRESSION:
            cout << "LOGICAL_AND_EXPRESSION";
            break;
        case T_LOGICAL_OR_EXPRESSION:
            cout << "LOGICAL_OR_EXPRESSION";
            break;
        case T_POSTFIX_EXPRESSION:
            cout << "POSTFIX_EXPRESSION";
            break;
        case T_PRIMARY_EXPRESSION:
            cout << "PRIMARY_EXPRESSION";
            break;
        case T_UNARYOP:
            cout << "UNARYOP";
            break;
        case T_AND_OP:
            cout << "AND_OP";
            break;
        case T_OR_OP:
            cout << "OR_OP";
            break;
        default:
            cout << "ttt";
            break;
    }
}

SyntaxTree::SyntaxTree(Name name, int num, ...) {
    va_list ValueList;
    this->LeftChild = NULL;
    this->RightChild = NULL;
    this->name = name;
    this->Value = "";
    va_start(ValueList, num);//initializtion
    if (num > 0) {//Non-terminal
        SyntaxTree *tmp = NULL;
        tmp = va_arg(ValueList, SyntaxTree * );
        this->LeftChild = tmp;
        this->Line = tmp->GetLine();
        if (num > 1) {//more than one
            for (int i = 1; i < num; i++) {
                tmp->SetSibling(va_arg(ValueList, SyntaxTree * ));
                tmp = tmp->GetSibling();
                if (this->Line == -2)this->Line = tmp->GetLine();
            }
        } else {//one
            this->Value = tmp->GetValue();
        }
    } else {//empty
        this->Line = -2;
    }
}

SyntaxTree::SyntaxTree(Name name, char zero, int Line) {
    this->LeftChild = NULL;
    this->RightChild = NULL;
    this->name = name;
    this->Line = Line;
    switch (this->name) {
        case T_CONST_INT:
            this->Value = yytext;
            break;
        case T_CONST_DOUBLE:
            this->Value = yytext;
            break;
        case T_TRUE:
            this->Value = "1";
            break;
        case T_FALSE:
            this->Value = "0";
            break;
        case T_STRING:
            this->Value = yytext;
            break;
        default:
            this->Value = yytext;//including identifier like int,double,for,while
            break;
    }
}

SyntaxTree::~SyntaxTree() {
    if (!LeftChild) {
        delete LeftChild;
    }
    if (!RightChild) {
        delete RightChild;
    }
    delete this;
}

void SyntaxTree::eval(int level) {
    Name NAME = this->name;
    if (this->Line != -1) {
        cout << "{label: '";
        PrintName(this->name);
        cout << "'";
    }
    if (this->LeftChild != NULL) {
        cout << "," << endl;
        cout << "children: [";
        this->LeftChild->eval(level + 1);
        cout << "]";
    }
    cout<<"}";
    if (this->RightChild != NULL) {
        cout << "," << endl;
        this->RightChild->eval(level);
    }
}