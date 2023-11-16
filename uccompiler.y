%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"


    extern int yylex(void);
    void yyerror(char * s);
    extern char *yytext;
    int debug =1;

    bool flagTree=false;                //-t

    /* https://docs.oracle.com/javase%2Ftutorial%2F/java/nutsandbolts/operators.html */ 

%}

    %token RESERVED IF INT SHORT DOUBLE CHAR ELSE WHILE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI NATURAL DECIMAL ID CHRLIT
    /* %type<node> FunctionAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclartion FunctionDeclarator ParameterList ParameterDeclaration Declaration TypeSpec Declarator Statement */ 

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
    %left RPAR
    %right LPAR
    %right ELSE


    
%%
Program: FunctionsAndDeclarations
       ;

FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarations
                      | FunctionDeclaration FunctionsAndDeclarations
                      | Declaration FunctionsAndDeclarations
                      |
                      ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody
                 ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE
            ;

DeclarationsAndStatements: StatementOrDeclaration DeclarationsAndStatements
                       | 
                       ;

StatementOrDeclaration: Statement
                    | Declaration
                    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI
                  ;

FunctionDeclarator: ID LPAR ParameterList RPAR
                 ;

ParameterList: ParameterDeclaration COMMA ParameterList
             | ParameterDeclaration
             | 
             ;

ParameterDeclaration: TypeSpec ID
                   | TypeSpec
                   ;

Declaration: TypeSpec Declarator SEMI
           ;

TypeSpec: CHAR
        | INT
        | VOID
        | SHORT
        | DOUBLE
        ;

Declarator: ID
          | ID ASSIGN Expr
          ;

Statement: LBRACE DeclarationsAndStatements RBRACE
         | IF LPAR Expr RPAR Statement
         | IF LPAR Expr RPAR Statement ELSE Statement
         | WHILE LPAR Expr RPAR Statement
         | RETURN SEMI
         | RETURN Expr SEMI
         | Expr SEMI
         ;

Expr: Expr ASSIGN Expr              { if (debug) printf("Assign\n"); }
    | Expr COMMA Expr               { if (debug) printf("Comma\n"); }
    | Expr PLUS Expr                { if (debug) printf("Addition\n"); }
    | Expr MINUS Expr               { if (debug) printf("Subtraction\n"); }
    | Expr MUL Expr                 { if (debug) printf("Multiplication\n"); }
    | Expr DIV Expr                 { if (debug) printf("Division\n"); }
    | Expr MOD Expr                 { if (debug) printf("Modulo\n"); }
    | Expr OR Expr                  { if (debug) printf("Logical OR\n"); }
    | Expr AND Expr                 { if (debug) printf("Logical AND\n"); }
    | Expr BITWISEAND Expr          { if (debug) printf("Bitwise AND\n"); }
    | Expr BITWISEOR Expr           { if (debug) printf("Bitwise OR\n"); }
    | Expr BITWISEXOR Expr          { if (debug) printf("Bitwise XOR\n"); }
    | Expr EQ Expr                  { if (debug) printf("Equal\n"); }
    | Expr NE Expr                  { if (debug) printf("Not Equal\n"); }
    | Expr LE Expr                  { if (debug) printf("Less Than or Equal\n"); }
    | Expr GE Expr                  { if (debug) printf("Greater Than or Equal\n"); }
    | Expr LT Expr                  { if (debug) printf("Less Than\n"); }
    | Expr GT Expr                  { if (debug) printf("Greater Than\n"); }
    | PLUS Expr                     { if (debug) printf("Unary Plus\n"); }
    | MINUS Expr                    { if (debug) printf("Unary Minus\n"); }
    | NOT Expr                      { if (debug) printf("Logical NOT\n"); }
    | ID LPAR COMMA RPAR          { if (debug) printf("Function Call\n"); }
    | ID                            { if (debug) printf("Identifier\n" ); }
    | NATURAL                       { if (debug) printf("Natural: \n" ); }
    | CHRLIT                        { if (debug) printf("Char Literal: \n" ); }
    | DECIMAL                       { if (debug) printf("Decimal: \n"); }
    | LPAR Expr RPAR                { }
    ;


%%

void yyerror(char *error) {
    printf("%s '%s'\n", error, yytext);
}
