#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "funcoes.h"
#include "symtable.h"

#include <stdbool.h>
#ifndef SEMANTIC_H
#define SEMANTIC_H

extern tab *global;


void funcDef(no toadd);
void decl(no toadd);
void funcDecl(no toadd);
void buildSymbolTable(no root);
void checkBody(tab *table, no toadd,char* ftype);
void checkStat(tab *table,no toadd, char *ftype);
char *checkExpr(tab *table,no toadd);
void *checkRet(tab *table,no toadd);
void checkCall(tab table,no toadd);
char *operatores(char *str);
#endif