#include "structures.h"
#include "semantics.h"
#include "symbol_table.h"
#include <stdio.h>
#include <string.h>

// cria as tabelas
int makeTables(node *root, int flag){
    node * aux=root;
    if(aux==NULL){
        return 1;
    }
    if (aux->type==NULL){
        
        return 1;
    }
    
    
    else{
      
      for(int i=0;i<aux->numChild;i++){
          node *auxSibling=aux->children[i];
          while(auxSibling!=NULL){
         
            if(strcmp("VarDecl",auxSibling->type)==0){
                //printf("Filho de Vardecl: %s\n",auxSibling->children[0]->type);
                //printf("Filho de Vardecl: %s\n",auxSibling->children[1]->value);
                insertInGTable(auxSibling);
               

           }
           if(strcmp("FuncDecl",auxSibling->type)==0){
                
                //printf("entrei na func %s\n", auxSibling->children[0]->children[0]->value);
                insertInFTable(auxSibling);
               
           }
            auxSibling =auxSibling->sibling;
        }
      }
            
           
        
   }
   if(flag==0){
    printTables(tablesHead);
   }
    return 0;
}

