%{
    #include <stdbool.h>

    int l = 1, c = 1;
    bool flag=false;                //-l
    int string = 0; 
    int comment[2]; 

    
%}

id          [a-zA-Z_][a-zA-Z0-9_]*
natural     [0-9]+
decimal     ([0-9]+\.[0-9]*|\.[0-9]+|[0-9]+)([eE][-+]?[0-9]+)?
chrlit      \'([^\'\n\\]|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))\'
char        "char"
while       "while"
else        "else"
e           "e"
if          "if"
int         "int"
short       "short"
double      "double"
return      "return"
void        "void"
bitwiseand  "&"
bitwiseor   "|" 
bitwisexor  "^"
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

reserved    auto|break|const|continue|do|enum|extern|float|for|goto|register|long|signed|unsigned|sizeof|static|struct|switch|case|default|typedef|union|volatile|_Bool|_Imaginary|restrict|inline|_Complex|"["|"]"|"++"|"--"
%x SCOMMENT MLCOMMENT 

%%
{reserved}      { if(flag) printf("RESERVED(%s)\n", yytext); c += yyleng;}
{if}            { if(flag) printf("IF\n"); c+=yyleng; }
{int}           { if(flag) printf("INT\n"); c+=yyleng; }
{short}         { if(flag) printf("SHORT\n"); c+=yyleng; }
{double}        { if(flag) printf("DOUBLE\n"); c+=yyleng; }
{char}          { if(flag) printf("CHAR\n"); c+=yyleng; }
{else}          { if(flag) printf("ELSE\n"); c+=yyleng; }
{while}         { if(flag) printf("WHILE\n"); c+=yyleng; }
{return}        { if(flag) printf("RETURN\n"); c+=yyleng; }
{void}          { if(flag) printf("VOID\n"); c+=yyleng; }
{bitwiseand}    { if(flag) printf("BITWISEAND\n"); c+=yyleng; }
{bitwiseor}     { if(flag) printf("BITWISEOR\n"); c+=yyleng; }
{bitwisexor}    { if(flag) printf("BITWISEXOR\n"); c+=yyleng; }
{and}           { if(flag) printf("AND\n"); c+=yyleng; }
{assign}        { if(flag) printf("ASSIGN\n"); c+=yyleng; }
{mul}           { if(flag) printf("MUL\n"); c+=yyleng; }
{comma}         { if(flag) printf("COMMA\n"); c+=yyleng; }
{div}           { if(flag) printf("DIV\n"); c+=yyleng; }
{eq}            { if(flag) printf("EQ\n"); c+=yyleng; }
{ge}            { if(flag) printf("GE\n"); c+=yyleng; }
{gt}            { if(flag) printf("GT\n"); c+=yyleng; }
{lbrace}        { if(flag) printf("LBRACE\n"); c+=yyleng; }
{le}            { if(flag) printf("LE\n"); c+=yyleng; }
{lpar}          { if(flag) printf("LPAR\n"); c+=yyleng; }
{lt}            { if(flag) printf("LT\n"); c+=yyleng; }
{minus}         { if(flag) printf("MINUS\n"); c+=yyleng; }
{mod}           { if(flag) printf("MOD\n"); c+=yyleng; }
{ne}            { if(flag) printf("NE\n"); c+=yyleng; }
{not}           { if(flag) printf("NOT\n"); c+=yyleng; }
{or}            { if(flag) printf("OR\n"); c+=yyleng; }
{plus}          { if(flag) printf("PLUS\n"); c+=yyleng; }
{rbrace}        { if(flag) printf("RBRACE\n"); c+=yyleng; }
{rpar}          { if(flag) printf("RPAR\n"); c+=yyleng; }
{semi}          { if(flag) printf("SEMI\n"); c+=yyleng; }
{e}             { if(flag) printf("E(%s)\n", yytext); c+=yyleng; }
{id}            { if(flag) printf("IDENTIFIER(%s)\n", yytext); c+=yyleng; }
{natural}       { if(flag) printf("NATURAL(%s)\n" , yytext); c+=yyleng; }
{decimal}       { if(flag) printf("DECIMAL(%s)\n", yytext); c+=yyleng; }
{chrlit}        { if(flag) printf("CHRLIT(%s)\n", yytext); c += yyleng; }


\'([^\n\r\'\\]|\\.)*\' {printf("Line %d, column %d: invalid char constant (%s)\n", l, c, yytext); c += yyleng;}
\'[^\n\r\']*\'?        {printf("Line %d, column %d: unterminated char constant\n", l, c);}


"//"									{c += yyleng; BEGIN SCOMMENT;}
<SCOMMENT>.								{c+=yyleng;}
<SCOMMENT>\n        					{l++; c=1;BEGIN 0;}


"/*"									{BEGIN MLCOMMENT;comment[0]=l; comment[1]=c-1; c+=yyleng;}
<MLCOMMENT>.							{c+=yyleng;}
<MLCOMMENT>\r|\n|(\r\n)					{l++;c=1;}
<MLCOMMENT><<EOF>>						{printf("Line %d, column %d: unterminated comment\n",comment[0],comment[1]); c+=yyleng;BEGIN 0;}
<MLCOMMENT>"*/"							{c+=yyleng;BEGIN 0;}


" "|"\t"|"\f"          {c += yyleng;}
"\n"|"\r"|"\r\n"       {l++; c = 1;}
.           {printf("Line %d, column %d: unrecognized character (%s)\n",l,c,yytext); c+=yyleng; }

%%
extern int yylex();
int main(int argc, char *argv[]) {
    if(argc >= 2 && strcmp(argv[1], "-l") == 0){
        flag = true;
    }

    yylex();    
    return 0;
}
int yywrap() { 
    return 1;
}
