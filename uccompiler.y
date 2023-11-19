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
    int debug =1;
    bool errorflag=false;
    int errFlag= 0;

    bool flagTree=false;                //-t

    no root;
	no aux;
	no aux1;
	no aux2;
    extern int l , c;
    int count =1;


%}
%union{
    char *value;
   	struct node *no;
}

    %token  RESERVED IF INT SHORT DOUBLE CHAR ELSE WHILE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI 
    %token <value> ID NATURAL DECIMAL CHRLIT
    %type <no> Program FunctionsAndDeclarations FunctionDefinition FunctionBody StatementList DeclarationsAndStatements StatementOrDeclaration FunctionDeclaration FunctionDeclarator ParameterList ParameterListAux ParameterDeclaration Declaration  StatementAux FunctionCall FuncCallAux
    %type <no> TypeSpec  Declarator DeclaratorAux Statement Expr IDToken

    
    
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

Program: FunctionsAndDeclarations {
    if (debug)
        printf("Program %d\n", count);
    $$ = create("Program", "Program");
    addChild($$, $1);
    if (!errFlag) {
            printTree($$, 0);
        }

};

FunctionsAndDeclarations: FunctionDefinition {
    if (debug)
        printf("Function Definition\n");
    $$ = $1;
}
| FunctionDeclaration {
    if (debug)
        printf("Function Declaration\n");
    $$ = $1;
}
| Declaration {
    if (debug)
        printf("Declaration1\n");
    $$ = $1;

}
| FunctionsAndDeclarations FunctionDefinition {
    if (debug)
        printf("Function Definition\n");
    addBrother($$, $2);
}
| FunctionsAndDeclarations FunctionDeclaration {
    if (debug)
        printf("Function Declaration\n");
    addBrother($$, $2);
}
| FunctionsAndDeclarations Declaration {
    if (debug)
        printf("Declaration2\n");
    addBrother($$, $2);
};

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {
    if (debug)
        printf("Function Definition\n");
    $$ = create("FuncDefinition", "");
    addChild($$, $1); // TypeSpec
    addChild($$, $2); // FunctionDeclarator
    addChild($$, $3); // FunctionBody
};

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {
    if (debug)
        printf("Function Body\n");
     $$ = create("FuncBody", "");
    if ($2) {
        addChild($$, $2); // DeclarationsAndStatements
    }
};

DeclarationsAndStatements: StatementOrDeclaration DeclarationsAndStatements {
    if (debug)
        printf("Declarations and Statements\n");

    $$ = $1;
    addBrother($$, $2);
    
}
| SEMI DeclarationsAndStatements{
    if (debug)
        printf("Empty Declarations and Statements\n");
    $$ = NULL;
    errorflag = 1;
}
| /* empty */ {
    if (debug)
        printf("Empty Declarations and Statements\n");
    $$ = NULL;
};

StatementOrDeclaration: Statement {
    if (debug)
        printf("Statement\n");
    $$ = $1;
}
| Declaration  {
    if (debug)
        printf("Declaration3\n");
     $$ = $1;
};

FunctionDeclaration: TypeSpec FunctionDeclarator RBRACE {
    if (debug)
        printf("Function Declaration\n");
    $$ = create("FuncDeclaration", "");
    addChild($$, $1); // TypeSpec
    addChild($$, $2); // FunctionDeclarator
}
| TypeSpec FunctionDeclarator SEMI {
    if (debug)
        printf("Function Declarationt\n");
    $$ = create("FuncDeclaration", "");
    addChild($$, $1); // TypeSpec
    addChild($$, $2); // FunctionDeclarator
};

FunctionDeclarator: IDToken LPAR ParameterList RPAR {
    if (debug)
        printf("Function Declarator\n");
    addBrother($$, $3);
};

ParameterList: ParameterListAux  {
    if (debug)
        printf("Parameter List\n");
    $$ = create("ParamList", "");
    addChild($$, $1);
};

ParameterListAux: ParameterDeclaration COMMA ParameterListAux  {
    if (debug)
        printf("Parameter List\n");
    
    $$ = create("X", "");
    addBrother($$, $1);
    addBrother($$, $3);

}
| ParameterDeclaration {
    if (debug)
        printf("Empty Parameter List\n");
    $$ = $1;
};

ParameterDeclaration: TypeSpec ID {
    if (debug)
        printf("Parameter Declaration ID:%s\n",$2);
    $$ = create("ParamDeclaration", "");
    addChild($$, $1); // TypeSpec
    addChild($$, create("Identifier", $2));
}
| TypeSpec {
    if (debug)
        printf("Empty Parameter Declaration\n");
    $$ = create("ParamDeclaration", "");
    addChild($$, $1); // TypeSpec
};

