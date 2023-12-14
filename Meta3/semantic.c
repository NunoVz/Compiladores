#include "semantic.h"
#include "funcoes.h"

#include <ctype.h>


no father;


void buildSymbolTable(no toadd) {

    if (toadd == NULL) {
        return;
    }

    if (strcmp(toadd->type, "Program") == 0){
        createglobal();

    }
    else if (strcmp(toadd->type, "FuncDefinition") == 0) {
        funcDef(toadd);
      
    } else if (strcmp(toadd->type, "Declaration") == 0) {
        decl(toadd);
    }else if (strcmp(toadd->type, "FuncDeclaration") == 0) {
        funcDecl(toadd);

    }

  
    if(toadd->child != NULL){
        no childNode = toadd->child;
        while (childNode != NULL) {
            father=toadd;
            buildSymbolTable(childNode);
            childNode = childNode->brother;
        }
    }

  
}

void funcDef(no toadd){
    int abortmission=1;
    char *name = toadd->child->brother->infor;  
    char *type = toadd->child->type;  

    tab *auxtab= (tab *)malloc(sizeof(tab));
    auxtab->type = strdup("Function");
    auxtab->name = strdup(name);
    auxtab->next = NULL;
    auxtab->table = NULL;
    auxtab->isDeclaration=false;

    insert(auxtab, "return", type, "",false);
    no paramNode = toadd->child->brother->brother->child;
    char* paramsString = strdup("");
    char *errorMessages = strdup(""); 
    int counter=0;
    int brothercounter=0;

    while (paramNode != NULL) {
        if(paramNode->child != NULL){
            char *paramType = paramNode->child->type; 
            char *temp = (char *)malloc(strlen(paramsString) + strlen(paramType) + 3); 
            sprintf(temp, "%s%s,", paramsString, paramType);
            free(paramsString); 
            paramsString = temp;
            if(paramNode->child->brother!= NULL && strcmp(paramType,"Void")!=0){
                
                char *paramName = paramNode->child->brother->infor; 
                insert(auxtab, paramName, paramType, "param",false);
            }else if((strcmp(paramType,"Void")==0 && paramNode->child->brother==NULL ) && brothercounter==0   ){
                
            }else if((strcmp(paramType,"Void")!=0 && paramNode->child->brother==NULL )){
                char *errorTemp = (char *)malloc(strlen(errorMessages) + 100);  
                sprintf(errorTemp,"Unexpected error: Parameter symbol required\n");                
                free(errorMessages);
                counter++;
                errorMessages = errorTemp;
            } 
            else{
                abortmission=0;
                char *errorTemp = (char *)malloc(strlen(errorMessages) + 100);  
                sprintf(errorTemp,"Line %d, collumn %d: Invalid use of void type in declaration\n", paramNode->child->line,paramNode->child->col-4);                
                free(errorMessages);
                errorMessages = errorTemp;
                break;
            }
        }
        brothercounter++;
        paramNode = paramNode->brother;
    }
    if (strlen(paramsString) >= 2) {
        paramsString[strlen(paramsString) - 1] = '\0';
    }
    noTab *existingTable = findNoTab(global,name,type);
    if (existingTable != NULL && abortmission) {
        if(strcmp(existingTable->type, type) == 0 && existingTable->isDeclaration ){
            existingTable->isDeclaration=false;
            tab *change = findTable(global,name);
            change->table=auxtab->table;
            change->isDeclaration=false;
        }
        else if(strcmp(existingTable->id, name) == 0  && !existingTable->isDeclaration){
            printf("Line %d, column %d: Symbol %s already defined\n", toadd->child->brother->line,toadd->child->col, name);
        }else{
            printf( "Line %d, column %d: Conflicting types (got %s(%s), expected %s)\n",toadd->child->line,toadd->child->col, toLowerCase(type),toLowerCase(paramsString),toLowerCase(existingTable->type));

        }
    } else {
        size_t newLength = strlen(paramsString) + 2;
        char* newParamsString = (char *)malloc(newLength);
        sprintf(newParamsString, "(%s)", paramsString);
        insert(global, name, type, newParamsString,false);
        tab *auxadd = global;
        while (auxadd->next != NULL) {
            auxadd = auxadd->next;
        }
        auxadd->next = auxtab;
        if(counter!=0){
            for (int i = 0; i < counter; i++)
            {
                printf("%s", errorMessages);
            }
            
        }else{
            printf("%s", errorMessages);
        }
    }
    free(errorMessages);

    checkBody(*auxtab,toadd->child->brother->brother->brother,toadd->child->type);
    
}

void checkCall(tab table,no toadd){

}

void checkExpr(tab table,no toadd){
    if(strcmp(toadd->type,"Call")==0){

    }else if(strcmp(toadd->type,"IntLit")==0){
        toadd->auxinfo = (char *)strdup("int");
    }else if(strcmp(toadd->type,"ChrLit")==0){
        toadd->auxinfo = (char *)strdup("int");
    }else if(strcmp(toadd->type,"RealLit")==0){
        toadd->auxinfo = (char *)strdup("double");

    }else if(strcmp(toadd->type,"Id")==0){
       


    }else if(strcmp(toadd->type,"Not")==0){

    }else if(strcmp(toadd->type,"Plus")==0 || strcmp(toadd->type,"Minus")==0){

    }else{
    }
}

