#include "structures.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>


//cria elemento
tableElement * createElement(char *value,char *params ,char *type, int line, int column){

    tableElement * te= (struct tableElement *)malloc(sizeof(struct tableElement));
    te->value=value;
    te->type=strdup(type);
    te->params=strdup(params);
    te->next=NULL;
    te->line=line;
    te->column=column;
    te->counter=-1;
    return te;
}

//cria tabela
functionsList * createTable(char * funcID,tableElement *te,char *params,char *type, int line, int column){
    functionsList * func = (struct functionsList *)malloc(sizeof(struct functionsList));
    func->funcID=funcID;
    func->params=strdup(params);
    func->type=type;
    func->next=NULL;
    func->symtable=te;
    func->line=line;
    func->column=column;

    return func;
}

//coloca string recebida em minusculas
char *getLower(char string[100]){
    for(int i=0; i<strlen(string);i++){
        string[i]=tolower(string[i]);
    }
    return string;
}

//insere o elemento te na tabela escolhida (chosen)
void insertInChooseFuncTable(char *chosen, tableElement * te){

    //todas as tabelas
      

    functionsList * auxFL= tablesHead;
        while(auxFL!=NULL){
           
            //entra na tabela pretendida
            if (strcmp(auxFL->funcID,chosen)==0){
                
                //insere elemento na tabela (cauda da tabela)
                tableElement* auxS= auxFL->symtable;
                if(auxFL->symtable==NULL){
                    auxFL->symtable=te;
                }
                else{
                while(auxS->next!=NULL){
                     
                    auxS=auxS->next;
                }
               
                auxS->next=te;
                break;
                }
            }
            
            auxFL=auxFL->next;
        }

}

//insere variaveis globais
void insertInGTable(struct node * newNode){

    char typeLow[100]="";
    strcat(typeLow,newNode->children[0]->type);
    char *typeLowFinal=getLower(typeLow);
    int checkVarDeclRes;

    //falta funcao para verificar se elemento ja existe na tabela
   
    checkVarDeclRes = checkVarDecl(newNode->children[1], "");

    if (checkVarDeclRes == 1){

        return;

    }

    tableElement * te=createElement(newNode->children[1]->value,"",typeLowFinal,newNode->children[1]->line,newNode->children[1]->column);
    
   
    //se nao existir uma tabela global cria e coloca na lista de funcoes
    if(tablesHead==NULL){
        
       
        tablesHead=createTable("",te,"","",te->line,te->column);

    }
    //insere a variavel global no tabela certa
    else{
      
        insertInChooseFuncTable("",te);
    }

    //cria nova tabela


}

//insere params da funcao na sua tabela
void  insertPV(functionsList* func,node *newNode){

    int checkVarDeclRes=0;

    if(strcmp(newNode->children[0]->children[1]->type,"FuncParams")!=0){

         //Está no 1ª ParamDecl (FuncDecl->FuncHeader->FuncParams->ParamDecl)
         node * params=newNode->children[0]->children[2]->children[0];
        

        //coloca params numa string
        
        while(params!=NULL){
            
            checkVarDeclRes = 0;
            checkVarDeclRes = checkVarDecl(params->children[1], func->funcID);

            if (checkVarDeclRes == 1){

                return;

            }

            //falta dar low de segundo parametro
            char typeLow[100]="";
            strcat(typeLow,params->children[0]->type);
            char *typeLowFinal=getLower(typeLow);
            tableElement *te=createElement(params->children[1]->value,typeLowFinal,"param",params->children[1]->line, params->children[1]->column);


            insertInChooseFuncTable(func->funcID,te);
            params=params->sibling;
        }

    }
    else{

        //Está no 1ª ParamDecl (FuncDecl->FuncHeader->FuncParams->ParamDecl)
        node * params=newNode->children[0]->children[1]->children[0];
  
        //coloca params numa string
        
        while(params!=NULL){

            checkVarDeclRes = 0;
            checkVarDeclRes = checkVarDecl(params->children[1], func->funcID);

            if (checkVarDeclRes == 1){

                return;

            }
            
            char typeLow[100]="";
            strcat(typeLow,params->children[0]->type);
            char *typeLowFinal=getLower(typeLow);
            tableElement *te=createElement(params->children[1]->value,typeLowFinal,"param",params->children[1]->line, params->children[1]->column);
           
            insertInChooseFuncTable(func->funcID,te);
            params=params->sibling;
        }

    }
    


}

