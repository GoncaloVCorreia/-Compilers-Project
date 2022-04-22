    /* 
    --------------------- PROJETO DE COMPILADORES ----------------------------

    Goncalo Vasconcelos Correia 2019216331
    Vicente Freire Tiago 2018281994

    */

 %{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "functions.h"
    #include "symbol_table.h"
    #include "semantics.h"
    #include "structures.h"

    extern int column;
    extern int errColumn;
    extern int errLine;
    extern int line;
 
    extern int errorBrace2;
    extern int errorBrace;



    int flag=0;

    int yylex (void);
    int yylex_destroy();

    void yyerror(char *s);

    extern char *yytext;
    extern int yyleng;
    extern int yywrap();
    int printTree=0;
%}

%union{
    char *str;
    struct node * node;
    struct idToken *id;
}

%token FUNC PACKAGE SEMICOLON COMMA BLANKID ASSIGN STAR DIV MINUS PLUS EQ GE GT LBRACE RBRACE LE RPAR LPAR LSQ LT MOD NE NOT AND OR RSQ RETURN ELSE FOR IF VAR INT FLOAT32 BOOL STRING PRINT PARSEINT CMDARGS error
%token <str> INTLIT REALLIT RESERVED STRLIT 
%token <id> ID


%type <node> Program Declarations VarDeclaration VarSpec  Type FuncDeclaration Parameters FuncBody VarsAndStatements Statement Expr FuncInvocation ParseArgs 
%type <node>  ci para ty cit vds ss elr exp expcexp cexp 

%left COMMA
%right ASSIGN
%left OR
%left AND 
%left GE LE LT GT EQ NE
%left PLUS MINUS
%left STAR DIV MOD NOT
%right UNARY
%nonassoc LPAR RPAR LSQ RSQ LBRACE RBRACE

%%

Program: PACKAGE ID SEMICOLON Declarations  {
                                           
                                            idToken * idaux = createID("",-1,-1);
                                            head= newNode("Program",idaux);
                                            if ($4 != NULL) {
                                               
                                                addNode($4, head);
                                                
                                            }
                                           $$=head;
		                                   
                                           
                                           
		
                                            

};

Declarations: /*empty*/ { $$ = NULL; }

            | VarDeclaration SEMICOLON Declarations{
               if ($3 != NULL) {
			        addSibling($1, $3);
			    }
			    $$ = $1;
                

            }
            | FuncDeclaration SEMICOLON Declarations{

                if ($3 != NULL) {
				    addSibling($1, $3);
			    }
			    $$ = $1;


            };

VarDeclaration: VAR VarSpec {
                            $$=$2;

                            }

            |   VAR LPAR VarSpec SEMICOLON RPAR {
                        $$ = $3;
                        
                };

VarSpec: ID ci Type {
    //Lista com os vardecs
    idToken * idaux = createID("",-1,-1);
    node * vardecList = newNode("VarDecl",idaux);

    //cada elemento contem um vardec
    node * vardecs[100];
    
    node *firstId= newNode("Id",$1);

    addNode($3,vardecList);
    addNode(firstId,vardecList);

   

    node *vardecsCI =$2;
    int numIds=0;
    node *type;
    while(vardecsCI!=NULL){
        idToken * idaux = createID("",-1,-1);
        //Nova declaracao de var
        vardecs[numIds]=newNode("VarDecl",idaux);
        type=newNode($3->type,idaux);
        //tipo
        addNode(type,vardecs[numIds]);
        //var
        addNode(vardecsCI,vardecs[numIds]);

        numIds++;
        vardecsCI=vardecsCI->sibling;
    }
  

    //retirar irmandade dos irmaos Ci
    node * aux2 = $2;
    node *destroy;
    if(aux2!=NULL){
        if (aux2->sibling != NULL) {
        
					while(aux2 != NULL) {
                        
						destroy = aux2->sibling;
						aux2->sibling = NULL;
						aux2 = destroy;
					}
	    }
    }
    
   
    //torna vardecList e os restantes vardecs em irmaos
    if(numIds>0){
     

        addSibling(vardecList,vardecs[0]);
        if(numIds>1){
             
            
            for (int j=0;j<numIds-1;j++){
               
                addSibling(vardecs[j],vardecs[j+1]);
            }
        }
    }
    
   
                        
    $$=vardecList;
    
   
};

/*ci -> COMMA ID (variavel auxiliar)*/
ci: /*empty*/ {$$ = NULL;}
            
            |COMMA ID ci {

                node * id = newNode("Id",$2);

                if($3!=NULL){
                    $$=addSibling(id,$3);
                   
                }
                else{
                    $$=id;
                }
                

            };


