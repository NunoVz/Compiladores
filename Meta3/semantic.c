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
    auxtab->type = strdup(toadd->child->type);
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
                sprintf(errorTemp,"Line %d, column %d: Invalid use of void type in declaration\n", paramNode->child->line,paramNode->child->col-5);                
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
    noTab *existingTable = findNoTab(global,name);
    if (existingTable != NULL && abortmission) {
        if(strcmp(existingTable->type, type) == 0 && existingTable->isDeclaration ){
            existingTable->isDeclaration=false;
            tab *change = findTable(global,name);
            change->table=auxtab->table;
            change->isDeclaration=false;
        }
        else if(strcmp(existingTable->id, name) == 0  && !existingTable->isDeclaration){
            printf("Line %d, column %d: Symbol %s already defined\n", toadd->child->brother->line,toadd->child->col, name);
        }
        else{
            printf( "Line %d, column %d: Conflicting types (got %s(%s), expected %s%s)\n",toadd->child->line,toadd->child->col, toLowerCase(type),toLowerCase(paramsString),toLowerCase(existingTable->type),toLowerCase(existingTable->params));

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
    //checkBody(auxtab,toadd->child->brother->brother->brother,toadd->child->type);  
}

void decl(no toadd){
    char *type = toadd->child->type;                   
    char *name = toadd->child->brother->infor;          
    int keepgoing=1;
    int gflag=1;
    if(strcmp(type, "Void")==0){
        char error[100];
        //TODO: Somehow meter a linha e coluna certa quando é void a=2+232+32 para diz l e c no a
        sprintf(error, "Line %d, column %d: Invalid use of void type in declaration\n",toadd->child->brother->line,(int)(toadd->child->brother->col-strlen(toadd->child->brother->type)));
        printf("%s", error);
        return;
    }
    
    noTab *existingTable = findNoTab(global,name);
    
    if (existingTable != NULL) {
        if(strcmp(existingTable->type, type) != 0 && strcmp(father->type, "Program")==0){
            char error[100];
            sprintf(error, "Line %d, column %d: Conflicting types (got %s, expected %s)\n",toadd->child->line,toadd->child->col, toLowerCase(type),toLowerCase(existingTable->type));
            printf("%s", error);
            keepgoing=0;
        }
        gflag=0;

    }
    
    if(keepgoing){
        if(strcmp(father->type, "Program") == 0){
            if(gflag)
                insert(global, name, type, "",true);       
        }
        else{
            tab *existingTable =findTable(global,father->parent->child->brother->infor);
            if (existingTable != NULL) {
                noTab *exist= findNoTab(existingTable,name);
                if(exist != NULL){
                    char error[100];
                    sprintf(error,"Line %d, column %d: Symbol %s already defined\n", toadd->line,(int)(toadd->col-strlen(exist->type)-strlen(exist->id)), name);
                    printf("%s", error);
                }else
                    insert(existingTable, name, type, "",true);

            }
        }
        if (toadd->child->brother->brother != NULL) {
            no auxno = toadd->child->brother->brother;
            if (strcmp(auxno->type, "ChrLit") == 0 || strcmp(auxno->type, "Natural") == 0) {
                auxno->auxinfo = (char *)strdup("int");
            } else if (strcmp(auxno->type, "Decimal") == 0) {
                auxno->auxinfo = (char *)strdup("double");
            } 
        }

        

    }
}

void funcDecl(no toadd){
    int abortmission=1;
    char *name = toadd->child->brother->infor;  
    char *type = toadd->child->type;           

    tab *auxtab= (tab *)malloc(sizeof(tab));
    auxtab->type = strdup(toadd->child->type);
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
                sprintf(errorTemp,"Line %d, column %d: Invalid use of void type in declaration\n", paramNode->child->line,paramNode->child->col-5);                
                free(errorMessages);
                errorMessages = errorTemp;
                return;
            }
        }
        brothercounter++;
        paramNode = paramNode->brother;
    }
  
     if (strlen(paramsString) >= 2) {
        paramsString[strlen(paramsString) - 1] = '\0';
    }
    noTab *existingTable = findNoTab(global,name);
    printf("%s|%s\n",existingTable,name);
    if (existingTable != NULL && abortmission && !existingTable->isDeclaration) {
        if(strcmp(existingTable->id, name) == 0 ){
            printf("Line %d, column %d: Symbol %s already defined\n", toadd->child->brother->line,toadd->child->col, name);
        }
        else {
            printf( "Line %d, column %d: Conflicting types (got %s(%s), expected %s%s)\n",toadd->child->line,toadd->child->col, toLowerCase(type),toLowerCase(paramsString),toLowerCase(existingTable->type),toLowerCase(existingTable->params));
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
        
        printf("%s", errorMessages);
            
    }
    
    free(errorMessages);
}


