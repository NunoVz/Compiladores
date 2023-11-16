#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estruturas.h"

int linha, coluna;
char *yytext;

no insert(char type, no *filho){
    no *novo = (no *)malloc(sizeof(no));
    novo->irmao = NULL;
    novo->tipo = strdup(type);
    novo->anotacao = NULL

    if(strcmp(novo->tipo, "Call") == 0){
        novo->linha = filho->linha;
        novo->coluna = filho->coluna;
    }
    else{
        novo->linha = linha;
        new->coluna = (int)(coluna - strlen(yytext));
    }

    novo->filho = filho;

    return novo;
}