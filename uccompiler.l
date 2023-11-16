%{
    #include <stdbool.h>
    #include "y.tab.h"
    #include "funcoes.h"


    int yyparse(void);

    int l = 1, c = 1;
    bool flag=false;                //-l
    int string = 0; 
    int comment[2]; 


    
%}

ID          [a-zA-Z_][a-zA-Z0-9_]*
NATURAL     [0-9]+
DECIMAL     ([0-9]+\.[0-9]*|\.[0-9]+|[0-9]+)([eE][-+]?[0-9]+)?
CHRLIT      \'([^\'\n\\]|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))\'
CHAR        "char"
WHILE       "while"
ELSE        "else"
IF          "if"
INT         "int"
SHORT       "short"
DOUBLE      "double"
RETURN      "return"
VOID        "void"
BITWISEAND  "&"
BITWISEOR   "|" 
BITWISEXOR  "^"
AND         "&&"
ASSIGN      "="
MUL         "*"
COMMA       ","
DIV         "/"
EQ          "=="
GE          ">="
GT          ">"
LBRACE      "{"
LE          "<="
LPAR        "("
LT          "<"
MINUS       "-"
MOD         "%"
NE          "!="
NOT         "!"
OR          "||"
PLUS        "+"
RBRACE      "}"
RPAR        ")"
SEMI        ";"

RESERVED    auto|break|const|continue|do|enum|extern|float|for|goto|register|long|signed|unsigned|sizeof|static|struct|switch|case|default|typedef|union|volatile|_Bool|_Imaginary|restrict|inline|_Complex|"["|"]"|"++"|"--"
%X SCOMMENT MLCOMMENT 

%%
{RESERVED}      { if(flag) printf("RESERVED(%s)\n", yytext); c += yyleng; return RESERVED;}
{IF}            { if(flag) printf("IF\n"); c+=yyleng; return IF;}
{INT}           { if(flag) printf("INT\n"); c+=yyleng; return INT;}
{SHORT}         { if(flag) printf("SHORT\n"); c+=yyleng; return SHORT;}
{DOUBLE}        { if(flag) printf("DOUBLE\n"); c+=yyleng; return DOUBLE;}
{CHAR}          { if(flag) printf("CHAR\n"); c+=yyleng; return CHAR;}
{ELSE}          { if(flag) printf("ELSE\n"); c+=yyleng; return ELSE;}
{WHILE}         { if(flag) printf("WHILE\n"); c+=yyleng; return WHILE;}
{RETURN}        { if(flag) printf("RETURN\n"); c+=yyleng; return RETURN;}
{VOID}          { if(flag) printf("VOID\n"); c+=yyleng; return VOID;}
{BITWISEAND}    { if(flag) printf("BITWISEAND\n"); c+=yyleng; return BITWISEAND;}
{BITWISEOR}     { if(flag) printf("BITWISEOR\n"); c+=yyleng;return BITWISEOR;}
{BITWISEXOR}    { if(flag) printf("BITWISEXOR\n"); c+=yyleng;return BITWISEXOR ;}
{AND}           { if(flag) printf("AND\n"); c+=yyleng; return AND;}
{ASSIGN}        { if(flag) printf("ASSIGN\n"); c+=yyleng; return ASSIGN;}
{MUL}           { if(flag) printf("MUL\n"); c+=yyleng; return MUL;}
{COMMA}         { if(flag) printf("COMMA\n"); c+=yyleng; return COMMA;}
{DIV}           { if(flag) printf("DIV\n"); c+=yyleng; return DIV;}
{EQ}            { if(flag) printf("EQ\n"); c+=yyleng; return EQ;}
{GE}            { if(flag) printf("GE\n"); c+=yyleng; return GE;}
{GT}            { if(flag) printf("GT\n"); c+=yyleng; return GT;}
{LBRACE}        { if(flag) printf("LBRACE\n"); c+=yyleng; return LBRACE;}
{LE}            { if(flag) printf("LE\n"); c+=yyleng; return LE;}
{LPAR}          { if(flag) printf("LPAR\n"); c+=yyleng; return LPAR;}
{LT}            { if(flag) printf("LT\n"); c+=yyleng; return LT;}
{MINUS}         { if(flag) printf("MINUS\n"); c+=yyleng; return MINUS;}
{MOD}           { if(flag) printf("MOD\n"); c+=yyleng; return MOD;}
{NE}            { if(flag) printf("NE\n"); c+=yyleng; return NE;}
{NOT}           { if(flag) printf("NOT\n"); c+=yyleng; return NOT;}
{OR}            { if(flag) printf("OR\n"); c+=yyleng; return OR;}
{PLUS}          { if(flag) printf("PLUS\n"); c+=yyleng;return PLUS; }
{RBRACE}        { if(flag) printf("RBRACE\n"); c+=yyleng; return RBRACE;}
{RPAR}          { if(flag) printf("RPAR\n"); c+=yyleng; return RPAR;}
{SEMI}          { if(flag) printf("SEMI\n"); c+=yyleng; return SEMI;}
{NATURAL}       { if(flag) printf("NATURAL(%s)\n" , yytext); c+=yyleng; return NATURAL;}
{DECIMAL}       { if(flag) printf("DECIMAL(%s)\n", yytext); c+=yyleng; return DECIMAL;}
{ID}            { if(flag) printf("IDENTIFIER(%s)\n", yytext); c+=yyleng; return ID;}
{CHRLIT}        { if(flag) printf("CHRLIT(%s)\n", yytext); c += yyleng; return CHRLIT;}



\'([^\n\r\'\\]|\\.)*\' {printf("Line %d, column %d: invalid char constant (%s)\n", l, c, yytext); c += yyleng;}
\'[^\n\r\']*\'?        {printf("Line %d, column %d: unterminated char constant\n", l, c);}


"//"									{c += yyleng; BEGIN SCOMMENT;}
<SCOMMENT>.								{c+=yyleng;}
<SCOMMENT>\n        					{l++; c=1;BEGIN 0;}


"/*"									{comment[0]=l; comment[1]=c; c+=yyleng;BEGIN MLCOMMENT;}
<MLCOMMENT>.							{c+=yyleng;}
<MLCOMMENT>\r|\n|(\r\n)					{l++;c=1;}
<MLCOMMENT><<EOF>>						{printf("Line %d, column %d: unterminated comment\n",comment[0],comment[1]); c+=yyleng;BEGIN 0;}
<MLCOMMENT>"*/"							{c+=yyleng;BEGIN 0;}


" "|"\t"|"\f"          {c += yyleng;}
"\n"|"\r"|"\r\n"       {l++; c = 1;}
.           {printf("Line %d, column %d: unrecognized character (%s)\n",l,c,yytext); c+=yyleng; }

%%
void yyerror(char *s) {
    printf("Line %d, column %d: %s: %s \n",l,c, s, yytext);
}
extern int yylex();
int main(int argc, char *argv[]) {
    if(argc >= 2 && strcmp(argv[1], "-l") == 0){
        flag = true;
        while(yylex());
    }else if(argc >= 2 && strcmp(argv[1], "-t") == 0){
       yyparse();
       
    }

    return 0;
}
int yywrap() { 
    return 1;
}