//insere os params do funcBody
void insertFuncBodyVars(char *funcId,node * funcBody){

    for(int i=0;i< funcBody->numChild;i++){
        node * aux=funcBody->children[i];
        while(aux!=NULL){
            if(strcmp(aux->type,"VarDecl")==0){
            //verificar se var ja existe   
            int checkVarDeclRes = 0;
            checkVarDeclRes = checkVarDecl(aux->children[1], funcId);

            if (checkVarDeclRes == 1){

                return;

            }
            //passar para minuscila
            char typeLow[100]="";
            strcat(typeLow,aux->children[0]->type);
            char *typeLowFinal=getLower(typeLow);

            //insere elemento
            tableElement * te=createElement(aux->children[1]->value,typeLowFinal,"",aux->children[1]->line, aux->children[1]->column);
            insertInChooseFuncTable(funcId,te);
            }
            aux=aux->sibling;
        }
    }

}

//cria tabela por funcao, recebe funcao como parametro
void insertInFTable(struct node * newNode){

    //printf("%s\n", newNode->children[0]->children[0]->value);

    int checkFuncDeclRes;
    //verifica se funcao ja existe
    checkFuncDeclRes = checkFuncDecl(newNode->children[0]->children[0]);

    if (checkFuncDeclRes == 1){

        return;

    }
    


    tableElement *te;
    tableElement* firstElem;
    //se a funcao tiver um tipo
    if(strcmp(newNode->children[0]->children[1]->type,"FuncParams")!=0){
       
        //Está no 1ª ParamDecl (FuncDecl->FuncHeader->FuncParams->ParamDecl)
        node * params=newNode->children[0]->children[2]->children[0];
        

        //coloca params numa string
        char paramss[100]="(";
        while(params!=NULL){
            //printf("Param: %s\n",params->children[0]->type);
            strcat(paramss,params->children[0]->type);
            if(params->sibling!=NULL){
                strcat(paramss,",");
            }
            params=params->sibling;
        }
       
        strcat(paramss,")");
        char *paramssFinal=getLower(paramss);
        //fim
       
        //coloca tipo em lowercase
        char typeLow[100]="";
        strcat(typeLow,newNode->children[0]->children[1]->type);
        char *typeLowFinal=getLower(typeLow);
     

        //cria elemento e adiciona tabela global
        te= createElement(newNode->children[0]->children[0]->value,paramssFinal,typeLowFinal,newNode->children[0]->children[0]->line,newNode->children[0]->children[0]->column);

        // coloca o tipo do return em minuscula
        memset(typeLow,0,sizeof(typeLow));
        strcat(typeLow,newNode->children[0]->children[1]->type);
        typeLowFinal=getLower(typeLow);

        //adiciona o return do tipo da funcao
        firstElem= createElement("return",typeLowFinal,"",newNode->children[0]->children[1]->line,newNode->children[0]->children[1]->column);
        if(tablesHead==NULL){
            tablesHead=createTable("",te,"","",te->line,te->column);

        }
        else{
            insertInChooseFuncTable("",te);
        }

    }
    else{
        node * params=newNode->children[0]->children[1]->children[0];

        //coloca params numa string
        char paramss[100]="(";
        while(params!=NULL){
            //printf("Param: %s\n",params->children[0]->type);

            strcat(paramss,params->children[0]->type);
            if(params->sibling!=NULL){
                strcat(paramss,",");
            }
            params=params->sibling;
        }
        strcat(paramss,")"); 
        char *paramssFinal=getLower(paramss);
        //fim

    
        te= createElement(newNode->children[0]->children[0]->value, paramssFinal,"none",newNode->children[0]->children[0]->line,newNode->children[0]->children[0]->column);
        //adiciona return do tipo da funcao
        firstElem= createElement("return","none","",newNode->children[0]->children[0]->line,newNode->children[0]->children[0]->column);
        if(tablesHead==NULL){
            tablesHead=createTable("",te,"","",te->line,te->column);

        }
        else{

            //insere funcao na tabela global
            insertInChooseFuncTable("",te);
        }
    }

    struct functionsList *aux =tablesHead;

    
    //cria tabela para a funcao
    
    struct functionsList* func=createTable(te->value,NULL,te->params,"",te->line,te->column);
  
    //insere na lista de tabelas
    if(tablesHead==NULL){
       
        tablesHead=func;
    }
    else{
        while(aux->next!=NULL){
                     
            aux=aux->next;
                
        }
               
        aux->next=func;
        }
    
    insertInChooseFuncTable(func->funcID, firstElem);
    //inseres os parametros da funcao na tabela da funcao 
    insertPV(func,newNode);
    
    
    // insere variaveis do funcBody (FuncDecl->FuncBody)
    //printf("Estou no %s\n",newNode->children[1]->type);
    insertFuncBodyVars(func->funcID,newNode->children[1]);
    //...

}