Declaration: TypeSpec DeclaratorAux  SEMI {
    if (debug)
        printf("Declaration4\n");
    if($2) {
             aux = $2;
            while(aux) {
                aux1 = create($1->type,"");
                aux2 = aux->child;
                aux->child = aux1;
                aux1->brother = aux2;
                aux = aux->brother;
            }
        }
        $$ = $2;
}
| error SEMI {
    $$ = NULL;
    errorflag = 1;
};

DeclaratorAux: DeclaratorAux COMMA Declarator{
    if($1) {
        aux = $1;
        while(aux->brother) aux = aux->brother;
        if($3) aux->brother = addChild(create("Declaration",""), $3);
        $$ = $1;
    }
    else if($3) {$$ = $3;}
    else {$$ = NULL;}
}
|Declarator
{
    if($1) {
            aux = create("Declaration","");
            $$ = addChild(aux, $1);
        }
        else {$$ = NULL;}

};



TypeSpec: CHAR {
    if (debug)
        printf("Type: char\n");
    $$ = create("Char", "");
}
| INT {
    if (debug)
        printf("Type: int\n");
    $$ = create("Int", "");
}
| VOID {
    if (debug)
        printf("Type: void\n");
    $$ = create("Void", "");
}
| SHORT {
    if (debug)
        printf("Type: short\n");
    $$ = create("Short", "");
}
| DOUBLE {
    if (debug)
        printf("Type: double\n");
    $$ = create("Double", "");
};

Declarator:  IDToken             {$$ = $1;}
          |  IDToken ASSIGN Expr {$1->brother = $3; $$ = $1;}
          ;
Statement: LBRACE StatementList  RBRACE {
    $$ = $2;

    if (debug && $2)
        printf("Statlist\n");
    else if (debug)
        printf("Compound Stat\n");

    if ($2 && $2->brother) {
        $$ = create("StatList", "");
        $$ = addChild($$, $2);
    } else if ($2) {
        $$ = $2;
    } else {
        $$ = create("Null1", ""); // Handle the case of an empty statement
    }
}
| IF LPAR Expr RPAR StatementAux %prec NO_ELSE {
    if (debug)
        printf("If Statement\n");
     $$ = create("If", "");
    addChild($$, $3); // Expr
    if ($5 != NULL) addChild($$, $5); 
    else addChild($$, create("Null2",""));
    addChild($$,  create("Null3","")); // StatementAux
}
| IF LPAR Expr RPAR StatementAux ELSE StatementAux {
    if (debug)
        printf("If-Else Statement\n");
    $$ = create("If", "");
    addChild($$, $3); // Expr
    if ($5 != NULL) addChild($$, $5); 
    else addChild($$, create("Null4",""));

    if ($7 != NULL) addChild($$, $7); 
    else addChild($$, create("Null5",""));
}
| WHILE LPAR Expr RPAR StatementAux {
    if (debug)
        printf("While Loop\n");
    $$ = create("While", "");
    addChild($$, $3); // Expr
    addChild($$, $5); // StatementAux
}
| RETURN SEMI {
    if (debug)
        printf("Return Statement\n");
     $$ = create("Return", "");
    addChild($$, create("Null6",""));
}
| RETURN Expr SEMI {
    if (debug)
        printf("Return Statement with Value\n");
    $$ = create("Return", "");
    addChild($$, $2); // Expr
}
| Expr SEMI {
    if (debug)
        printf("Expression Statement\n");
     $$ = $1;
}
| LBRACE error RBRACE {
    $$ = create("Null7", "");


};

StatementList: 
   StatementAux StatementList  {
    if (debug)
        printf("Stat + StatList\n");
                                                if ($1) {
                                                    $$ = $1;
                                                    if ($2) {
                                                        aux = $$;
                                                        while (aux->brother) aux = aux->brother;
                                                        aux->brother = $2;
                                                    }
                                                } else {
                                                    $$ = $2;
                                                }
                                             }
             | StatementAux                {$$ = $1;}
            ;

StatementAux: Statement {
    $$ = $1;
}
| error SEMI {
    $$ = NULL;
    errorflag = 1;
}
| SEMI {
 
    $$ = create("Null9", "");

}
| LBRACE  RBRACE {
    $$ = create("Null9", "");
}
;

