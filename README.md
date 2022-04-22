# -Compilers-Project

Compiler to deiGO language

## Run

lex gocompiler.l

yacc -d gocompiler.y

cc -o compiler lex.yy.c y.tab.c functions.c semantics.c symbol_table.c

./compiler < input.txt or ./compiler
