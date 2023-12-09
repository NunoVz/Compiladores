#include "funcoes.h"
#include "symtable.h"
#include <ctype.h>

tab *global;


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}


void insert(tab *table, char *id, char *type, char *params) {



    noTab *newEntry = (noTab *)malloc(sizeof(noTab));
    newEntry->id = strdup(id);
    newEntry->type = strdup(type);
    newEntry->params = strdup(params);
    newEntry->next = NULL;

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

void buildSymbolTable(no toadd) {

    if (toadd == NULL) {
        return;
    }

    if (strcmp(toadd->type, "Program") == 0){
        global = (tab *)malloc(sizeof(tab));
        global->type = strdup("Global");
        global->name = strdup("");
        global->next = NULL;
        global->table = NULL;
        insert(global, "putchar", "int", "int");
        insert(global, "getchar", "int", "void");
    }
    else if (strcmp(toadd->type, "FuncDefinition") == 0) {

        char *name = toadd->child->brother->infor;  
        char *type = toadd->child->type;           
        toLowerCase(name);
        toLowerCase(type);
        tab *auxtab= (tab *)malloc(sizeof(tab));
        auxtab->type = strdup("Function");
        auxtab->name = strdup(name);
        auxtab->next = NULL;
        auxtab->table = NULL;
        insert(auxtab, "return", type, "");
        no paramNode = toadd->child->brother->brother->child;
        char* paramsString = strdup(""); 
        while (paramNode != NULL) {

            if(paramNode->child != NULL){
                char *paramType = paramNode->child->type; 
                toLowerCase(paramType);  
                char *temp = (char *)malloc(strlen(paramsString) + strlen(paramType) + 3); 
                sprintf(temp, "%s%s,", paramsString, paramType);
                free(paramsString); 
                paramsString = temp;

                if(paramNode->child->brother!= NULL){
                    char *paramName = paramNode->child->brother->infor; 
                    insert(auxtab, paramName, paramType, "param");
                }
               
            }
            paramNode = paramNode->brother;

            
        }
        if (strlen(paramsString) >= 2) {
            paramsString[strlen(paramsString) - 1] = '\0';
        }
        insert(global, name, type, paramsString);
        tab *auxadd = global;
        while (auxadd->next != NULL) {
            auxadd = auxadd->next;
        }
        auxadd->next=auxtab;

      
    } else if (strcmp(toadd->type, "Declaration") == 0) {
        char *type = toadd->child->infor;                   
        char *name = toadd->child->brother->infor;          
        char *params = "";  
        insert(global, name, type, params);
    }

  
    if(toadd->child != NULL){
        no childNode = toadd->child;
        while (childNode != NULL) {
            buildSymbolTable(childNode);
            childNode = childNode->brother;
        }
    }

  
}

void printTable(tab *table) {
    noTab *currentEntry = table->table;

    if (currentEntry == NULL) {
        printf("Empty table\n");
        return;
    }
    if (strcmp(table->type, "Global") == 0)
        printf("===== %s Symbol Table =====\n", table->type);
    else
        printf("===== %s %s Symbol Table =====\n", table->type,table->name);
    while (currentEntry != NULL) {
        if (strcmp(table->type, "Global") == 0)
        printf("%s\t%s(%s)\n", currentEntry->id, currentEntry->type, currentEntry->params);
    else
        printf("%s\t%s %s\n", currentEntry->id, currentEntry->type, currentEntry->params);
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
