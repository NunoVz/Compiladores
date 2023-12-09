#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "y.tab.h"
#include "funcoes.h"



no create(char* type, char* info) {
    if( type==NULL || info==NULL ){
        return NULL;
    }
    no new_node = (no)malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->parent = NULL;
        new_node->child = NULL;
        new_node->brother = NULL;
        new_node->nchildren = 0;

        new_node->type = (char*)malloc(strlen(type) + 1);
        strcpy(new_node->type, type);

        new_node->auxinfo  = (char *)malloc(20 * sizeof(char));


        new_node->infor = (char*)malloc(strlen(info) + 1);
        if (new_node->infor == NULL) {
            free(new_node->type);
            free(new_node);
            return NULL;
        }
        strcpy(new_node->infor, info);
    }else{
        free(new_node);
        return NULL;
    }
    
    return new_node;
}

no addChild(no parent, no child){

    if (parent == NULL || child == NULL) {
        return NULL; 
    }

    child->parent = parent;

    if (parent->child == NULL) {
        parent->child = child;

    } else {
        no sibling = parent->child;
        while (sibling->brother != NULL) {
            sibling = sibling->brother;
        }
        sibling->brother = child;
    }

    parent->nchildren++;


    return parent;
}

void addBrother(no existingNode, no newBrother) {
    if (existingNode == NULL || newBrother == NULL) {
        return; 
    }

    while (existingNode->brother != NULL) {
        existingNode = existingNode->brother;
    }

    existingNode->brother = newBrother;
}
int countB(no root) {
		int count = 0;
		no aux = root;

		while(aux != NULL) {
			aux = aux->brother;
			count++;
		}
		
		return count;
	}

void printTree(no root, int size) {
		if(root == NULL){
        	return;
    	}
		int i = 0;
		no aux;
		if(strcmp(root->type, "Program") == 0)
			printf("%s\n", root->type);
		else {
            if(strcmp(root->type, "X") == 0){}
            else{
			while(i < size) {
				printf("..");
				i++;
			}
            if(strcmp(root->auxinfo, "") == 0){
                if(strcmp(root->infor, "") != 0)
				    printf("%s(%s)\n", root->type, root->infor);
                else
                    printf("%s\n", root->type);
                
            }else{
                if(strcmp(root->infor, "") != 0)
				    printf("%s(%s) - %s\n", root->type, root->infor,root->auxinfo);
                else
                    printf("%s - %s\n", root->type,root->auxinfo);
                }
            }
            
			
		}

		aux = root->child;

		while(aux!= NULL){
			no free_n = aux;
			printTree(aux, size+1);
			aux = aux->brother;
			
			free(free_n);
		}
	}