void checkStat(tab table,no toadd, char *ftype){
    if(strcmp(toadd->type,"If")==0){

    }else if(strcmp(toadd->type,"While")==0){

    }else if(strcmp(toadd->type,"Return")==0){

    }else if(strcmp(toadd->type,"Statlist")==0){

    }else{
        checkExpr(table,toadd);
    }
}

void checkBody(tab table, no toadd,char* ftype){
    no aux= toadd->child;
    while (aux)
    {
        if (strcmp(aux->type,"Declaration")!=0)
        {
            checkStat(table,aux,ftype);
        }
        aux = aux->brother;
    }
    

}

void decl(no toadd){
    char *type = toadd->child->type;                   
    char *name = toadd->child->brother->infor;          
    int keepgoing=1;
    if(strcmp(type, "Void")==0){

        char error[100];
        sprintf(error, "Line %d, column %d: Invalid use of void type in declaration\n",toadd->child->line,toadd->child->col);
        printf("%s", error);
        return;
    }
    noTab *existingTable = findNoTab(global,name,type);
    if (existingTable != NULL) {
        if(strcmp(existingTable->type, type) != 0 && strcmp(father->type, "Program")==0){
            char error[100];
            sprintf(error, "Line %d, column %d: Conflicting types (got %s, expected %s)\n",toadd->child->line,toadd->child->col, type,existingTable->type);
            printf("%s", error);
            keepgoing=0;
        }
    }
    if(keepgoing){

            if(strcmp(father->type, "Program") == 0){
                insert(global, name, type, "",true);
            }
            else{
                tab *existingTable =findTable(global,father->parent->child->brother->infor);
                if (existingTable != NULL) {
                    noTab *exist= findNoTab(existingTable,name,type);
                    if(exist != NULL){
                        char error[100];
                        sprintf(error, "Line %d, column %d: Conflicting types (got %s, expected %s)\n",toadd->child->line,toadd->child->col, type,existingTable->type);
                        printf("%s", error);
                    }else
                        insert(existingTable, name, type, "",true);

                }
            }
        
        if (toadd->child->brother->brother != NULL) {
            no auxno = toadd->child->brother->brother;
            if (strcmp(auxno->type, "ChrLit") == 0 || strcmp(auxno->type, "IntLit") == 0) {
                auxno->auxinfo = (char *)strdup("int");
            } else if (strcmp(auxno->type, "RealLit") == 0) {
                auxno->auxinfo = (char *)strdup("double");
            } else {
            }
        }

        
        
    }
}



void funcDecl(no toadd){
    int abortmission=1;
    char *name = toadd->child->brother->infor;  
    char *type = toadd->child->type;           

    tab *auxtab= (tab *)malloc(sizeof(tab));
    auxtab->type = strdup("Function");
    auxtab->name = strdup(name);
    auxtab->next = NULL;
    auxtab->table = NULL;
    auxtab->isDeclaration=true;
    no paramNode = toadd->child->brother->brother->child;
    char* paramsString = strdup("");
    char *errorMessages = strdup(""); 
    int counter=0;
    int brothercounter=0;
    
    while (paramNode != NULL) {
        if(paramNode->child != NULL){
            char *paramType = paramNode->child->type; 
            char *temp = (char *)malloc(strlen(paramsString) + strlen(paramType) + 3); 
            sprintf(temp, "%s%s,", paramsString, paramType);
            free(paramsString); 
            paramsString = temp;
            
            if(paramNode->child->brother!= NULL && strcmp(paramType,"Void")!=0){             
                char *paramName = paramNode->child->brother->infor; 
                insert(auxtab, paramName, paramType, "param",true);
            }else if((strcmp(paramType,"Void")==0 && paramNode->child->brother==NULL ) && brothercounter==0   ){
                
            }else if((strcmp(paramType,"Void")!=0 && paramNode->child->brother==NULL )){

            }
            else{
                
                abortmission=0;
                char *errorTemp = (char *)malloc(strlen(errorMessages) + 100);  
                sprintf(errorTemp,"Line %d, collumn %d: Invalid use of void type in declaration\n", paramNode->child->line,paramNode->child->col-4);                
                free(errorMessages);
                errorMessages = errorTemp;
                break;
            }
        }
        brothercounter++;
        paramNode = paramNode->brother;
    }
  
     if (strlen(paramsString) >= 2) {
        paramsString[strlen(paramsString) - 1] = '\0';
    }
    noTab *existingTable = findNoTab(global,name,type);
    if(abortmission){
    if (existingTable != NULL ) {
        if(strcmp(existingTable->type, type) == 0  ){
            printf( "Line %d, column %d: Conflicting types (got %s(%s), expected %s)\n",toadd->child->line,toadd->child->col, toLowerCase(type),toLowerCase(paramsString),toLowerCase(existingTable->type));
        }else{
            printf("Line %d, column %d: Symbol %s already defined\n", toadd->child->brother->line,toadd->child->col, name);

        }
        free(auxtab);
    } else {
        size_t newLength = strlen(paramsString) + 2;
        char* newParamsString = (char *)malloc(newLength);
        sprintf(newParamsString, "(%s)", paramsString);
        insert(global, name, type, newParamsString,true);
        tab *auxadd = global;
        while (auxadd->next != NULL) {
            auxadd = auxadd->next;
        }
        auxadd->next = auxtab;
        if(counter!=0){
            for (int i = 0; i < counter; i++)
            {
                printf("%s", errorMessages);
            }
            
        }
    }
    }
    free(errorMessages);
}