//da print das tabelas
void printTables(functionsList *tables){
    if(tables==NULL){
        //printf("nao ha tabelas");
        return;
    }
    functionsList *aux=tables;
    tableElement *aux2=aux->symtable;
    //percorre as tabelas existentes
    while(aux!=NULL){
         
        if(strcmp(aux->funcID,"")==0){
                printf("===== Global Symbol Table =====\n");
        }
        else{
             printf("\n===== Function %s%s Symbol Table =====\n",aux->funcID,aux->params);
        }
        aux2=aux->symtable;
        //percorre elementos das tabelas
        while(aux2!=NULL){
            if(strcmp(aux->funcID,"")==0){
                printf("%s\t%s\t%s\n",aux2->value,aux2->params,aux2->type);
            }
            else{
                 printf("%s\t\t%s",aux2->value,aux2->params);
                 if(strcmp(aux2->type,"")!=0){
                    printf("\t%s\n",aux2->type);
                 }
                 else{
                    printf("\n");
                 }
            }
            aux2=aux2->next;
        }
        aux=aux->next;
      
    }
}




int checkVarDecl(node * nodeID, char *funcID) {

    //Verifica se a variavel ja varId ja foi declarada 
    //return 1 variavel ja declarada, 0 nao declarada

    functionsList *aux = tablesHead;
    //ver na tabela da sua funcao
    while (aux != NULL) {

        if(strcmp(aux->funcID, funcID)==0){

            tableElement *aux2 = aux->symtable;

            while (aux2 != NULL) {

                if(strcmp(aux2->value, nodeID->value)==0){
                    printf("Line %d, column %d: Symbol %s already defined\n",nodeID->line,nodeID->column,nodeID->value);
                    return 1;

                }

                aux2 = aux2->next;

            }
            
        }
         aux = aux->next;
    }
        aux=tablesHead;

    //ver na tabela global
    while (aux != NULL) {

        if(strcmp(aux->funcID, "")==0){

            tableElement *aux2 = aux->symtable;

            while (aux2 != NULL) {
                //printf( "estou a ver a var :%s    com o  tIpo: %s a comparar com tipo %s\n",nodeID->value, nodeID->parent->children[0]->type,aux2->type);
                char string[100]="";
                strcat(string, nodeID->parent->children[0]->type);
                char *type=getLower(string);
                if(strcmp(aux2->value, nodeID->value)==0 && strcmp(aux2->type,type)==0){
                    
                    printf("Line %d, column %d: Symbol %s already defined\n",nodeID->line,nodeID->column,nodeID->value);
                    return 1;

                }

                aux2 = aux2->next;

            }
            
        }

        aux = aux->next;

    }

    return 0;

}


int checkFuncDecl(node *func) {

    //Verifica se a funcao  funcId ja foi declarada 
    //return 1 funcao ja declarada, 0 nao declarada

    functionsList *aux = tablesHead;

    while (aux != NULL) {
        if(strcmp(aux->funcID,"")==0){
            tableElement* te=aux->symtable;
            while(te!=NULL){
                if(strcmp(te->value,func->value)==0 ){
                  
                    printf("Line %d, column %d: Symbol %s already defined\n",func->line,func->column,func->value);
                    return 1;
                }
                te=te->next;
            }
        }
        if (strcmp(aux->funcID, func->value) == 0) {
            printf("Line %d, column %d: Symbol %s already defined\n",func->line,func->column,func->value);
            return 1;

        }

        aux = aux->next;

    }
    
    return 0;

} 