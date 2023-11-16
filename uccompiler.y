%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"
    #include "funcoes.h"



    extern int yylex(void);
    void yyerror(char * s);
    extern char *yytext;
    int debug =0;
    bool errorflag=false;

    bool flagTree=false;                //-t

    no root;
	no aux;
	no aux1;
	no aux2;
    extern int l , c;


%}
%union{
    char *value;
   	struct node *no;
}

    %token <value> RESERVED IF INT SHORT DOUBLE CHAR ELSE WHILE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI 
    %token <value> ID NATURAL DECIMAL CHRLIT
    %type <no> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements StatementOrDeclaration FunctionDeclaration FunctionDeclarator ParameterList ParameterListAux ParameterDeclaration Declaration StatementAux
    %type <no> TypeSpec  Declarator DeclaratorAux Statement Expr


    
    /* https://docs.oracle.com/javase%2Ftutorial%2F/java/nutsandbolts/operators.html */ 

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

Program: FunctionsAndDeclarations {
    if (debug)
        printf("Program\n");

    if ($1) {
        root = create("Program", "");
        addChild(root, $1);
        $$ = root;
    } else {
        $$ = NULL;
    }
};

FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarations {
                          $$ = $1;
                      }
                      | FunctionDeclaration FunctionsAndDeclarations {
                            if (debug)
                                printf("Function Declaration\n");
                            $$ = create("FuncDeclaration", "");
                            addChild($$, $1);
                            addBrother($$, $2);
                        }
                      | Declaration FunctionsAndDeclarations {
                            if (debug)
                                printf("Declaration\n");
                            $$ = create("Declaration", "");
                            addChild($$, $1);
                            addBrother($$, $2);
                        }
                      | {
                            if (debug)
                                printf("Empty\n");
                            $$ = NULL;
                        };

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {
                      if (debug)
                          printf("Function Definition\n");
                      $$ = create("FuncDefinition", "");
                      addChild($$, $1);
                      addChild($$, $2);
                      addChild($$, $3);
                  };

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {
                 if (debug)
                     printf("Function Body\n");
                 $$ = create("FuncBody", "");
                 addChild($$, $2);
             };

DeclarationsAndStatements: StatementOrDeclaration DeclarationsAndStatements {
                            if (debug)
                                printf("Declarations and Statements\n");
                        }
                        | {
                            if (debug)
                                printf("Empty\n");
                        };

StatementOrDeclaration: Statement {
                           if (debug)
                               printf("Statement\n");
                       }
                     | Declaration {
                           if (debug)
                               printf("Declaration\n");
                       };

FunctionDeclaration: TypeSpec FunctionDeclarator RBRACE {
                       if (debug)
                           printf("Function Declaration\n");
                   };


FunctionDeclarator: ID LPAR ParameterList RPAR {
                      if (debug)
                          printf("Function Declarator\n");
                  };

ParameterList: ParameterDeclaration ParameterListAux {
                   if (debug)
                       printf("Parameter List\n");
               }
               | {
                     if (debug)
                         printf("Empty\n");
                 };

ParameterListAux: COMMA ParameterDeclaration ParameterListAux {
                   if (debug)
                       printf("Parameter List\n");
               }
               | {
                     if (debug)
                         printf("Empty\n");
                 };


ParameterDeclaration: TypeSpec ID {
                        if (debug)
                            printf("Parameter Declaration\n");
                    }
                  | TypeSpec {
                        if (debug)
                            printf("Empty Parameter Declaration\n");
                    };

Declaration: TypeSpec Declarator SEMI {
                 if (debug)
                     printf("Declaration\n");
             }
           | error SEMI {
                 $$ = NULL;
                 errorflag = 1;
             };

TypeSpec: CHAR {
               if (debug)
                   printf("Type: char\n");
           }
         | INT {
               if (debug)
                   printf("Type: int\n");
           }
         | VOID {
               if (debug)
                   printf("Type: void\n");
           }
         | SHORT {
               if (debug)
                   printf("Type: short\n");
           }
         | DOUBLE {
               if (debug)
                   printf("Type: double\n");
           };