//---------------------------------ANOTACÕES
void checkCall(tab table,no toadd){

}


int compare(char *first, char *second) {
    int isValid = 0;

    if (strcmp(first, "int") == 0 || strcmp(first, "char") == 0 || strcmp(first, "short") == 0) {
        isValid = (strcmp(second, "void") == 0 || strcmp(second, "undef") == 0) ? 1 : 0;
    } else if (strcmp(first, "double") == 0) {
        isValid = (strcmp(second, "int") == 0 || strcmp(second, "char") == 0 ||
                    strcmp(second, "short") == 0 || strcmp(second, "undef") == 0) ? 1 : 0;
    } else if (strcmp(first, "void") == 0) {
        isValid = (strcmp(second, "int") == 0 || strcmp(second, "char") == 0 ||
                    strcmp(second, "short") == 0 || strcmp(second, "undef") == 0 ||
                    strcmp(second, "double") == 0) ? 1 : 0;
    } else if (strcmp(first, "undef") == 0) {
        isValid = (strcmp(second, "undef") != 0) ? 1 : 0;
    }

    return isValid;
}

void *checkRet(tab *table,no toadd){
    no aux=toadd->child;
    checkExpr(table,aux);
    char error[100];
    
    
    if ((strcmp(table->type, "Void") == 0) && strcmp(toadd->child->auxinfo, "Null") != 0 && strcmp(aux->auxinfo, "Null") != 0)
    {
        
    }
    else if(toadd->child){
        if(compare(aux->auxinfo,table->type)==1){
            if (strcmp(toadd->child->type, "Null") != 0)
                sprintf(error, "Line %d, column %d: Conflicting types (got %s, expected %s)\n",toadd->child->line,toadd->child->col, toLowerCase(aux->auxinfo),toLowerCase(table->type));
            else
                sprintf(error, "Line %d, column %d: Conflicting types (got %s, expected %s)\n",toadd->line,toadd->col ,toLowerCase(aux->auxinfo),toLowerCase(table->type));

            printf("%s", error);
        }
    }
    

    
}

