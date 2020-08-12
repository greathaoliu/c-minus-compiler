yacc -d project.y
lex project.l
g++ -std=c++11 -o compiler SyntaxTree.cpp Translator.cpp InterRepresent.cpp lex.yy.c y.tab.c
./compiler inputfilename
