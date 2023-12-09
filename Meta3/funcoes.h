#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct node* no;
typedef struct node{
    no parent;
    no child;
    no brother;
    int nchildren;

    char* type;
    char* infor;
    char* auxinfo;

}node;

extern  no root;


no create(char* type, char* info);
no addChild(no parent, no child);
void addBrother(no existingNode, no newBrother);
void printTree(no root, int level);
int countB(no root);
#endif