Type: INT {
        idToken * idaux = createID("",-1,-1);
        $$=newNode("Int",idaux);
    }

    | FLOAT32 {
        idToken * idaux = createID("",-1,-1);
        $$=newNode("Float32",idaux);
        }

    |BOOL {
        idToken * idaux = createID("",-1,-1);
         $$=newNode("Bool",idaux);
    }

    |STRING {
          idToken * idaux = createID("",-1,-1);
          $$=newNode("String",idaux);
    
    };


FuncDeclaration: FUNC ID LPAR para RPAR ty FuncBody {
    idToken * idaux = createID("",-1,-1);
    node* funcDecl = newNode("FuncDecl",idaux);
    node* funcHead = newNode("FuncHeader",idaux);
    node * idHead= newNode("Id",$2);
    addNode(idHead,funcHead);
    addNode($6,funcHead);
    
    addNode($4,funcHead);
    
    addNode(funcHead,funcDecl);
    addNode($7,funcDecl);
    $$=funcDecl;


};

/*para -> Parameters (variavel auxiliar)*/
para: /*empty*/ {
      idToken * idaux = createID("",-1,-1);
    $$ = newNode("FuncParams", idaux);
    }

    |Parameters {$$=$1;};
    
/*ty -> Type (variavel auxiliar)*/
ty: /*empty*/ {$$ = NULL;}


    |Type {$$=$1;};

Parameters: ID Type cit {
      idToken * idaux = createID("",-1,-1);
   node * funcPara = newNode("FuncParams",idaux);

   node * firstparaDecl= newNode("ParamDecl",idaux);
   node * firstId = newNode("Id",$1);
   addNode($2,firstparaDecl);
   addNode(firstId,firstparaDecl);
   if($3!=NULL){
       addSibling(firstparaDecl,$3);
   }
   //node *aux2=firstparaDecl;
    if(firstparaDecl != NULL) {

        addNode(firstparaDecl,funcPara);
        $$ = funcPara;

    }
    else {
        $$ = funcPara;
    }
   
   
   

};

/*cit -> COMMA ID Type (variavel auxiliar)*/
cit: /*empty*/ { $$ = NULL;}


    | COMMA ID Type cit {
        //parametro
          idToken * idaux = createID("",-1,-1);
        node * paraDecl = newNode("ParamDecl",idaux);
        //adiciona o tipo como filho do parametro
        
        addNode($3,paraDecl);
        //adiciona id como filho do parametro
        node * id = newNode("Id",$2);
        $$=addNode(id,paraDecl);

        
        if($3!=NULL){
            //parametros ficam irmaos
            addSibling(paraDecl, $4);
        }
        else{
            $$=id;

        }

    };




FuncBody: LBRACE VarsAndStatements RBRACE {
      idToken * idaux = createID("",-1,-1);
    node* funcBody = newNode("FuncBody", idaux);
    if($2!=NULL){
        addNode($2,funcBody);
    }
    $$=funcBody;
  
};

VarsAndStatements: /*empty*/ {$$ = NULL;}

    |VarsAndStatements vds SEMICOLON{
        if ($2 == NULL && $1 == NULL){
            $$ = NULL;
        }
		else if ($1 == NULL){ 
            $$ = $2;
            }
		else if ($2 == NULL){ 
            $$ = $1;
            }
		else{ 
            $$ = addSibling($1, $2);
            }
    };

/*vds -> VarDeclaration | Statement (variavel auxiliar)*/
vds: /*empty*/ {$$ = NULL;}

    |VarDeclaration {
      $$=$1;
      }

    |Statement {
        $$ = $1;
        }

