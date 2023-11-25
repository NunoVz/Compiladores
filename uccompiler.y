%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"
    #include "funcoes.h"



    extern int yylex(void);
    extern int yyparse();
    extern void yyerror(char *s);

    extern char *yytext;
    int debug =0;
    bool errorflag=false;
    extern int errFlag;

    extern bool flagTree;                //-t

    no root;
	no aux;
	no aux1;
	no aux2;


%}
%union{
    char *value;
   	struct node *no;
}

    %token CHAR INT VOID SHORT DOUBLE
    %token PLUS MINUS MUL DIV MOD OR AND BITWISEAND BITWISEOR BITWISEXOR
    %token EQ NE LE GE LT GT ASSIGN COMMA NOT
    %token LPAR RPAR LBRACE RBRACE SEMI IF ELSE WHILE RETURN
    %token <value> CHRLIT DECIMAL NATURAL RESERVED ID 

    %type <no> Program FunctionsAndDeclarations FunctionDefinition FunctionBody StatementList DeclarationsAndStatements  FunctionDeclaration FunctionDeclarator ParameterList ParameterListAux ParameterDeclaration Declaration  StatementAux  
    %type <no> TypeSpec  Declarator DeclaratorAux Statement Expr IDToken ExprAux  FunctionsAndDeclarationsList ExprAuxAux

    
    
    %left SEMI
    %left COMMA
    %right ASSIGN
    %left OR
    %left AND
    %left BITWISEOR
    %left BITWISEXOR
    %left BITWISEAND
    %left EQ NE
    %left GE GT LE LT
    %left PLUS MINUS
    %left MUL DIV MOD
    %right NOT
    %nonassoc NO_ELSE
    %nonassoc ELSE
    %left MAX_PREC



    
%%
Program: FunctionsAndDeclarations { if (debug) printf("Program \n"); $$ = create("Program", "Program"); addChild($$, $1); if (!errFlag && flagTree) { printTree($$, 0); } };

FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarationsList {$$ = $1; addBrother($$, $2);} 

| FunctionDeclaration FunctionsAndDeclarationsList {$$ = $1; addBrother($$, $2);} 
| Declaration FunctionsAndDeclarationsList {if (!$1) {$$ = $2;} else {$$ = $1; addBrother($$, $2);}} ;

FunctionsAndDeclarationsList: FunctionsAndDeclarations {$$ = $1;} 
| {$$ = NULL;} ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody { if (debug) printf("Function Definition\n"); $$ = create("FuncDefinition", ""); addChild($$, $1); addChild($$, $2); if ($3) { addChild($$, $3); } else { addChild($$, create("FuncBody", "")); } };

FunctionBody: LBRACE DeclarationsAndStatements RBRACE { if (debug) printf("Function Body\n"); $$ = create("FuncBody", ""); addChild($$, $2);  } 
| LBRACE RBRACE {$$ = create("FuncBody", "");};

DeclarationsAndStatements: Statement DeclarationsAndStatements {if (!$1) {$$ = $2;} else {$$ = $1; addBrother($$, $2);}} 
| Declaration DeclarationsAndStatements {if (!$1) {$$ = $2;} else {$$ = $1; addBrother($$, $2);}} 
| Statement {$$ = $1;} 
| Declaration {$$ = $1;} ;

FunctionDeclaration: TypeSpec FunctionDeclarator RBRACE { if (debug) printf("Function Declaration\n"); $$ = create("FuncDeclaration", ""); addChild($$, $1); addChild($$, $2); } 
| TypeSpec FunctionDeclarator SEMI { if (debug) printf("Function Declarationt\n"); $$ = create("FuncDeclaration", ""); addChild($$, $1); addChild($$, $2); };

FunctionDeclarator: IDToken LPAR ParameterList RPAR { if (debug) printf("Function Declarator\n"); addBrother($$, $3); };

ParameterList: ParameterListAux { if (debug) printf("Parameter List\n"); $$ = create("ParamList", ""); addChild($$, $1); };

ParameterListAux: ParameterDeclaration COMMA ParameterListAux { if (debug) printf("Parameter List\n"); $$ = create("X", ""); addBrother($$, $1); addBrother($$, $3); } 
| ParameterDeclaration { if (debug) printf("Empty Parameter List\n"); $$ = $1; };

