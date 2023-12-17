#include "funcoes.h"
#include "symtable.h"
#include <ctype.h>

tab *global;

void createglobal(){
        global = (tab *)malloc(sizeof(tab));
        global->type = strdup("Global");
        global->name = strdup("");
        global->next = NULL;
        global->table = NULL;
        global->isDeclaration = false;
        insert(global, "putchar", "int", "(int)",false);
        insert(global, "getchar", "int", "(void)",false);
}
char* toLowerCase(const char* str) {
    size_t len = strlen(str);

    char* result = (char*)malloc(len + 1);

    if (result == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        result[i] = (char)tolower((unsigned char)str[i]);
    }

    result[len] = '\0';

    return result;
}

void insert(tab *table, char *id, char *type, char *params, bool decl) {
    noTab *newEntry = (noTab *)malloc(sizeof(noTab));
    newEntry->id = strdup(id);
    newEntry->type = strdup(type);
    newEntry->params = strdup(params);
    newEntry->next = NULL;
    newEntry->isDeclaration=decl;
    if (table->table == NULL) {
        table->table = newEntry;
    } else {
        noTab *lastEntry = table->table;
        while (lastEntry->next != NULL) {
            lastEntry = lastEntry->next;
        }
        lastEntry->next = newEntry;
    }
}

noTab *findNoTab(tab *tabletosearch, const char *id) {
    tab *globalTable = tabletosearch;
    if (globalTable != NULL) {
        noTab *currentNode = globalTable->table;

        while (currentNode != NULL) {

            if (strcmp(currentNode->id, id) == 0) {


                return currentNode;  
            } 
            currentNode = currentNode->next;
        }

    }


    return NULL;
}

tab *findTable(tab *globalTable, const char *tableName) {
    tab *currentTable = globalTable->next;
    while (currentTable != NULL) {

        if (strcmp(currentTable->name, tableName) == 0) {
            return currentTable;
        }
        currentTable = currentTable->next;
    }
    return NULL; 
}

tab *findFunc(tab* globalTable, const char* id) {
    tab* currentTable = globalTable->next;

    while (currentTable != NULL) {
        noTab* currentNode = currentTable->table;

        // Search in the current table's noTab list
        while (currentNode != NULL) {
            if (strcmp(currentNode->id, id) == 0) {
                // If id is found, return the current table
                return currentTable;
            }
            currentNode = currentNode->next;
        }

        // Move to the next table in the global table list
        currentTable = currentTable->next;
    }

    // If no match is found, return NULL
    return NULL;
}






void printTable(tab *table) {
    noTab *currentEntry = table->table;

    if (currentEntry == NULL || table->isDeclaration) {
        return;
    }
    if (strcmp(table->type, "Global") == 0)
        printf("===== %s Symbol Table =====\n", table->type);
    else
        printf("===== Function %s Symbol Table =====\n",table->name);
    while (currentEntry != NULL) {
        if (strcmp(table->type, "Global") == 0)
        printf("%s\t%s%s\n", currentEntry->id, toLowerCase(currentEntry->type), toLowerCase(currentEntry->params));
        else{
        if (strcmp(currentEntry->params, "") != 0)
            printf("%s\t%s\t%s\n", currentEntry->id, toLowerCase(currentEntry->type), toLowerCase(currentEntry->params));
        else
            printf("%s\t%s\n", currentEntry->id, toLowerCase(currentEntry->type));

        
        }
        currentEntry = currentEntry->next;
    }
    printf("\n");
}

void printGlobalTable() {
    tab *currentTable = global;
    while (currentTable != NULL) {
        if (currentTable->table != NULL) {
            printTable(currentTable);
        }
        currentTable = currentTable->next;
    }
}
