#include "functions.h"
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
lex gocompiler.l
yacc -d gocompiler.y
cc -o compiler lex.yy.c y.tab.c functions.c semantics.c symbol_table.c
*/

idToken *createID(char *id, int line, int col) {
  idToken *idt = malloc(sizeof(idToken));
  idt->id = strdup(id);
  idt->line = line;
  idt->col = col;
  //printf("ID-> %s  Line-> %d   Column-> %d \n",id,line,col);
  return idt;
}

//cria no
struct node * newNode(char *type, idToken * id){

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->numChild=0;

    newNode->value =id->id;
    newNode->line=id->line;
    newNode->column=id->col;
    newNode->type=type;
    newNode->anot="";
    newNode->parent=NULL;
    newNode->sibling=NULL;
    
    //printf("New node created, value: %s  type: %s\n",newNode->value,newNode->type);
    return newNode;

}

//adiciona no
node * addNode(node* newNode,node *parent){
    if(newNode==NULL || parent==NULL){
        return NULL;
    }
	parent->children[parent->numChild] = newNode;

	parent->numChild++;

	newNode->parent = parent;

   
    //printf("Node parent -> %s %s  Node son -> %s %s\n",parent->value,parent->type,newNode->value,newNode->type);


	return parent;

    

}

//adiciona irmao
node* addSibling(node * sb1, node *sb2){
    if(sb1==NULL || sb2==NULL){
        return NULL;
    }
    struct node * aux = sb1;

	if (aux != NULL) {

		while (aux->sibling != NULL) {

			aux = aux->sibling;
		}
       
		aux->sibling = sb2;
	}
	
	return sb1;
}

//retorna o tipo do ID que se esta a ver 0- vars, 1- calls,2-  func params
char * returnIDType( char * idValue,char *funcID, int func, node *id){
 
    functionsList *aux =tablesHead;
    if(aux != NULL){ 
        aux = aux->next;
        }
    //verificar se existe nas variaveis da funcao em que esta
    while(aux != NULL){
        tableElement * symtab ;
        if(func==0){
            if(strcmp(aux->funcID,funcID)==0){
                symtab=aux->symtable;
                while(symtab!=NULL){
                    //printf("counter %d, funcid %s, symbol %s\n", symtab->counter, funcID, symtab->value);
                    if(strcmp(symtab->value,idValue)==0 && symtab->counter==0){
                        return symtab->params;

                    }

                    symtab=symtab->next;
                }
            }
        }
     aux = aux->next;

    }
    aux =tablesHead;
    //printf("Valor  a ser analisado: %s\n",idValue);
    while(aux!=NULL){
        tableElement * symtab ;

    
        //verificar se existe nas variaveis globais
        if(strcmp(aux->funcID,"")==0){
           
            symtab=aux->symtable;
            while(symtab!=NULL){
               
                if(strcmp(symtab->value,idValue)==0 && symtab->counter==0){
                    
                    if (func==2){
                        //printf("Tou na func %s com os params %s\n",symtab->value, symtab->params);
                        //printf("os meus params %s\n",id->)
                       return symtab->params;
                    }
                    else{
                        //printf("Tou na func %s com os params %s\n",symtab->value, symtab->params);
                        return symtab->type;
                    }

                }
                symtab=symtab->next;
            }
        }
        aux=aux->next;
    }
    if(id->line!=-1){
        printf("Line %d, column %d: Cannot find symbol %s\n",id->line,id->column,idValue);
    }
    
    return "";
   
}

//Quando a variavel é declarada ou está nos Params counter passa a 1
void increaseCounter(char * value, char * funcID){
    //printf("entrei increase, value: %s\n", value);
    functionsList *aux =tablesHead;

    while(aux != NULL){

        if(strcmp(aux->funcID, funcID) == 0){

            tableElement * symtab ;
            symtab = aux->symtable;
           
            while(symtab != NULL){
                if(strcmp(value, symtab->value)==0){
                    symtab->counter = 0;
                    //printf("Adicionei funcid %s, value %s , node %d \n", funcID, value, symtab->counter);
                    break;
                }
                symtab = symtab->next;
            }

        }
        aux = aux->next;

    }

}