char *checkExpr(tab *table,no toadd){
    char error[100];


    if(strcmp("Call",toadd->type)==0){
        printf("%s|\n",toadd->child->infor);
        if (strcmp(toadd->child->infor, "putchar")==0 || strcmp(toadd->child->infor, "getchar")==0){
            toadd->auxinfo = strdup("int");
            toadd->child->auxinfo = strdup("int");
            checkExpr(table,toadd->child);
        }
        else{
            checkExpr(table,toadd->child);
            toadd->auxinfo = strdup(toadd->child->auxinfo);
        }

        

    }else if(strcmp("Natural",toadd->type)==0){
        toadd->auxinfo = (char *)strdup("int");
        return toadd->auxinfo;
    }else if(strcmp("ChrLit",toadd->type)==0){
        toadd->auxinfo = (char *)strdup("int");
        return toadd->auxinfo;
    }else if(strcmp("Decimal",toadd->type)==0){
        toadd->auxinfo = (char *)strdup("double");
        return toadd->auxinfo;
    }else if(strcmp("Identifier",toadd->type)==0){
        noTab *existingTable = findNoTab(global,toadd->infor);
        if (existingTable == NULL ) {
               existingTable = findNoTab(table,toadd->infor);
        }

        if (existingTable == NULL ) {
            tab *func=findFunc(global,toadd->infor);
            if(func!=NULL){
                return toadd->auxinfo=toLowerCase(func->type);

            }
        }else{
            return toadd->auxinfo= toLowerCase(existingTable->type);

        }

     
        
    }else if(strcmp("Not",toadd->type)==0 || strcmp("Plus",toadd->type)==0 || strcmp("Minus",toadd->type)==0){
        no aux=toadd->child;
        char *type=checkExpr(table,aux);
        if(strcmp(type,table->type)==0){
            char error[100];
            sprintf(error, "Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",toadd->line,toadd->col,operatores(toadd->type),toadd->type, table->name);
            printf("%s", error);
            if(strcmp(toadd->type,"Not")==0){
                toadd->auxinfo = (char *)strdup("int");
            }else{
                toadd->auxinfo = (char *)strdup("undef");
            }
        }
        if(strcmp(type,"Void")==0 || strcmp(type,"undef")==0){
            char error[100];
            sprintf(error, "Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",toadd->line,toadd->col,operatores(toadd->type),toadd->type, type);
            printf("%s", error);
            if(strcmp(toadd->type,"Not")==0){
                toadd->auxinfo = (char *)strdup("int");
            }else{
                toadd->auxinfo = (char *)strdup("undef");
            }
        }else if(strcmp(toadd->type,"Not")==0){
            if(strcmp(toadd->type,"Double")){
                sprintf(error, "Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",toadd->line,toadd->col,operatores(toadd->type),toadd->type, type);
            printf("%s", error);
            }
        }
        
    }else if(strcmp(toadd->type,"Lt")==0 || strcmp(toadd->type,"Le")==0 || strcmp(toadd->type,"Gt")==0 || strcmp(toadd->type,"Ge")==0 || strcmp(toadd->type,"Ne")==0 || strcmp(toadd->type,"Eq")==0 || strcmp(toadd->type,"Not")==0){

        no aux1=toadd->child;
        no aux2=toadd->child->brother;

        checkExpr(table, aux1);
        checkExpr(table, aux2);

        if(strcmp(aux1->auxinfo,"undef")==0 || strcmp(aux2->auxinfo,"undef")==0 ){
            char error[100];
            sprintf(error, "Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",toadd->line,toadd->col,operatores(toadd->type),aux1->type, aux2->type);
            printf("%s", error);
        }
        
        return toadd->auxinfo= (char *) strdup("int");
    }else if(strcmp(toadd->type, "Or") == 0 || strcmp(toadd->type, "And") == 0 ||  strcmp(toadd->type, "BitWiseAnd") == 0 || strcmp(toadd->type, "BitWiseOr") == 0 || strcmp(toadd->type, "BitWiseXor") == 0 || strcmp(toadd->type, "Mod") == 0){
      
        return toadd->auxinfo= (char *) strdup("int");
    }else if(strcmp(toadd->type, "Div") == 0 ||strcmp(toadd->type, "Mul") == 0 ||strcmp(toadd->type, "Sub") == 0 ||strcmp(toadd->type, "Add") == 0 ||strcmp(toadd->type, "Store") == 0){
        no aux1=toadd->child;
        no aux2=toadd->child->brother;
        char * storeaux1= checkExpr(table,aux1);
        char * storeaux2=checkExpr(table,aux2);
        noTab *existingTable = findNoTab(table,aux1->infor);
        if (existingTable == NULL ) {
            toadd->auxinfo=(char *) strdup("undef");
        }
        existingTable = findNoTab(table,aux2->infor);
        if (existingTable == NULL ) {
            toadd->auxinfo=(char *) strdup("undef");
        }
        //printf("%s|%s|%s|||%s|%s\n",toadd->type,toadd->child->type,toadd->child->brother->type,storeaux1,storeaux2);

        if(strcmp("Void",aux1->auxinfo)==0|| strcmp("Void",aux2->auxinfo)==0||strcmp("undef",aux1->auxinfo)==0||strcmp("undef",aux1->auxinfo)==0){
            sprintf(error, "Operator %s cannot be applied to types %s, %s\n", operatores(toadd->type), toLowerCase(aux1->auxinfo),toLowerCase(aux2->auxinfo));
            printf("%s", error);
            toadd->auxinfo=(char *) strdup("undef");
            if(strcmp(toadd->type,"Store")==0){
                return toadd->auxinfo=toLowerCase(aux1->auxinfo);

            }
            toadd->auxinfo=(char *) strdup("undef");
            
        }else if(strcmp("double",aux1->auxinfo)==0|| strcmp("double",aux2->auxinfo)==0){
            if(strcmp(toadd->type,"Store")==0){
            

                if(strcmp("double",aux1->auxinfo)!=0 && strcmp("double",aux2->auxinfo)==0){
                    sprintf(error, "Operator s cannot be applied to types %s, %s\n",aux1->auxinfo,aux2->auxinfo);
                    printf("%s", error);
                }
                return toadd->auxinfo=toLowerCase(aux1->auxinfo);

            }else{
                toadd->auxinfo=(char *) strdup("double");

            }
        }else if(strcmp("int",aux1->auxinfo)==0|| strcmp("int",aux2->auxinfo)==0){
            if(strcmp(toadd->type,"Store")==0){
               
                return toadd->auxinfo=toLowerCase(aux1->auxinfo);

            }else{
                toadd->auxinfo=(char *) strdup("int");  
            }
        }else if(strcmp("short",aux1->auxinfo)==0|| strcmp("short",aux2->auxinfo)==0){
            if(strcmp(toadd->type,"Store")==0){
             
                return toadd->auxinfo=toLowerCase(aux1->auxinfo);

            }else{
                toadd->auxinfo=(char *) strdup("short");  
            }
        }else{
            if(strcmp(toadd->type,"Store")==0){
               
                return toadd->auxinfo= toLowerCase(aux1->auxinfo);

            }else{
                return toadd->auxinfo=toLowerCase(aux1->auxinfo);
            }
        }



     


    }else if (strcmp(toadd->type, "Null") == 0)
    {
        return toadd->auxinfo=(char *) strdup("Void");
        
    }else{
        no aux1=toadd->child;
        no aux2=toadd->child->brother;

        checkExpr(table, aux1);
        checkExpr(table, aux2);
       
    }

    return "NULL";
    

    
}