ParameterDeclaration: TypeSpec ID { if (debug) printf("Parameter Declaration ID:%s\n",$2); $$ = create("ParamDeclaration", ""); addChild($$, $1); addChild($$, create("Identifier", $2)); } 
| TypeSpec { if (debug) printf("Empty Parameter Declaration\n"); $$ = create("ParamDeclaration", ""); addChild($$, $1); };

Declaration: TypeSpec DeclaratorAux SEMI { if (debug) printf("Declaration4\n"); if($2) { aux = $2; while(aux) { aux1 = create($1->type,""); aux2 = aux->child; aux->child = aux1; aux1->brother = aux2; aux = aux->brother; } } $$ = $2; } 
| error SEMI { $$ = NULL; errorflag = 1; };

DeclaratorAux: DeclaratorAux COMMA Declarator{ if($1) { aux = $1; while(aux->brother) aux = aux->brother; if($3) aux->brother = addChild(create("Declaration",""), $3); $$ = $1; } else if($3) {$$ = $3;} else {$$ = NULL;} } 
| Declarator { if($1) { aux = create("Declaration",""); $$ = addChild(aux, $1); } else {$$ = NULL;} };

TypeSpec: CHAR { if (debug) printf("Type: char\n"); $$ = create("Char", ""); } 
| INT { if (debug) printf("Type: int\n"); $$ = create("Int", ""); } 
| VOID { if (debug) printf("Type: void\n"); $$ = create("Void", ""); } 
| SHORT { if (debug) printf("Type: short\n"); $$ = create("Short", ""); } 
| DOUBLE { if (debug) printf("Type: double\n"); $$ = create("Double", ""); };

Declarator: IDToken {$$ = $1;} 
| IDToken ASSIGN ExprAux {$1->brother = $3; $$ = $1;} ;

Statement: LBRACE StatementList RBRACE { $$ = $2; if (debug && $2) printf("Statlist\n"); else if (debug) printf("Compound Stat\n"); if ($2 && $2->brother) { $$ = create("StatList", ""); $$ = addChild($$, $2); } else if ($2) { $$ = $2; } } 
| IF LPAR ExprAux RPAR StatementAux %prec NO_ELSE { if (debug) printf("If Statement\n"); $$ = create("If", ""); addChild($$, $3); if ($5 != NULL) addChild($$, $5); else addChild($$, create("Null","")); addChild($$, create("Null","")); } 
| IF LPAR ExprAux RPAR StatementAux ELSE StatementAux { if (debug) printf("If-Else Statement\n"); $$ = create("If", ""); addChild($$, $3); if ($5 != NULL) addChild($$, $5); else addChild($$, create("Null","")); if ($7 != NULL) addChild($$, $7); else addChild($$, create("Null","")); } 
| WHILE LPAR ExprAux RPAR Statement { if (debug) printf("While Loop\n"); $$ = create("While", ""); addChild($$, $3); if ($5 != NULL) addChild($$, $5); else addChild($$, create("Null",""));} 
| RETURN SEMI { if (debug) printf("Return Statement\n"); $$ = create("Return", ""); addChild($$, create("Null","")); } 
| RETURN ExprAux SEMI { if (debug) printf("Return Statement with Value\n"); $$ = create("Return", ""); addChild($$, $2); } 
| ExprAux SEMI { if (debug) printf("Expression Statement\n"); $$ = $1; } 
| LBRACE RBRACE { $$ = NULL; } 
| LBRACE error RBRACE { $$ = create("Null1", ""); } 
| SEMI { $$ = NULL; errorflag = 1; } ;
;

StatementList: StatementAux StatementList { if (debug) printf("Stat + StatList\n"); if ($1) { $$ = $1; if ($2) { aux = $$; while (aux->brother) aux = aux->brother; aux->brother = $2; } } else { $$ = $2; } } 
| StatementAux {$$ = $1;} ;

