all: lex gcc zip

lex: uccompiler.l
	lex uccompiler.l

gcc: lex.yy.c
	gcc lex.yy.c -o lexer

zip: lex.yy.c uccompiler.l
	zip uccompiler.zip uccompiler.l lex.yy.c

clean:
	rm -f lexer lex.yy.c uccompiler.zip

.PHONY: clean
