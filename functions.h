#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

#include "structures.h"
idToken *createID(char *id, int line, int col);
struct node * newNode(char *type, idToken *id);
node *addNode(node * newNode, node *parent);
node *addSibling(node *sb1,node*sb2);
void printAST(node * root,int level);
void deleteTree(node *root);
void makeAnotation(node * node, char * funcID);
void  annotateTree(node * root,int level, char * funcID);
char * returnIDType( char * idValue,char *funcID, int func,node *id);
void increaseCounter(char * value, char * funcID);