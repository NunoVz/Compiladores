echo 'yacc'
yacc -d -v -Wyacc -Wcounterexamples uccompiler.y
echo 'lex'
lex uccompiler.l
echo 'cc'
cc -o uccompiler y.tab.c lex.yy.c funcoes.c symtable.c
zip uccompiler.zip uccompiler.y uccompiler.l funcoes.h funcoes.c symtable.c symtable.h
#bash test_all.sh uccompiler
