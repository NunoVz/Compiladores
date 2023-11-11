%{
    /* place here any C variables and definitions */
    int line = 1, column = 1;
    
%}

id          [a-zA-Z_][a-zA-Z0-9_]*
natural     [0-9]+
decimal     ([0-9]+\.[0-9]*|\.[0-9]+|[0-9]+)([eE][-+]?[0-9]+)?
chrlit      '[^\'\\\n]|\\[ntr'"\\]|[\\][0-7]{1,3}'
e           "e"
if          "if"
int         "int"
short       "short"
double      "double"
return      "return"
void        "void"
bitwiseand  "&"
bitwiseor   "|"
bitwisexor  "ˆ"
and         "&&"
assign      "="
mul         "*"
comma       ","
div         "/"
eq          "=="
ge          ">="
gt          ">"
lbrace      "{"
le          "<="
lpar        "("
lt          "<"
minus       "-"
mod         "%"
ne          "!="
not         "!"
or          "||"
plus        "+"
rbrace      "}"
rpar        ")"
semi        ";"

%%

{id}       { printf("IDENTIFIER(%s)\n", yytext); }
{natural}  { printf("NATURAL(%s)\n" , yytext); }
{decimal}  { printf("DECIMAL(%s)\n", yytext); }
{chrlit}   { printf("CHRLIT(%s)\n", yytext); }
{e}        { printf("E(%s)\n", yytext); }

.          { printf("Unrecognized character: %s\n", yytext); }

%%
extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
