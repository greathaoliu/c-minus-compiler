%{
#include "y.tab.h"
#include "SyntaxTree.h"
#include "Translator.h"
#include <cstring>    
#include <cstdio>
void ConsumeComment();
%}
%option yylineno

letter [a-zA-Z]
digit [0-9]
numbers ([0-9])+
floats ([0-9]+\.[0-9]+)  
plus "+"  
minus "-"  
times "*"  
divide "/"  
lp "("  
rp ")"  
pow "^"
delim [" "/t/n]  
ws {delim}*  

%%

"/*"[/]*([^*/][/]*|[*]|[^*/])*"*/" {/*comments, do nothing*/}
"//"[^\n]* {/*comments, do nothing*/}

"else" {yylval.syntaxtree=new SyntaxTree(T_ELSE,'0',yylineno);return ELSE;}
"if" {yylval.syntaxtree=new SyntaxTree(T_IF,'0',yylineno);return IF;}
"int" {yylval.syntaxtree=new SyntaxTree(T_INT,'0',yylineno);return INT;}
"return" {yylval.syntaxtree=new SyntaxTree(T_RETURN,'0',yylineno);return RETURN;}
"void" {yylval.syntaxtree=new SyntaxTree(T_VOID,'0',yylineno);return VOID;}
"while" {yylval.syntaxtree=new SyntaxTree(T_WHILE,'0',yylineno);return WHILE;}
"double" {yylval.syntaxtree=new SyntaxTree(T_DOUBLE,'0',yylineno);return DOUBLE;}
"true" {yylval.syntaxtree=new SyntaxTree(T_TRUE,'0',yylineno);return TRUE;}
"false" {yylval.syntaxtree=new SyntaxTree(T_FALSE,'0',yylineno);return FALSE;}
"break" {yylval.syntaxtree=new SyntaxTree(T_BREAK,'0',yylineno);return BREAK;}
"bool" {yylval.syntaxtree=new SyntaxTree(T_BOOL,'0',yylineno);return BOOL;}
"char" {yylval.syntaxtree=new SyntaxTree(T_CHAR,'0',yylineno);return CHAR;}
"or" {yylval.syntaxtree=new SyntaxTree(T_OR_OP,'0',yylineno);return OR_OP;}
"and" {yylval.syntaxtree=new SyntaxTree(T_AND_OP,'0',yylineno);return AND_OP;}

{letter}({letter}|{digit})* {yylval.syntaxtree=new SyntaxTree(T_ID,'0',yylineno);return ID;}

{numbers} {yylval.syntaxtree=new SyntaxTree(T_CONST_INT,'0',yylineno);return CONST_INT;}
{floats} {yylval.syntaxtree=new SyntaxTree(T_CONST_DOUBLE,'0',yylineno);return CONST_DOUBLE;}

letter?\"(\\.|[^\\"\n])*\" {yylval.syntaxtree=new SyntaxTree(T_STRING,'0',yylineno);return STRING;}

"||" {yylval.syntaxtree=new SyntaxTree(T_OR_OP,'0',yylineno);return OR_OP;}
"&&" {yylval.syntaxtree=new SyntaxTree(T_AND_OP,'0',yylineno);return AND_OP;}
"--" {yylval.syntaxtree=new SyntaxTree(T_DEC_OP,'0',yylineno);return DEC_OP;}
"++" {yylval.syntaxtree=new SyntaxTree(T_INC_OP,'0',yylineno);return INC_OP;}
"==" {yylval.syntaxtree=new SyntaxTree(T_EQUAL,'0',yylineno);return EQUAL;}
"<=" {yylval.syntaxtree=new SyntaxTree(T_LESS_EQUAL,'0',yylineno);return LESS_EQUAL;}
">=" {yylval.syntaxtree=new SyntaxTree(T_GREATER_EQUAL,'0',yylineno);return GREATER_EQUAL;}
"!=" {yylval.syntaxtree=new SyntaxTree(T_NOT_EQUAL,'0',yylineno);return NOT_EQUAL;}
"+" {yylval.syntaxtree=new SyntaxTree(T_ADD_OP,'0',yylineno);return ADD_OP;}
"-" {yylval.syntaxtree=new SyntaxTree(T_SUB_OP,'0',yylineno);return SUB_OP;}
"*" {yylval.syntaxtree=new SyntaxTree(T_MUL_OP,'0',yylineno);return MUL_OP;}
"/" {yylval.syntaxtree=new SyntaxTree(T_DIV_OP,'0',yylineno);return DIV_OP;}
"<" {yylval.syntaxtree=new SyntaxTree(T_LESS,'0',yylineno);return LESS;}
">" {yylval.syntaxtree=new SyntaxTree(T_GREATER,'0',yylineno);return GREATER;}
"%" {yylval.syntaxtree=new SyntaxTree(T_MOD_OP,'0',yylineno);return MOD_OP;}
";" {yylval.syntaxtree=new SyntaxTree(T_SEMICOLON,'0',yylineno);return SEMICOLON;}
"," {yylval.syntaxtree=new SyntaxTree(T_COMMA,'0',yylineno);return COMMA;}
"(" {yylval.syntaxtree=new SyntaxTree(T_LEFT_PARE,'0',yylineno);return LEFT_PARE;}
")" {yylval.syntaxtree=new SyntaxTree(T_RIGHT_PARE,'0',yylineno);return RIGHT_PARE;}
"[" {yylval.syntaxtree=new SyntaxTree(T_LEFT_BRA,'0',yylineno);return LEFT_BRA;}
"]" {yylval.syntaxtree=new SyntaxTree(T_RIGHT_BRA,'0',yylineno);return RIGHT_BRA;}
"{" {yylval.syntaxtree=new SyntaxTree(T_LEFT_BRACE,'0',yylineno);return LEFT_BRACE;}
"}" {yylval.syntaxtree=new SyntaxTree(T_RIGHT_BRACE,'0',yylineno);return RIGHT_BRACE;}
"=" {yylval.syntaxtree=new SyntaxTree(T_ASSIGN,'0',yylineno);return ASSIGN;}
[\t\v\n\f ] {/*ignore*/}
. {/*ignore*/}
%%

void ConsumeComment(){
    char input, pre=0;
    while(cin>>input){
        if(input=='/'&&pre=='*'){
	    return;
	}
	pre=input;
    }
}

int yywrap() {
	return 1;
}