void checkStat(tab *table,no toadd, char *ftype){

    if(strcmp(toadd->type,"If")==0){
        no aux=toadd->child;
        checkExpr(table,toadd);

    }else if(strcmp(toadd->type,"While")==0){

    }else if(strcmp(toadd->type,"Return")==0){
        checkRet(table,toadd);

    }else if(strcmp(toadd->type,"Statlist")==0){

    }else{
        checkExpr(table,toadd);
    }
}

void checkBody(tab *table, no toadd,char* ftype){
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



char *operatores(char *str) {
    struct OperatorMapping {
        const char *input;
        const char *output;
    };

    const struct OperatorMapping operatorMappings[] = {
        {"Add", "+"},
        {"Plus", "+"},
        {"Store", "="},
        {"Sub", "-"},
        {"Minus", "-"},
        {"Mul", "*"},
        {"Div", "/"},
        {"Mod", "%"},
        {"Or", "||"},
        {"And", "&&"},
        {"BitWiseAnd", "&"},
        {"BitWiseOr", "|"},
        {"BitWiseXor", "^"},
        {"Eq", "=="},
        {"Ne", "!="},
        {"Le", "<="},
        {"Ge", ">="},
        {"Lt", "<"},
        {"Gt", ">"},
        {"Not", "!"},
        {"RealComma", ","},
        {"Comma", ","},
    };

    for (size_t i = 0; i < sizeof(operatorMappings) / sizeof(operatorMappings[0]); ++i) {
        if (strcmp(str, operatorMappings[i].input) == 0) {
            return strdup(operatorMappings[i].output);
        }
    }

    return NULL;
}