StatementAux: Statement { $$ = $1; } 
| error SEMI { $$ = NULL; errorflag = 1; };
Expr: Expr ASSIGN Expr { if (debug) printf("Store\n"); $$ = create("Store", ""); addChild($$, $1); addChild($$, $3); } 
| Expr PLUS Expr { if (debug) printf("Addition\n"); $$ = create("Add", ""); addChild($$, $1); addChild($$, $3); } 
| Expr MINUS Expr { if (debug) printf("Subtraction\n"); $$ = create("Sub", ""); addChild($$, $1); addChild($$, $3); } 
| Expr MUL Expr { if (debug) printf("Multiplication\n"); $$ = create("Mul", ""); addChild($$, $1); addChild($$, $3); } 
| Expr DIV Expr { if (debug) printf("Division\n"); $$ = create("Div", ""); addChild($$, $1); addChild($$, $3); } 
| Expr MOD Expr { if (debug) printf("Modulo\n"); $$ = create("Mod", ""); addChild($$, $1); addChild($$, $3); } 
| Expr OR Expr { if (debug) printf("Logical OR\n"); $$ = create("Or", ""); addChild($$, $1); addChild($$, $3); } 
| Expr AND Expr { if (debug) printf("Logical AND\n"); $$ = create("And", ""); addChild($$, $1); addChild($$, $3); } 
| Expr BITWISEAND Expr { if (debug) printf("Bitwise AND\n"); $$ = create("BitWiseAnd", ""); addChild($$, $1); addChild($$, $3); } 
| Expr BITWISEOR Expr { if (debug) printf("Bitwise OR\n"); $$ = create("BitWiseOr", ""); addChild($$, $1); addChild($$, $3); } 
| Expr BITWISEXOR Expr { if (debug) printf("Bitwise XOR\n"); $$ = create("BitWiseXor", ""); addChild($$, $1); addChild($$, $3); } 
| Expr EQ Expr { if (debug) printf("Equal\n"); $$ = create("Eq", ""); addChild($$, $1); addChild($$, $3); } 
| Expr NE Expr { if (debug) printf("Not Equal\n"); $$ = create("Ne", ""); addChild($$, $1); addChild($$, $3); } 
| Expr LE Expr { if (debug) printf("Less Than or Equal\n"); $$ = create("Le", ""); addChild($$, $1); addChild($$, $3); } 
| Expr GE Expr { if (debug) printf("Greater Than or Equal\n"); $$ = create("Ge", ""); addChild($$, $1); addChild($$, $3); } 
| Expr LT Expr { if (debug) printf("Less Than\n"); $$ = create("Lt", ""); addChild($$, $1); addChild($$, $3); } 
| Expr GT Expr { if (debug) printf("Greater Than\n"); $$ = create("Gt", ""); addChild($$, $1); addChild($$, $3); } 
| PLUS Expr %prec MAX_PREC { if (debug) printf("Unary Plus\n"); $$ = create("Plus", ""); addChild($$, $2); } 
| MINUS Expr %prec MAX_PREC { if (debug) printf("Unary Minus\n"); $$ = create("Minus", ""); addChild($$, $2); } 
| NOT Expr %prec MAX_PREC { if (debug) printf("Logical NOT\n"); $$ = create("Not", ""); addChild($$, $2); } 
| ID LPAR Expr ExprAuxAux RPAR { if (debug) printf("CALL w stuff\n"); $$ = create("Call", ""); addChild($$, create("Identifier", $1)); addChild($$, $3); addChild($$, $4); } 
| ID LPAR RPAR { if (debug) printf("Call wo stuff\n"); $$ = create("Call", ""); aux = create("Identifier", $1); addChild($$, aux); } 
| ID { if (debug) printf("Identifier (%s)\n", $1); $$ = create("Identifier", $1); } 
| NATURAL { if (debug) printf("Natural: %s\n", $1); $$ = create("Natural", $1); } 
| CHRLIT { if (debug) printf("Char Literal: %s\n", $1); $$ = create("ChrLit", $1); } 
| DECIMAL { if (debug) printf("Decimal: %s\n", $1); $$ = create("Decimal", $1); } 
| LPAR ExprAux RPAR { $$ = $2; } 
| LPAR error RPAR { $$ = NULL; errorflag = 1; }
| ID LPAR error RPAR {$$ = NULL;};


ExprAux: ExprAux COMMA Expr { if (debug) printf("Comma\n"); $$ = create("Comma", ""); addChild($$, $1); addChild($$, $3); } 
| Expr { if (debug) printf("Expr from ExprAux\n"); $$ = $1; } ;


ExprAuxAux: COMMA Expr ExprAuxAux {$$ = $2; addBrother($$, $3);}
| {$$ = NULL;};


IDToken: ID { if(debug) printf("Identifier (%s)\n", $1); $$ = create("Identifier", $1); }

%%