FunctionCall: ID LPAR RPAR {
    if (debug)
        printf("FuncCall ID:%s\n",$1);
    $$ = create("Call", "");
    addChild($$, create("Identifier", $1));
}
| ID LPAR FuncCallAux RPAR {
    if (debug)
        printf("FuncCall ID:%s\n",$1);
    $$ = create("Call", "");
    addChild($$, create("Identifier",$1));
    addChild($$, $3); // FuncCallAux
}
| ID LPAR error RPAR {
    $$ = NULL;
    errorflag = 1;
};


FuncCallAux: Expr {
    if (debug)
        printf("FuncCallAUX\n");
    $$ = $1;
}
| FuncCallAux COMMA Expr {
    if (debug)
        printf("FuncCallAUXComma\n");
    
    addBrother($1, $3); 
};


Expr: Expr ASSIGN Expr {
    if (debug)
        printf("Store\n");
     $$ = create("Store", "");
    addChild($$, $1); // Left-hand side expression
    addChild($$, $3);
}
| Expr PLUS Expr  {
    if (debug)
        printf("Addition\n");
    $$ = create("Add", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr MINUS Expr {
    if (debug)
        printf("Subtraction\n");
    $$ = create("Sub", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr MUL Expr {
    if (debug)
        printf("Multiplication\n");
    $$ = create("Mul", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr DIV Expr {
    if (debug)
        printf("Division\n");
    $$ = create("Div", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr MOD Expr {
    if (debug)
        printf("Modulo\n");
    $$ = create("Mod", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr OR Expr {
    if (debug)
        printf("Logical OR\n");
    $$ = create("Or", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr AND Expr {
    if (debug)
        printf("Logical AND\n");
    $$ = create("And", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr BITWISEAND Expr {
    if (debug)
        printf("Bitwise AND\n");
    $$ = create("BitWiseAnd", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr BITWISEOR Expr {
    if (debug)
        printf("Bitwise OR\n");
    $$ = create("BitWiseOr", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr BITWISEXOR Expr {
    if (debug)
        printf("Bitwise XOR\n");
    $$ = create("BitWiseXor", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr EQ Expr {
    if (debug)
        printf("Equal\n");
    $$ = create("Eq", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr NE Expr {
    if (debug)
        printf("Not Equal\n");
    $$ = create("Ne", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr LE Expr {
    if (debug)
        printf("Less Than or Equal\n");
    $$ = create("Le", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr GE Expr {
    if (debug)
        printf("Greater Than or Equal\n");
    $$ = create("Ge", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr LT Expr {
    if (debug)
        printf("Less Than\n");
    $$ = create("Lt", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| Expr GT Expr {
    if (debug)
        printf("Greater Than\n");
    $$ = create("Gt", "");
    addChild($$, $1); // Left operand
    addChild($$, $3); // Right operand
}
| LPAR Expr COMMA Expr RPAR {
        if (debug)
            printf("Comma\n");
    $$ = create("Comma", "");
    addChild($$, $2); // Left operand
    addChild($$, $4); // Right operand
    }
    
| PLUS Expr %prec MAX_PREC {
    if (debug)
        printf("Unary Plus\n");
    $$ = create("Plus", "");
    addChild($$, $2); // Operand
}
| MINUS Expr %prec MAX_PREC {
    if (debug)
        printf("Unary Minus\n");
    $$ = create("Minus", "");
    addChild($$, $2); // Operand
}
| NOT Expr %prec MAX_PREC {
    if (debug)
        printf("Logical NOT\n");
    $$ = create("Not", "");
    addChild($$, $2); // Operand
}

| FunctionCall {
    $$ = $1;
}

| ID {
    if (debug)
        printf("Identifier (%s)\n", $1);
    $$ = create("Identifier", $1);
}
| NATURAL {
    if (debug)
        printf("Natural: %s\n", $1);
    $$ = create("Natural", $1);
}
| CHRLIT {
    if (debug)
        printf("Char Literal: %s\n", $1);
    $$ = create("ChrLit", $1);
}
| DECIMAL {
    if (debug)
        printf("Decimal: %s\n", $1);
    $$ = create("Decimal", $1);
}

| LPAR Expr RPAR {
    $$ = $2; // Parenthesized expression
}
| LPAR error RPAR {
    $$ = NULL;
    errorflag = 1;
};

IDToken: ID {
    if(debug)
        printf("Identifier (%s)\n", $1); 
    $$ = create("Identifier", $1); }

%%

void yyerror (char *error) {
    printf("Line %d, column %d: %s: %s\n", l, c - (int)strlen(yytext) , error, yytext);
    errFlag=1;
}
