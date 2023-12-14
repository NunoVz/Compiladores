#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "funcoes.h"
#include <stdbool.h>
#ifndef SYMTABLE_H
#define SYMTABLE_H


typedef struct noTab
{
    char * id;
    char * type;
    char *params;
    bool isDeclaration;
    struct noTab * next;
}noTab;

typedef struct tab
{
    char *name;
    char *type;
    int params;
    int def;
    bool isDeclaration;
    noTab * table;
    struct tab *next;
}tab;

void createglobal();
char* toLowerCase(const char* str);
void insert(tab *table, char *id, char *type, char *params, bool decl);
noTab *findNoTab(tab *tabletosearch, const char *id,const char *type);
tab *findTable(tab *globalTable, const char *tableName);

void printTable(tab *table);
void printGlobalTable();
#endif