//anota os nos de acordo com a funcao em q esta
void makeAnotation(node * node, char *funcID){

    if(strcmp(node->type, "VarDecl")==0 || strcmp(node->type, "ParamDecl")==0){
        increaseCounter(node->children[1]->value, funcID);
    }

    //BOOL
    if(strcmp(node->type,"Gt")==0 || strcmp(node->type,"Ge")==0  || strcmp(node->type,"Eq")==0 || strcmp(node->type,"Ne")==0 ||strcmp(node->type,"Not")==0 ||
    strcmp(node->type,"And")==0 || strcmp(node->type,"Or")==0 || strcmp(node->type,"Le")==0 || strcmp(node->type,"Lt")==0 || strcmp(node->type,"Gt")==0){
       
        node->anot=strdup("bool");
     
    }
    //INTLIT
    if(strcmp(node->type,"IntLit")==0){

        node->anot=strdup("int");
    }
    //REALIT
    if(strcmp(node->type,"RealLit")==0){

        node->anot=strdup("float32");
    }

    //ASSIGN
    if(strcmp(node->type,"Assign")==0){
        char *anot = returnIDType( node->children[0]->value,funcID,0,node);
        //printf("node anot: %s, node value: %s, funcId: %s \n", anot, node->children[0]->value, funcID);
        node->anot=strdup(anot);
        node->children[0]->anot=strdup(anot);
        //falta tratar da segunda parte
    }
    
    //CALL
    if(strcmp(node->type,"Call")==0){
        increaseCounter(node->children[0]->value, "");
        //printf("tou na func: %s\n",node->children[0]->value);
        char *anot = returnIDType( node->children[0]->value,funcID,1,node);
        if(strcmp(anot,"none")==0){
            anot = "";
        }
        node->anot=strdup(anot);
        //anota params funcao
        anot = returnIDType( node->children[0]->value,funcID,2,node);
        node->children[0]->anot=strdup(anot);
    }

    //IDs
    if(strcmp(node->type,"Id")==0){
       
        if(node->parent!=NULL){
            //IDs que nao sejam declaracoes ou que ainda nao tenham sido anotados
            if (strcmp(node->parent->type,"VarDecl")!=0 && strcmp(node->parent->type,"ParamDecl")!=0 && strcmp(node->anot,"")==0 && strcmp(node->parent->type,"FuncHeader")!=0 ){
              
                char *anot = returnIDType(node->value,funcID,0,node);
                node->anot=strdup(anot);
            }
        }
        else{
            char *anot = returnIDType(node->value,funcID,0,node);
            node->anot=strdup(anot);
        }
       
    }

    if(strcmp(node->type, "Plus")==0 || strcmp(node->type,"ParseArgs")==0 || strcmp(node->type,"Mul")==0 || strcmp(node->type,"Add")==0 || strcmp(node->type,"Sub")==0 || strcmp(node->type,"Mod")==0 || strcmp(node->type,"Minus")==0 || strcmp(node->type,"Div")==0){
        struct node * aux=node;
        
       
        while(aux!=NULL){
            if(strcmp(aux->type,"Id")==0){
                char * anot=returnIDType(aux->value,funcID,0,node);
                node->anot=strdup(anot);
                break;
                //printf("%s function, first Id -> %s\n",node->type,aux->value);
            }
            if(strcmp(aux->type,"RealLit")==0){
                char * anot = "float32";
                node->anot=strdup(anot);
                break;
            }
            if(strcmp(aux->type,"IntLit")==0){
                char * anot = "int";
                node->anot=strdup(anot);
                break;

            }

            aux=aux->children[0];

        }
        
    }
    
    
}
    
void printAST(node * root,int level){
  
    node * aux=root;
    if(aux==NULL){
        printf("arvore vazia\n");
        return;
    }
    if (aux->type==NULL){
        
        return ;
    }
    
    else{
       
     
        
       while(aux!=NULL){
           
           


            if(aux->value!=NULL){

                if(strcmp(aux->value,"")==0){
                   

                    for (int j =0;j<level;j++){
                    

                        printf("..");
                    }
                    printf("%s", aux->type);

                   

                    if(strcmp(aux->anot,"")==0){
                        printf("\n");
                    }
                    else{

                        printf(" - %s\n",aux->anot);

                        }
                      
                }
                
                    
                else{
                   
                    for (int j =0;j<level;j++){

                    printf("..");
                    }
                    
                    

                    printf("%s(%s)",aux->type, aux->value);
                   
                    if(strcmp(aux->anot,"")==0){

                        printf("\n");

                    }
                    else{
                       
                        printf(" - %s\n",aux->anot);
                       
                    }
                    
                }
                
            }
            else{
                return;
            }
            
            for(int i=0;i<aux->numChild;i++){
                 

                
                if(aux->children[i]->value==NULL){
                    

                   return;

                }
                else{
                  
            
                    printAST(aux->children[i],level+1);
                    
                    
                }

            }
           
            aux=aux->sibling; 
           
   
        }
        
   }
        
}

//percorre os nos da arvore para os anotar 
void annotateTree(node *root,int level, char * funcID){
  
    node * aux=root;
 
    if(aux==NULL){
        
        return;
    }
    if (aux->type==NULL){
        
        return ;
    }
    
    else{
       
     
        
       while(aux!=NULL){
           


            if(aux->value!=NULL){

                //printf("node Value -> %s || node Type: %s\n",aux->value,aux->type);
                if(strcmp(aux->type,"FuncHeader")==0){
                    funcID=aux->children[0]->value;
                }
                if(strcmp(aux->type,"FuncBody")==0){
                    //FuncBody->FuncDecl->FuncHeader->FuncID->value
                  
                   funcID=aux->parent->children[0]->children[0]->value;
                }
                    
                makeAnotation(aux,funcID);
                
            }
            else{
                return;
            }
            
            for(int i=0;i<aux->numChild;i++){
                 

                
                if(aux->children[i]->value==NULL){
                    

                   return;

                }
                else{
                  
                  
                    annotateTree(aux->children[i],level+1,funcID);
                    
                    
                }

            }
           
            aux=aux->sibling; 
           
   
        }
        
   }
        
}
    
//apaga memoria
void deleteTree(node * root) {

    node * aux = root;

    if(root == NULL){
        //printf("arvore vazia\n");
        free(root);
        return;
    }

    else{

        while (root != NULL){

            for(int i=0; i<root->numChild; i++){
                deleteTree(root->children[i]);
            }
            
            aux = root->sibling;
            free(root);
            root = aux;
        }
    }

}