#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "funcoes.h"
#ifndef SYMTABLE_H
#define SYMTABLE_H


typedef struct noTab
{
    char * id;
    char * type;
    char *params;
    struct noTab * next;
}noTab;

typedef struct tab
{
    char *name;
    char *type;
    int params;
    int def;
    noTab * table;
    struct tab *next;
}tab;

void enterScope(char *name, char *type, int params);
void exitScope();
void buildSymbolTable(no root);
void insert(tab *table, char *id, char* type, char *params);
void printTable(tab *table);
void printGlobalTable();
#endif