Statement: ID ASSIGN Expr {
            idToken * idaux = createID("",-1,-1);
            node * assign = newNode("Assign", idaux);
            node * statementId = newNode("Id", $1);
            addNode(statementId, assign);
            if($3 != NULL) {addNode($3, assign);}
            $$ = assign;

        }

    |LBRACE ss RBRACE {

        if($2 != NULL && $2->sibling != NULL) { 
            idToken * idaux = createID("",-1,-1);
            node *block = newNode("Block", idaux);
            addNode($2, block);
            $$ = block;
        }
        else{$$= $2;}

    }

    |IF Expr LBRACE ss RBRACE elr {
          idToken * idaux = createID("",-1,-1);
        node * statementIf = newNode("If", idaux);
        
        if($2 != NULL){
            addNode($2, statementIf);
        }
          
        node * blockIfStart = newNode("Block", idaux);
        addNode(blockIfStart, statementIf);

        if($4 != NULL) {
            addNode($4, blockIfStart);
        }

        if($6 == NULL) {
              idToken * idaux = createID("",-1,-1);
            node * blockIfEnd = newNode("Block", idaux);
            addNode(blockIfEnd, statementIf);
        }
        else{
            addNode($6, statementIf);
        }
      
        $$ = statementIf;

    }

    |FOR exp LBRACE ss RBRACE {
          idToken * idaux = createID("",-1,-1);
        node * statementFor = newNode("For", idaux);
        
        node * blockFor = newNode("Block", idaux);
        addNode($2, statementFor);
        addNode(blockFor, statementFor);
        if($4 != NULL) {
            addNode($4, blockFor);
        }
        $$ = statementFor;

    }

    |RETURN exp {
          idToken * idaux = createID("",-1,-1);
        node * ret = newNode("Return", idaux);
        addNode($2, ret);
        $$ = ret;
        
    }

    |FuncInvocation { 

        $$ = $1;
    }

    |ParseArgs {

        $$ = $1;
    }

    |PRINT LPAR Expr RPAR {
          idToken * idaux = createID("",-1,-1);
        node * print = newNode("Print", idaux);
        addNode($3, print);
        $$ = print;

    }

    |PRINT LPAR STRLIT RPAR {
          idToken * idaux = createID("",-1,-1);
        node * print = newNode("Print",idaux);
          idToken * idaux2 = createID($3,-1,-1);
        node * strlit = newNode("StrLit", idaux2);
        addNode(strlit,print);
        $$ = print;

    }

    | error {$$ = NULL;}

/*ss -> Statement SEMICOLON (variavel auxiliar)*/
ss: /*empty*/ {$$ = NULL;}

    |Statement SEMICOLON ss {
        if ($1 == NULL && $3 == NULL) {
            $$ = NULL;
        }
			else if ($1 == NULL) {
                $$ = $3;
            }
			else if ($3 == NULL){ 
                $$ = $1;
            }
			else {
                $$ = addSibling($1, $3);
            }
                


    };


/*elr -> ELSE LBRACE {ss} RBRACE (variavel auxiliar)*/
elr: /*empty*/ {$$ = NULL;}

    |ELSE LBRACE ss RBRACE {
        idToken * idaux = createID("",-1,-1);
        node * blockElse = newNode("Block", idaux);
        if($3 != NULL) {addNode($3, blockElse);}
        $$ = blockElse;

    }


/*exp -> Expr (variavel auxiliar)*/
exp: /*empty*/ {$$ = NULL;}

    |Expr {$$=$1;}

  

ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR {
                idToken * idaux = createID("",-1,-1);
                node * parseArgs=newNode("ParseArgs",idaux);
                node * id=newNode("Id",$1);
                addNode(id,parseArgs);
                if($9!=NULL){
                    addNode($9,parseArgs);
                }
                $$=parseArgs;
            }

          |ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR{printTree=1;$$ = NULL;}


FuncInvocation: ID LPAR expcexp RPAR {
                      idToken * idaux = createID("",-1,-1);
                    node * call = newNode("Call",idaux);
                    node * id = newNode("Id",$1);
                    addNode(id,call);
                    if($3!=NULL){
                        addNode($3,call);
                    }
                    $$=call;

                    }
            


/*expcep -> Expr {COMMA Expr} (variavel auxiliar)*/

expcexp: /*empty*/ {$$ = NULL;}

    |Expr cexp {
        if ($1 == NULL && $2 == NULL){ 
            $$ = NULL;
            }
		else if($1==NULL){ 
            $$ = $2;
            }
		else if($2==NULL) {
            $$ = $1;
            }
		else{ $$ = addSibling($1, $2);
            }

    }

    |error{printTree=1;$$ = NULL;}

    

/*cexp -> COMMA Expr (variavel auxiliar)*/
cexp: /*empty*/ {$$ = NULL;}
     
    |COMMA Expr cexp {
        if ($2 == NULL && $3 == NULL) {
            $$ = NULL;
            }
        
		else if($2==NULL){ 
            $$ = $3;
            }

			else if($3==NULL){
                 $$ = $2;
                 }
			else {
                $$ = addSibling($2, $3);
                }

    };

