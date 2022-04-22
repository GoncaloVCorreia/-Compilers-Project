#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct tableElement{
    //valor do elemento
    char * value;
    //tipo da elemento
    char * type;
    //caso estejamos nas var globais vao estar aqui os param da funcao
    char *params;
    //verifica se a variavel ja foi definida na funcao; -1 a funcao ainda nao foi declarada. 0 declarada, 1 usada
    int counter;

    int line;
    int column;
    struct tableElement *next;


}tableElement;

typedef struct functionsList{
    //ID da funcao
    char* funcID;
    //parametros da funcao
    char* params;
    //tipo da funcao (provavelemnte nao vai ser preciso aqui)
    char* type;
    //tabela da funcao

    int line;
    int column;
    struct tableElement *symtable;
    struct functionsList *next;

}functionsList;

struct functionsList *tablesHead;

#endif