Declarator: ID DeclaratorAux {
                if (debug)
                    printf("Declarator\n");
            };

DeclaratorAux: ASSIGN Expr {
                if (debug)
                    printf("Declarator\n");
            }
            | {
                if (debug)
                    printf("Empty Declarator\n");
            };


Statement: LBRACE DeclarationsAndStatements RBRACE {
               if (debug)
                   printf("Compound Statement\n");
           }
         | IF LPAR Expr RPAR StatementAux {
               if (debug)
                   printf("If Statement\n");
           }
         | IF LPAR Expr RPAR StatementAux ELSE StatementAux {
               if (debug)
                   printf("If-Else Statement\n");
           }
         | WHILE LPAR Expr RPAR StatementAux {
               if (debug)
                   printf("While Loop\n");
           }
         | RETURN SEMI {
               if (debug)
                   printf("Return Statement\n");
           }
         | RETURN Expr SEMI {
               if (debug)
                   printf("Return Statement with Value\n");
           }
         | Expr SEMI {
               if (debug)
                   printf("Expression Statement\n");
           };

StatementAux: Statement {
                 $$ = $1;
             }
             | SEMI {
                 $$ = NULL;
                 errorflag = 1;
             };

Expr: Expr ASSIGN Expr {
         if (debug)
             printf("Assign\n");
     }
     | Expr COMMA Expr {
         if (debug)
             printf("Comma\n");
     }
     | Expr PLUS Expr {
         if (debug)
             printf("Addition\n");
     }
     | Expr MINUS Expr {
         if (debug)
             printf("Subtraction\n");
     }
     | Expr MUL Expr {
         if (debug)
             printf("Multiplication\n");
     }
     | Expr DIV Expr {
         if (debug)
             printf("Division\n");
     }
     | Expr MOD Expr {
         if (debug)
             printf("Modulo\n");
     }
     | Expr OR Expr {
         if (debug)
             printf("Logical OR\n");
     }
     | Expr AND Expr {
         if (debug)
             printf("Logical AND\n");
     }
     | Expr BITWISEAND Expr {
         if (debug)
             printf("Bitwise AND\n");
     }
     | Expr BITWISEOR Expr {
         if (debug)
             printf("Bitwise OR\n");
     }
     | Expr BITWISEXOR Expr {
         if (debug)
             printf("Bitwise XOR\n");
     }
     | Expr EQ Expr {
         if (debug)
             printf("Equal\n");
     }
     | Expr NE Expr {
         if (debug)
             printf("Not Equal\n");
     }
     | Expr LE Expr {
         if (debug)
             printf("Less Than or Equal\n");
     }
     | Expr GE Expr {
         if (debug)
             printf("Greater Than or Equal\n");
     }
     | Expr LT Expr {
         if (debug)
             printf("Less Than\n");
     }
     | Expr GT Expr {
         if (debug)
             printf("Greater Than\n");
     }
     | PLUS Expr {
         if (debug)
             printf("Unary Plus\n");
     }
     | MINUS Expr {
         if (debug)
             printf("Unary Minus\n");
     }
     | NOT Expr {
         if (debug)
             printf("Logical NOT\n");
     }
     | ID LPAR RPAR {
         if (debug)
             printf("Function Call with Empty Parameters\n");
     }
     | ID {
         if (debug)
             printf("Identifier\n");
     }
     | NATURAL {
         if (debug)
             printf("Natural: \n");
     }
     | CHRLIT {
         if (debug)
             printf("Char Literal: \n");
     }
     | DECIMAL {
         if (debug)
             printf("Decimal: \n");
     }
     | LPAR Expr RPAR {
         $$ = $2;
     }
     | ID LPAR error RPAR {
        $$ = NULL;
         errorflag = true;
     }
     | LPAR error RPAR {
         $$ = NULL;
         errorflag = true;
     };

%%

void yyerror (char *error) {
    printf("Line %d, column %d: %s: %s\n", l, c-1 - (int)strlen(yytext) + 1, error, yytext);
}
