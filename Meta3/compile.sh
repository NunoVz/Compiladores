echo 'yacc'
yacc -d -v -Wyacc -Wcounterexamples uccompiler.y
echo 'lex'
lex uccompiler.l
echo 'cc'
cc -o lexer y.tab.c lex.yy.c funcoes.c
zip uccompiler.zip uccompiler.y uccompiler.l funcoes.h funcoes.c 
#bash test_all.sh uccompiler
