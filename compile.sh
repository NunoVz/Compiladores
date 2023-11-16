echo 'yacc'
yacc -d -v -Wyacc uccompiler.y
echo 'lex'
lex uccompiler.l
echo 'cc'
cc -o uccompiler y.tab.c lex.yy.c funcoes.c
#zip uccompiler.zip uccompiler.y uccompiler.l uccompiler.h uccompiler.c
#bash test_all.sh uccompiler
