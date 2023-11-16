all: clean lex yacc gcc zip

lex: uccompiler.l
	lex uccompiler.l

yacc: uccompiler.y
	yacc -dv  uccompiler.y

gcc: lex.yy.c
	gcc lex.yy.c -o lexer

zip: lex.yy.c uccompiler.l
	zip uccompiler.zip uccompiler.l uccompiler.y funcoes.c funcoes.h

clean:
	rm -f lexer lex.yy.c y.tab.c y.tab.h uccompiler.zip

.PHONY: clean