Expr: Expr OR Expr {
      idToken * idaux = createID("",-1,-1);
        node * orr = newNode("Or",idaux);
        addNode($1,orr);
        addNode($3,orr);
        $$=orr;
    }

    |Expr AND Expr {
          idToken * idaux = createID("",-1,-1);
        node * andd = newNode("And",idaux);
        addNode($1,andd);
        addNode($3,andd);
        $$=andd;
    }

    |Expr LT Expr {
          idToken * idaux = createID("",-1,-1);
        node * lt = newNode("Lt",idaux);
        addNode($1,lt);
        addNode($3,lt);
        $$=lt;
    }

    |Expr GT Expr {
          idToken * idaux = createID("",-1,-1);
        node * gt = newNode("Gt",idaux);
        addNode($1,gt);
        addNode($3,gt);
        $$=gt;
    }

    |Expr EQ Expr {
          idToken * idaux = createID("",-1,-1);
        node * eq= newNode("Eq",idaux);
        addNode($1,eq);
        addNode($3,eq);
        $$=eq;
    }

    |Expr NE Expr {
          idToken * idaux = createID("",-1,-1);
        node * ne = newNode("Ne",idaux);
        addNode($1,ne);
        addNode($3,ne);
        $$=ne;
    }

    |Expr LE Expr {  
        idToken * idaux = createID("",-1,-1);
        node * le = newNode("Le",idaux);
        addNode($1,le);
        addNode($3,le);
        $$=le;
    }

    |Expr GE Expr {
          idToken * idaux = createID("",-1,-1);
        node * ge = newNode("Ge",idaux);
        addNode($1,ge);
        addNode($3,ge);
        $$=ge;
    }

    |Expr PLUS Expr {
          idToken * idaux = createID("",-1,-1);
        node * plus = newNode("Add",idaux);
        addNode($1,plus);
        addNode($3,plus);
        $$=plus;
    }

    |Expr MINUS Expr {
          idToken * idaux = createID("",-1,-1);
        node * sub= newNode("Sub",idaux);
        addNode($1,sub);
        addNode($3,sub);
        $$=sub;
    }
    

    |Expr STAR Expr {
          idToken * idaux = createID("",-1,-1);
        node * mult = newNode("Mul",idaux);
        addNode($1,mult);
        addNode($3,mult);
        $$=mult;
    }

    |Expr DIV Expr {
          idToken * idaux = createID("",-1,-1);
        node * div = newNode("Div",idaux);
        addNode($1,div);
        addNode($3,div);
        $$=div;}
    

    |Expr MOD Expr {
          idToken * idaux = createID("",-1,-1);
        node * mod = newNode("Mod",idaux);
        addNode($1,mod);
        addNode($3,mod);
        $$=mod;
    }

    |NOT Expr %prec UNARY {
          idToken * idaux = createID("",-1,-1);
        node * nott=newNode("Not",idaux);
        addNode($2,nott);
        $$=nott;

        }

    |MINUS Expr %prec UNARY{
          idToken * idaux = createID("",-1,-1);
        node * minus=newNode("Minus",idaux);
        addNode($2,minus);
        $$=minus;
    }

    |PLUS Expr %prec UNARY {
          idToken * idaux = createID("",-1,-1);
        node * pluss=newNode("Plus",idaux);
        addNode($2,pluss);
        $$=pluss;
    }

    |INTLIT {
          idToken * idaux = createID($1,-1,-1);
        $$=newNode("IntLit",idaux);
        }

    |REALLIT {
          idToken * idaux = createID($1,-1,-1);
        $$=newNode("RealLit",idaux);
        }

    |ID {
        $$=newNode("Id",$1);}

    |FuncInvocation {$$=$1;}

    |LPAR Expr RPAR {$$=$2;}

    |LPAR error RPAR{printTree=1;$$ = NULL; }


%%

int main(int argc, char **argv)
{
    if (argc > 1) {
        
        if (strcmp(argv[1], "-l") == 0) {
            flag = 1;
            yylex();
            return 0;
        }
        if(strcmp(argv[1],"-t") == 0 ){
            flag=2;
            yyparse();
            if(printTree==0){
                printAST(head,0);
            }
          
        }
         if(strcmp(argv[1],"-s") == 0 ){

            flag=2;
            yyparse();
             if(printTree==0){
            makeTables(head,0);
            printf("\n");
            annotateTree(head,0,"");
            printAST(head, 0);
            }
           

         }
        
    }
    else{
             flag=2;
           
             yyparse();
              if(printTree==0){
                makeTables(head,1);
                annotateTree(head,0,"");
                }
             
        }

    //deleteTree(head);
    
    yylex_destroy();
    return 0;
}

void yyerror(char *s) {
    printTree=1;
   
    
    if(errorBrace2==1){
      

        printf ("Line %d, column %d: %s: %s\n", errLine,errColumn, s, yytext);
        errorBrace2=0;
    }
    else{
       
        int trueColumn=column - yyleng;
        printf ("Line %d, column %d: %s: %s\n", line,trueColumn, s, yytext);
        }
        
    

}