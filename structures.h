#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "symbol_table.h"
#define MAX 100

typedef struct idToken {
  char *id;
  int line;
  int col;
} idToken;

typedef struct node{

    char* type;
   char *value;
    int numChild;
    int line;
    int column;
    struct node *parent;
    struct node *sibling;

    struct node* children[MAX];
    
    char* anot;

}node;



struct node * head;

tableElement * createElement(char *value,char *params ,char *type, int line , int column);
functionsList * createTable(char * funcID,tableElement *te,char *params,char *type, int line, int column);
char * getLower(char string[100]);

void insertPV(functionsList* func,node *newNode);
void insertFuncBodyVars(char *funcId,node * funcBody);
void insertInChooseFuncTable(char *chosen, tableElement * te);
void insertInGTable(struct node *newNode);
void insertInFTable(struct node * newNode);
void printTables(functionsList * tables);
int checkFuncDecl(node * func);
int checkVarDecl(struct node *nodeID, char *funcID);
char * returnIDType2( char * idValue,char *funcID, int func);

#endif